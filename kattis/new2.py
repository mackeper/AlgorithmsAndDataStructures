#!/usr/bin/env python3
import os
import shutil
from collections import defaultdict
from dataclasses import dataclass
from io import BytesIO
from pathlib import Path
from typing import Callable, List
from zipfile import ZipFile

import requests
import typer
from typing_extensions import Annotated


@dataclass
class Sample:
    name: str
    input: str
    answer: str


@dataclass
class Language:
    name: str
    extension: str
    setup: List[Callable[str, None]]


app = typer.Typer(
    no_args_is_help=True, context_settings={"help_option_names": ["-h", "--help"]}
)


languages = [
    Language(
        "Python",
        "py",
        [
            lambda name, _: os.mkdir(name),
            lambda name, _: shutil.copy("main.py", f"{name}/main.py"),
        ],
    ),
    Language(
        "C++",
        "cpp",
        [
            lambda name, _: os.mkdir(name),
            lambda name, _: shutil.copy("main.cpp", f"{name}/main.cpp"),
            lambda name, _: shutil.copy("Makefile", f"{name}/Makefile"),
        ],
    ),
    # Language("C", "c", []),
    Language(
        "C#",
        "cs",
        [
            lambda name, _: os.system("dotnet new console -n " + name),
            lambda name, _: shutil.copy("Program.cs", f"{name}/Program.cs"),
            lambda name, _: cs_change_namespace(name, f"{name}/Program.cs"),
            lambda name, _: shutil.copy("Tests.cs", f"{name}/Tests.cs"),
            lambda name, _: cs_change_namespace(name, f"{name}/Tests.cs"),
            lambda name, _: shutil.copy("template.csproj", f"{name}/{name}.csproj"),
        ],
    ),
    # Language("Haskell", "hs", []),
    Language(
        "Rust",
        "rs",
        [
            lambda name, _: os.system(f"cargo new {name}"),
            lambda name, _: shutil.copy("main.rs", f"{name}/src/main.rs"),
            lambda name, samples: rust_append_tests(name, samples),
        ],
    ),
    # Language("Scala", "scala", []),
    Language(
        "Go",
        "go",
        [
            lambda name, _: os.mkdir(name),
            lambda name, _: shutil.copy("main.go", f"{name}/main.go"),
        ],
    ),
]


def cs_change_namespace(problem_name: str, file_path: str) -> None:
    with open(Path(file_path), "r") as file:
        data = file.read()
    data = data.replace("ConsoleApp", problem_name)
    with open(Path(file_path), "w") as file:
        file.write(data)


def rust_append_tests(problem_name: str, samples: List[Sample]) -> None:
    test_cases = """
#[cfg(test)]
mod tests {
   use super::*;

   fn within_epsilon(a: f64, b: f64) -> bool {
       (a - b).abs() < 1e-6
   }
"""
    for sample in samples:
        input = sample.input.replace("\n", "\\n").rstrip("\\n")
        answer = sample.answer.replace("\n", "\\n").rstrip("\\n")
        test_cases += "\n"
        test_cases += "    #[test]\n"
        test_cases += f"    fn test_{sample.name}() {{\n"
        test_cases += f'        let mut stdin = "{input}".as_bytes();\n'
        test_cases += "        let mut buffer = String:: with_capacity(1024);\n"
        test_cases += (
            f'        assert_eq!(solve( & mut stdin, & mut buffer), "{answer}");\n'
        )
        test_cases += "    }\n"

    test_cases += "}"
    with open(Path(problem_name) / Path("src/main.rs"), "a+", newline="") as file:
        file.write(test_cases)


def download_samples(problem_name: str) -> List[Sample]:
    sample_url = (
        f"https://open.kattis.com/problems/{problem_name}/file/statement/samples.zip"
    )
    response = requests.get(sample_url).content
    test_cases = defaultdict(dict)
    with ZipFile(BytesIO(response)) as zipfile:
        for i in zipfile.filelist:
            data = zipfile.read(i.filename).decode("utf-8")
            test_cases[i.filename.rsplit(".", 1)[0]][
                i.filename.rsplit(".", 1)[1]
            ] = data
    return [Sample(kvp[0], kvp[1]["in"], kvp[1]["ans"]) for kvp in test_cases.items()]


def write_samples_to_files(problem_name: str, samples: List[Sample]) -> None:
    for sample in samples:
        with open(Path(problem_name) / Path(sample.name + ".in"), "w+") as file:
            file.write(sample.input)
        with open(Path(problem_name) / Path(sample.name + ".ans"), "w+") as file:
            file.write(sample.answer)


def setup_problem(language: Language, problem_name: str) -> None:
    samples = download_samples(problem_name)
    for setup_function in language.setup:
        setup_function(problem_name, samples)
    write_samples_to_files(problem_name, samples)


@app.command()
def add_samples(
    problem_name: Annotated[str, typer.Argument(help="Name of the problem")]
) -> None:
    """Add samples to an existing problem"""
    if not os.path.exists(problem_name):
        print(f"Problem '{problem_name}' not found")
        return
    samples = download_samples(problem_name)
    write_samples_to_files(problem_name, samples)


@app.command()
def list_languages() -> None:
    """List all available languages"""
    for language in languages:
        print(f"{language.name} - {language.extension}")


@app.command()
def new(
    language: Annotated[str, typer.Argument(help="Name of the programming language")],
    problem_name: Annotated[str, typer.Argument(help="Name of the problem")],
) -> None:
    """Setup a new problem"""
    language = next(
        (
            x
            for x in languages
            if x.name.lower() == language.lower()
            or x.extension.lower() == language.lower()
        ),
        None,
    )

    if language is None:
        print(f"Language {language} not found")
        return

    setup_problem(language, problem_name)


@app.callback()
def main() -> None:
    """Kattis tool

    You find the problem name in the URL of the problem on open.kattis.com/problems/PROBLEM_NAME
    """
    pass


if __name__ == "__main__":
    # typer.run(main)
    app()

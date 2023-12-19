import os
import shutil
import sys
from collections import defaultdict
from dataclasses import dataclass
from io import BytesIO
from pathlib import Path
from typing import Callable, List
from zipfile import ZipFile

import requests


@dataclass
class Sample:
    name: str
    input: str
    answer: str


@dataclass
class Language:
    name: str
    extension: str
    # annotate as function
    setup: List[Callable[str, None]]


languages = [
    Language('Python', 'py', []),
    Language('C++', 'cpp', []),
    Language('C', 'c', []),
    Language('C#', 'cs', []),
    Language('Haskell', 'hs', []),
    Language(
        'Rust',
        'rs',
        [
            lambda x: os.system(f'cargo new {x}'),
            lambda x: shutil.copy('main.rs', f"{x}/src/main.rs"),
        ]
    ),
    Language('Scala', 'scala', []),
    Language('Go', 'go', []),
]


def download_samples(problem_name: str) -> List[Sample]:
    sample_url = f"https://open.kattis.com/problems/{problem_name}/file/statement/samples.zip"
    response = requests.get(sample_url).content
    test_cases = defaultdict(dict)
    with ZipFile(BytesIO(response)) as zipfile:
        for i in zipfile.filelist:
            data = zipfile.read(i.filename).decode("utf-8")
            test_cases[i.filename.rsplit('.', 1)[0]][i.filename.rsplit('.', 1)[1]] = data
    return [Sample(kvp[0], kvp[1]['in'], kvp[1]['ans']) for kvp in test_cases.items()]


def write_samples_to_files(problem_name: str, samples: List[Sample]) -> None:
    for sample in samples:
        with open(Path(problem_name) / Path(sample.name + '.in'), 'w+') as file:
            file.write(sample.input)
        with open(Path(problem_name) / Path(sample.name + '.ans'), 'w+') as file:
            file.write(sample.answer)


def setup_problem(language: Language, problem_name: str) -> None:
    [f(problem_name) for f in language.setup]
    samples = download_samples(problem_name)
    write_samples_to_files(problem_name, samples)


def main(args: List[str]) -> None:
    if len(args) != 3:
        print("Usage: new <language> <problem name>")
        return

    language = next((x for x in languages if x.name.lower() == args[1].lower()), None)
    if language is None:
        print(f"Language {args[1]} not found")
        return

    setup_problem(language, args[2])


if __name__ == '__main__':
    main(sys.argv)




































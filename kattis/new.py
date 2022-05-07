
from collections import defaultdict
from dataclasses import dataclass
from datetime import datetime
from email.policy import default
from io import BytesIO
from pathlib import Path
from typing import Dict, List
from zipfile import ZipFile
import requests
import os
import sys

@dataclass
class Sample:
    name: str
    input: str
    answer: str

def main_file_content(name:str) -> str:
    return f"""#{name}
from collections import *
from typing import *
import io, os, sys
_fast_readline = io.BytesIO(os.read(0, 2147483647)).readline
_readline = lambda: _fast_readline().decode()
read_line = lambda: _readline().strip()
read_list = lambda: _readline().strip().split(' ')
read_int = lambda: int(_readline())
read_int_list = lambda: [int(x) for x in read_list()]
write = lambda *msg: sys.stdout.write(' '.join(list(map(str, msg))))
writeln = lambda *msg: sys.stdout.write(' '.join(list(map(str, msg))) + '\\n')

def main() -> None:
    for line in sys.stdin:
        value = int(line)

if __name__ == '__main__':
    main()"""


def test_file_content(name:str, test_cases:str):
    return f"""from pathlib import Path
from subprocess import Popen, PIPE
import os
import unittest

class {name.capitalize()}Tests(unittest.TestCase):
    def _run_test_file(self, in_data: str) -> str:
        p = Popen(['python3', Path(os.path.dirname(os.path.abspath(__file__))) / Path('main.py')], stdout=PIPE, stdin=PIPE, stderr=PIPE)
        stdout, stderr = list(map(lambda x: x.decode().replace('\\r\\n', '\\n').strip(), p.communicate(input=in_data.encode())))
        if (stderr):
            print(stderr)
        return stdout
    {test_cases}
if __name__ == '__main__':
    unittest.main()"""

def write_file(filename:str, content:str) -> None:
    with open(filename, mode='w+', encoding='utf-8') as file:
        file.write(content)

def test_cases_content(samples: List[Sample]) -> str:
    test_cases_code = ""
    for sample in samples:
        test_cases_code += f"""
    def test_{sample.name}(self) -> None:
        in_data = '''\n{sample.input}'''.strip()
        ans_data = '''\n{sample.answer}'''.strip()
        result = self._run_test_file(in_data)
        self.assertEqual(ans_data, result, '\\nExpected:\\n' + ans_data + '\\n\\nActual:\\n' + result)"""
    return test_cases_code

def download_samples(problem_name:str) -> List[Sample]:
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


def setup_problem(problem_name: str) -> None:
    os.makedirs(problem_name, exist_ok=True)

    samples = download_samples(problem_name)
    write_samples_to_files(problem_name, samples)
    write_file(Path(problem_name) / Path('tests.py'), test_file_content(problem_name, test_cases_content(samples)))
    main_path = Path(problem_name) / Path('main.py')
    if not main_path.is_file():
        write_file(main_path, main_file_content(problem_name))

    print(problem_name)

def main(args: List[str]) -> None:
    for problem in args[1:]:
        setup_problem(problem)

if __name__ == '__main__':
    main(sys.argv)
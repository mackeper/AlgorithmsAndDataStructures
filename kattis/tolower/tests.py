from pathlib import Path
from subprocess import Popen, PIPE
import os
import unittest

class TolowerTests(unittest.TestCase):
    def _run_test_file(self, in_data: str) -> str:
        p = Popen(['python3', Path(os.path.dirname(os.path.abspath(__file__))) / Path('main.py')], stdout=PIPE, stdin=PIPE, stderr=PIPE)
        stdout, stderr = list(map(lambda x: x.decode().replace('\r\n', '\n').strip(), p.communicate(input=in_data.encode())))
        if (stderr):
            print(stderr)
        return stdout
    
    def test_tolower_01(self) -> None:
        in_data = '''
2 2
abc
Def
DDG
add
'''.strip()
        ans_data = '''
1
'''.strip()
        result = self._run_test_file(in_data)
        self.assertEqual(ans_data, result, '\nExpected:\n' + ans_data + '\n\nActual:\n' + result)

    def test_tolower_02(self) -> None:
        in_data = '''
2 3
abc
def
def
ddg
add
DAe
'''.strip()
        ans_data = '''
1
'''.strip()
        result = self._run_test_file(in_data)
        self.assertEqual(ans_data, result, '\nExpected:\n' + ans_data + '\n\nActual:\n' + result)

    def test_tolower_03(self) -> None:
        in_data = '''
2 1
a
B
'''.strip()
        ans_data = '''
2
'''.strip()
        result = self._run_test_file(in_data)
        self.assertEqual(ans_data, result, '\nExpected:\n' + ans_data + '\n\nActual:\n' + result)

if __name__ == '__main__':
    unittest.main()
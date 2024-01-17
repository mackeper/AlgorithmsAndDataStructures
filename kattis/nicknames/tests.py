from pathlib import Path
from subprocess import Popen, PIPE
import os
import unittest

class NicknamesTests(unittest.TestCase):
    def _run_test_file(self, in_data: str) -> str:
        p = Popen(['python3', Path(os.path.dirname(os.path.abspath(__file__))) / Path('main.py')], stdout=PIPE, stdin=PIPE, stderr=PIPE)
        stdout, stderr = list(map(lambda x: x.decode().replace('\r\n', '\n').strip(), p.communicate(input=in_data.encode())))
        if (stderr):
            print(stderr)
        return stdout
    
    def test_01(self) -> None:
        in_data = '''
3
j
jason
susan
3
j
s
x
'''.strip()
        ans_data = '''
2
1
0
'''.strip()
        result = self._run_test_file(in_data)
        self.assertEqual(ans_data, result, '\nExpected:\n' + ans_data + '\n\nActual:\n' + result)
    def test_02(self) -> None:
        in_data = '''
10
a
ba
cba
dcba
edcba
fedcba
gfedcba
hgfedcba
ihgfedcba
jihgfedcba
9
a
b
c
d
e
f
g
h
i
'''.strip()
        ans_data = '''
1
1
1
1
1
1
1
1
1
'''.strip()
        result = self._run_test_file(in_data)
        self.assertEqual(ans_data, result, '\nExpected:\n' + ans_data + '\n\nActual:\n' + result)
    def test_03(self) -> None:
        in_data = '''
4
string
substring
substrate
submarine
4
string
substr
sub
ring
'''.strip()
        ans_data = '''
1
2
3
0
'''.strip()
        result = self._run_test_file(in_data)
        self.assertEqual(ans_data, result, '\nExpected:\n' + ans_data + '\n\nActual:\n' + result)
if __name__ == '__main__':
    unittest.main()
from pathlib import Path
from subprocess import Popen, PIPE
import os
import unittest

class OddechoTests(unittest.TestCase):
    def _run_test_file(self, in_data: str) -> str:
        p = Popen(['python3', Path(os.path.dirname(os.path.abspath(__file__))) / Path('main.py')], stdout=PIPE, stdin=PIPE, stderr=PIPE)
        stdout, stderr = list(map(lambda x: x.decode().replace('\r\n', '\n').strip(), p.communicate(input=in_data.encode())))
        if (stderr):
            print(stderr)
        return stdout
    
    def test_1(self) -> None:
        in_data = '''
5
hello
i
am
an
echo
'''.strip()
        ans_data = '''
hello
am
echo
'''.strip()
        self.assertEqual(ans_data, self._run_test_file(in_data))

    def test_2(self) -> None:
        in_data = '''
10
only
if
these
oddindexed
words
appear
are
you
correct
output
'''.strip()
        ans_data = '''
only
these
words
are
correct
'''.strip()
        self.assertEqual(ans_data, self._run_test_file(in_data))

if __name__ == '__main__':
    unittest.main()
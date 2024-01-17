from pathlib import Path
from subprocess import Popen, PIPE
import os
import unittest

class BettingTests(unittest.TestCase):
    def _run_test_file(self, in_data: str) -> str:
        p = Popen(['python3', Path(os.path.dirname(os.path.abspath(__file__))) / Path('main.py')], stdout=PIPE, stdin=PIPE, stderr=PIPE)
        stdout, stderr = list(map(lambda x: x.decode().replace('\r\n', '\n').strip(), p.communicate(input=in_data.encode())))
        if (stderr):
            print(stderr)
        return stdout
    
    def test_1(self) -> None:
        in_data = '''
80
'''.strip()
        ans_data = '''
1.2500000000
5.0000000000
'''.strip()
        self.assertEqual(ans_data, self._run_test_file(in_data))

    def test_2(self) -> None:
        in_data = '''
15
'''.strip()
        ans_data = '''
6.6666666667
1.1764705882
'''.strip()
        self.assertEqual(ans_data, self._run_test_file(in_data))

if __name__ == '__main__':
    unittest.main()
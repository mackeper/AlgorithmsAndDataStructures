from pathlib import Path
from subprocess import Popen, PIPE
import os
import unittest

class TouchscreenkeyboardTests(unittest.TestCase):
    def _run_test_file(self, in_data: str) -> str:
        p = Popen(['python3', Path(os.path.dirname(os.path.abspath(__file__))) / Path('main.py')], stdout=PIPE, stdin=PIPE, stderr=PIPE)
        stdout, stderr = list(map(lambda x: x.decode().replace('\r\n', '\n').strip(), p.communicate(input=in_data.encode())))
        if (stderr):
            print(stderr)
        return stdout
    
    def test_sample(self) -> None:
        in_data = '''
2
ifpv 3
iopc
icpc
gcpc
edc 5
wsx
edc
rfv
plm
qed
'''.strip()
        ans_data = '''
icpc 3
gcpc 7
iopc 7
edc 0
rfv 3
wsx 3
qed 4
plm 17
'''.strip()
        result = self._run_test_file(in_data)
        self.assertEqual(ans_data, result, '\nExpected:\n' + ans_data + '\n\nActual:\n' + result)
if __name__ == '__main__':
    unittest.main()
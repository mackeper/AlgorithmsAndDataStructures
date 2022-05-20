#sortofsorting
from collections import *
from typing import *
import io, os, sys
# _fast_readline = io.BytesIO(os.read(0, 2147483647)).readline
_readline = lambda: sys.stdin.readline()
read_line = lambda: _readline().strip()
read_list = lambda: _readline().strip().split(' ')
read_int = lambda: int(_readline().strip())
read_int_list = lambda: [int(x) for x in read_list()]
write = lambda *msg, sep=' ': sys.stdout.write(sep.join(list(map(str, msg))))
writeln = lambda *msg, sep=' ': sys.stdout.write(sep.join(list(map(str, msg))) + '\n')

def solve_case(n):
    names = [read_line() for _ in range(n)]
    names.sort(key=lambda k: k[0:2])
    writeln(*names, sep='\n')
    writeln()

def main() -> None:
    while(True):
        n = read_int()
        if n == 0:
            break
        solve_case(n)

if __name__ == '__main__':
    main()
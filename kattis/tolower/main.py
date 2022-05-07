#tolower
from collections import *
from functools import reduce
from typing import *
import io, os, sys
# _fast_readline = io.BytesIO(os.read(0, 2147483647)).readline
# _readline = lambda: _fast_readline().decode()
_readline = lambda: sys.stdin.readline()
read_line = lambda: _readline().strip()
read_list = lambda: _readline().strip().split(' ')
read_int = lambda: int(read_line())
read_int_list = lambda: [int(x) for x in read_list()]
write = lambda *msg: sys.stdout.write(' '.join(list(map(str, msg))))
writeln = lambda *msg: sys.stdout.write(' '.join(list(map(str, msg))) + '\n')

def is_all_lower(word: str):
    return all(c == c.lower() for c in word[1:])

def is_problem_solvable(cases):
    return all(is_all_lower(line) for line in [read_line() for _ in range(cases)])

def main() -> None:
    problems, cases = read_int_list()
    writeln(reduce(lambda p, _: p + is_problem_solvable(cases), range(problems), 0))

if __name__ == '__main__':
    main()
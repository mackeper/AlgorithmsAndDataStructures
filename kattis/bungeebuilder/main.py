#bungeebuilder
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
writeln = lambda *msg: sys.stdout.write(' '.join(list(map(str, msg))) + '\n')

def 

def main() -> None:
    read_int()
    mountains = read_int_list()
    max_height = 0
    min_height = 2147483647
    for mountain_height in mountains:
        if mountain_height > min_height:


if __name__ == '__main__':
    main()
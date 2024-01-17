#nicknames by Marcus Östling (2022/04/17 09:31:16)
from collections import *
import io, os, sys
_fast_readline = io.BytesIO(os.read(0, 2147483647)).readline
_readline = lambda: _fast_readline().decode()
read_int = lambda: int(_readline())
read_line = lambda: _readline().strip()
write = lambda msg: sys.stdout.write(msg)
writeln = lambda msg: sys.stdout.write(msg+'\n')

def hash(s: str):
    res = 0
    for c in s:
        res = res * 100 + ord(c)
    return res

def main() -> None:
    prefixes = defaultdict(lambda: 0)
    for _ in range(0, read_int()):
        prefix = 0
        for char in read_line():
            prefix *= 100
            prefix += ord(char)
            prefixes[prefix] += 1

    for _ in range(0, read_int()):
        nickname = read_line()
        writeln(str(prefixes[hash(nickname)]))

if __name__ == '__main__':
    main()
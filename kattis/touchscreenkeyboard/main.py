#touchscreenkeyboard
from collections import *
from typing import *
import io, os, sys
_fast_readline = io.BytesIO(os.read(0, 2147483647)).readline
_readline = lambda: _fast_readline().decode()
read_line = lambda: _readline().strip()
read_list = lambda: _readline().strip().split(' ')
read_lines_list = lambda n_lines: [_readline().strip() for _ in range(0, n_lines)]
read_int = lambda: int(_readline())
read_int_list = lambda: [int(x) for x in read_list]
write = lambda *msg: sys.stdout.write(' '.join(list(map(str, msg))))
writeln = lambda *msg: sys.stdout.write(' '.join(list(map(str, msg))) + '\n')

class Graph:
    def __init__(self):
        self.graph = [list(word) for word in ["qwertyuiop", "asdfghjkl", "zxcvbnm"]]

        self.loc = {}
        for row in range(len(self.graph)):
            for col in range(len(self.graph[row])):
                self.loc[self.graph[row][col]] = (col, row)

    def dist(self, c1, c2):
        return abs(self.loc[c1][0] - self.loc[c2][0]) + abs(self.loc[c1][1] - self.loc[c2][1])

def solve_case(graph: Graph):
    word, n_words = read_list()
    words_dist = sorted([(sum([graph.dist(w[i], word[i]) for i in range(len(w))]), w) for w in read_lines_list(int(n_words))])
    for l, w in words_dist:
        writeln(w, l)

def main() -> None:
    cases = read_int()
    graph = Graph()
    for _ in range(cases):
        solve_case(graph)

if __name__ == '__main__':
    main()
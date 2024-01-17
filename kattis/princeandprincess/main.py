#princeandprincess
from collections import *
import io, os, sys
from typing import *

_fast_readline = io.BytesIO(os.read(0, 2147483647)).readline
_readline = lambda: _fast_readline().decode()
read_int = lambda: int(_readline().strip())
read_int_list = lambda: [int(x) for x in _readline().strip().split(' ')]
read_line = lambda: _readline().strip()
write = lambda *msg: sys.stdout.write(' '.join(list(map(str, msg))))
writeln = lambda *msg: sys.stdout.write(' '.join(list(map(str, msg))) + '\n')
stats = defaultdict(lambda: 0)

class Graph:
    def __init__(self, size: int, prince_path: Dict[int, int], princess_path: Dict[int, int]):
        self.size = size
        self.prince_path = prince_path
        self.princess_path = princess_path
        self.longest_path_from = {size: 1}

    def reachable(self, src: int, dist: int) -> bool:
        return\
            dist in self.prince_path and\
            dist in self.princess_path and\
            self.prince_path[src] < self.prince_path[dist] and\
            self.princess_path[src] < self.princess_path[dist]
        
def get_longest_path(graph: Graph, pos: int, length: int) -> int:
    if pos == graph.size: return length
    if pos in graph.longest_path_from: return graph.longest_path_from[pos]

    max_length = 0
    for dest in range(pos+1, graph.size+1):
        if graph.reachable(pos, dest):
            max_length = max(max_length, get_longest_path(graph, dest, length + 1))

    graph.longest_path_from[pos] = max_length
    return max_length

def lower_bound(arr: List, value:int, low: int = 0, high: int =-1):
    """Binary search for first value not less than value"""
    if high == -1: high = len(arr) - 1
    if high < low: return low
    mid = (high + low) // 2
    if arr[mid] == value: return mid
    elif arr[mid] < value: return lower_bound(arr, value, mid+1, high)
    else: return lower_bound(arr, value, low, mid-1)

def lower_boundw(arr, value, low = 0, high = -1):
    """Binary search for first value not less than value"""
    if high == -1: high = len(arr) - 1
    while low <= high:
        mid = (high + low) // 2
        if arr[mid] == value: return mid
        elif arr[mid] < value: low = mid + 1
        else: high = mid - 1
    return low


def longest_increasing_subsequence(graph: Graph):
    for dest in range(graph.size, 0, -1):
        print(dest)

def main() -> None:
    for case in range(read_int()):
        n, p, q = read_int_list()
        prince_path = {v: i for i,v in enumerate(read_int_list())}
        princess_path = {v: i for i,v in enumerate(read_int_list())}
        graph = Graph(n*n, prince_path, princess_path)
        # sys.stdout.write(f'Case {case+1}: {get_longest_path(graph, 1, 1)}\n')
        print(dict(stats))
        longest_increasing_subsequence(graph)
        print("lower_bound:", lower_bound([1,2,4,5,8], 3))
        print("lower_boundw:", lower_boundw([1,2,4,5,8], 3))

if __name__ == '__main__':
    main()
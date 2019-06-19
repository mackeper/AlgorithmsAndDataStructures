#! /usr/bin/python3

import sys
 
cnt = 0
nums = []

for line in sys.stdin:
    if(cnt != 0):
        [a, b] = map(int, line.split())
        nums.append((a, b))
    cnt += 1

def glads(n, k, mem):
    if mem[n][k] != -1:
        return mem[n][k]
    if k == 0 or (n == 1 and k != 1):
        return 0
    if k == 1:
        return 1
    
    mem[n][k] = k * glads(n-1, k, mem) + (2*n - k) * glads(n-1, k-1, mem)
    return mem[n][k]
  
for i in range(0, len(nums)):
    mem = [[-1 for i in range(0, 101)] for j in range(0, 101)]
    print(glads(nums[i][0], nums[i][1], mem))


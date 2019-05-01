#! /usr/bin/python3

import sys
 
cnt = 0
nums = []
max_num = 0

for line in sys.stdin:
    if(cnt != 0):
        num = int(line)
        nums.append(num)
        max_num = max(max_num, num)
    cnt += 1

def binomialCoefficient(n, k): 
    res = 1
    if k > (n - k): 
        k = n - k 
  
    for i in range(k): 
        res *= (n - i) 
        res //= (i + 1) 
    return res 
  
def catalan(n): 
    c = binomialCoefficient(2*n, n) 
    return c//(n + 1) 
  
for i in range(0, len(nums)):
    c = catalan(int(nums[i]//2))
    print(int(c)*2+1)


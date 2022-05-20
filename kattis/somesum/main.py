#somesum
import sys
n = int(sys.stdin.readline())
if n & 1 == 1: print("Either")
elif n & 2 != 2: print("Even")
else: print("Odd")
import sys
flag = sys.stdin.read()
print(flag)

for i in range(0, len(flag)):
    value = ord(flag[i])
    part1 = value >> 8
    part2 = value & 0xff
    print(chr(part1) + chr(part2), end='')

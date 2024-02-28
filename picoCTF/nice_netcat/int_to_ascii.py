import sys

data = sys.stdin.read()
data = data.split('\n')
for i in data:
    try:
        print(chr(int(i)), end='')
    except:
        pass

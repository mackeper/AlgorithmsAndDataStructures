flag = "112 105 99 111 67 84 70 123 98 52 100 95 98 114 111 103 114 97 109 109 101 114 95 57 99 49 49 56 98 98 102 125"
flag = flag.split(" ")
flag = [int(i) for i in flag]
flag = "".join([chr(i) for i in flag])
print(flag)

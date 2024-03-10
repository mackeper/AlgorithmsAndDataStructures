numbers = "16 9 3 15 3 20 6 { 20 8 5 14 21 13 2 5 18 19 13 1 19 15 14 }"
numbers = numbers.split()
flag = "".join([chr(int(num) + 96) if num.isdigit() else num for num in numbers])
print(flag)

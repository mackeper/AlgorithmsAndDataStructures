#oddecho by Marcus Östling (2022/04/17 07:15:35)
import sys

def main() -> None:
    counter = 0
    for line in sys.stdin:
        if counter & 1:
            print(line.strip())
        counter += 1

if __name__ == '__main__':
    main()
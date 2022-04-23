
import sys

def main() -> None:
    for line in sys.stdin:
        v = int(line)
        print(f'{(100-v)/v+1:.10f}')
        print(f'{v/(100-v)+1:.10f}')

if __name__ == '__main__':
    main()
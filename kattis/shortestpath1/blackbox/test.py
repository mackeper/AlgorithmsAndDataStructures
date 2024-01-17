import random
import subprocess

exes = [
    'shortestpath1.exe',
    'main.exe',
]


def test_exe():
    input = '1 0 1 0\n0\n0 0 0 0\n'
    for exe in exes:
        print('Testing {}'.format(exe))
        out = run_exe(exe, input)
        print(out)


def run_exe(exe, input):
    p = subprocess.run(exe, input=input.encode(), stdout=subprocess.PIPE)
    return p.stdout.decode()


def generate_input():
    n = random.randint(1, 10000)
    m = random.randint(0, 30000)
    q = random.randint(1, 100)

    n = random.randint(1, 10)
    m = random.randint(0, 10)
    q = random.randint(1, 1)

    s = random.randint(0, n-1)

    input = '{} {} {} {}\n'.format(n, m, q, s)

    for i in range(m):
        u = random.randint(0, n-1)
        v = random.randint(0, n-1)
        w = random.randint(0, 1000)
        input += '{} {} {}\n'.format(u, v, w)

    for i in range(q):
        t = random.randint(0, n-1)
        input += '{}\n'.format(t)

    input += '0 0 0 0\n'

    return input


def test():
    input = generate_input()
    results_exes = []
    results = []
    for exe in exes:
        print('Testing {}'.format(exe))
        out = run_exe(exe, input)
        # remove newlines and trailing whitespace
        out = out.replace('\n', '').rstrip()
        results_exes.append(exe)
        results.append(out)

    for i in range(len(results)-1):
        if results[i] != results[i+1]:
            print('Results differ')
            print('Input:')
            print(input)
            print(f'Output {results_exes[i]}:')
            print(results[i])
            print(f'Output {results_exes[i+1]}:')
            print(results[i+1])
            return False

    return True
    print('All OK')


def main():
    for i in range(100):
        print('Test {}'.format(i))
        if not test():
            break


if __name__ == '__main__':
    main()
    # test_exe()


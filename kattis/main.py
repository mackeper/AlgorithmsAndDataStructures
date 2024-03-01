#!/usr/bin/env python3
import sys
import io
import unittest


class test(unittest.TestCase):

    def test_1(self):
        with open("1.in", "r", encoding="utf-8") as stdin, open(
            "1.ans", "r", encoding="utf-8"
        ) as answer, io.StringIO() as stdout:
            solve(stdin, stdout)
            self.assertEqual(stdout.getvalue().strip(), answer.read().strip())

    def test_2(self):
        with open("2.in", "r", encoding="utf-8") as stdin, open(
            "2.ans", "r", encoding="utf-8"
        ) as answer, io.StringIO() as stdout:
            solve(stdin, stdout)
            self.assertEqual(stdout.getvalue().strip(), answer.read().strip())


def solve(stdin: io.TextIOWrapper, stdout: io.TextIOWrapper) -> None:
    word = stdin.readline().strip()
    repeat = int(stdin.readline().strip())
    stdout.write(word * repeat + "\n")


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "test":
        unittest.main()
    else:
        solve(sys.stdin, sys.stdout)

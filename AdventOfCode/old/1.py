import sys
import unittest

def run_integer_sum(input_string: str) -> str:
    groups = input_string.split("\n\n")
    print(groups)
    for g in groups:
        for l in g.split("\n"):
            print(l, int(l))
    max_sum = max((
        sum(int(line) for line in group.split("\n"))
        for group in groups
    ), key=int)
    return str(max_sum)

class TestIntegerSum(unittest.TestCase):
    def test_sum_of_highest_group(self):
        input_string = "1\n2\n3\n\n4\n5\n6\n"
        expected_output = "9"

        with self.subTest(input_string=input_string, expected_output=expected_output):
            self.assertEqual(run_integer_sum(input_string), expected_output)

        input_string = "1\n2\n3\n4\n\n5\n6\n7\n8\n"
        expected_output = "16"

        with self.subTest(input_string=input_string, expected_output=expected_output):
            self.assertEqual(run_integer_sum(input_string), expected_output)

        input_string = "1\n2\n3\n4\n5\n\n6\n7\n8\n9\n10\n"
        expected_output = "15"

        with self.subTest(input_string=input_string, expected_output=expected_output):
            self.assertEqual(run_integer_sum(input_string), expected_output)

    def test_large_values(self):
        input_string = "1000\n2000\n3000\n\n4000\n\n5000\n6000\n\n7000\n8000\n9000\n\n10000\n"
        expected_output = "24000"

        with self.subTest(input_string=input_string, expected_output=expected_output):
            self.assertEqual(run_integer_sum(input_string), expected_output)

if __name__ == "__main__":
    # unittest.main()
    input_string = ""
    for line in sys.stdin:
        input_string += line
    print(run_integer_sum(input_string))

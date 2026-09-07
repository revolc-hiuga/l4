import unittest
from src.main import split_str

class TestIsNumber(unittest.TestCase):
    def test_split_str(self):
        cases = [
            "0",
            "123",
            "123+123",
            "123+",
            "   123+   ",
            " 12 34 ",
            "+123+123+",
            "+-12 -  + 12",
            "123.456",
            "-123.456.789"
        ]

        accpet = [
            ["0"],
            ["123"],
            ["123", "+", "123"],
            ["123", "+"],
            ["123", "+"],
            ["12", "34"],
            ["+", "123", "+", "123", "+"],
            ["+", "-", "12", "-", "+", "12"],
            ["123.456"],
            ["-", "123.456.789"]
        ]

        for i in range(0, len(cases)):
            value = cases[i]
            accept_value = accpet[i]
            with self.subTest(value=value):
                self.assertEqual(split_str(value), accept_value)

if __name__ == "__main__":
    unittest.main()
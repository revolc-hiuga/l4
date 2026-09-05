import unittest
from src.main import is_number

class TestIsNumber(unittest.TestCase):
    def test_valid_numbers(self):
        cases = [
            "0",
            "1",
            "123"
            "123456",
            "123.456"
        ]

        for value in cases:
            with self.subTest(value=value):
                self.assertTrue(is_number(value))

    def test_invalid_numbers(self):
        cases = [
            "",
            "hello",
            "abc123",
            "123abc",
            "  123456  ",
            "123   456",
            ".123",
            "1.2.3",
            "123,456"
            "+123456"
            "-123456"
        ]

        for value in cases:
            with self.subTest(value=value):
                self.assertFalse(is_number(value))


if __name__ == "__main__":
    unittest.main()
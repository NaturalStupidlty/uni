import unittest
from typing import Union

from lab5.source.pohlig_hellman import pohlig_hellman


class TestPohligHellman(unittest.TestCase):
    def case(self, g: int, h: int, p: int, expected_result: Union[int, None]) -> None:
        result = pohlig_hellman(g, h, p)
        if expected_result is None:
            self.assertIsNone(result)
        else:
            self.assertEqual(expected_result, result)

    def test_pohlig_hellman_valid_input1(self):
        self.case(18, 2, 29, 11)

    def test_pohlig_hellman_valid_input2(self):
        self.case(27, 3, 31, 3)

    def test_pohlig_hellman_valid_input3(self):
        self.case(8, 2, 11, 3)

    def test_pohlig_hellman_valid_input4(self):
        self.case(525, -2, 131, 0)

    def test_pohlig_hellman_valid_input5(self):
        self.case(525, 2, 809, None)


if __name__ == '__main__':
    unittest.main()

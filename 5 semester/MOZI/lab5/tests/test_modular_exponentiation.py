import unittest
from lab5.source.modular_exponentiation import modular_exponentiation1, modular_exponentiation2


class TestModularExponentiation(unittest.TestCase):
    def case(self, algorithm: callable, number: int, degree: int, modulo: int, expected_result: int) -> None:
        result = algorithm(number, degree, modulo)
        self.assertEqual(expected_result, result)
        print(f"Test case passed: {number}^{degree} (mod {modulo}) = {expected_result}")

    def modular_exponentiation_test(self, algorithm: callable):
        # Case 1
        self.case(algorithm, 2, 3, 5, 3)
        # Case 2
        self.case(algorithm, 5, 0, 7, 1)
        # Case 3
        self.case(algorithm, 0, 10, 3, 0)
        # Case 4
        self.case(algorithm, 3, 123, 247, 183)
        # Case 5
        self.case(algorithm, 2, 1000, 1001, 562)

        print("All test cases passed!")

    def test_modular_exponentiation1(self):
        self.modular_exponentiation_test(modular_exponentiation1)

    def test_modular_exponentiation2(self):
        self.modular_exponentiation_test(modular_exponentiation2)


if __name__ == '__main__':
    unittest.main()

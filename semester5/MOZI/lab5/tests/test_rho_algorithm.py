import unittest

from lab5.source.rho_algorithm import rho_algorithm


class TestRhoAlgorithm(unittest.TestCase):
    def test_rho_algorithm(self):
        test_cases = [
            (3, None),  # Просте число
            (4, None),  # Складене число, але дільник = 2
            (15, 3),  # 3 - дільник 15
            (17, None),  # Просте число
            (561, 3),  # 3 - дільник числа Кармайкла 561
            (8051, 97),  # 31 - дільник числа 8051
            (104723, None)  # Просте число
        ]

        for number, expected_result in test_cases:
            with self.subTest(number=number):
                result = rho_algorithm(number)
                self.assertEqual(expected_result, result)

        print("All tests passed")


if __name__ == "__main__":
    unittest.main()

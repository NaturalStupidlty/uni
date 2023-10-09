import unittest

from lab5.source.pohlig_hellman import pohlig_hellman


class TestPohligHellman(unittest.TestCase):

    def test_pohlig_hellman_valid_input1(self):
        g = 18
        h = 2
        p = 29
        expected_result = 11
        result = pohlig_hellman(g, h, p)
        self.assertEqual(expected_result, result)

    def test_pohlig_hellman_valid_input2(self):
        g = 27
        h = 3
        p = 31
        expected_result = 3
        result = pohlig_hellman(g, h, p)
        self.assertEqual(expected_result, result)

    def test_pohlig_hellman_valid_input3(self):
        g = 8
        h = 2
        p = 11
        expected_result = 3
        result = pohlig_hellman(g, h, p)
        self.assertEqual(expected_result, result)

    def test_pohlig_hellman_valid_input4(self):
        g = 525
        h = -2
        p = 131
        expected_result = 0
        result = pohlig_hellman(g, h, p)
        self.assertEqual(expected_result, result)

    def test_pohlig_hellman_valid_input5(self):
        g = 525
        h = 2
        p = 809
        # No solution
        with self.assertRaises(TypeError):
            pohlig_hellman(g, h, p)


if __name__ == '__main__':
    unittest.main()

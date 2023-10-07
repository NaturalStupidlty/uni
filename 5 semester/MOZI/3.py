""" Implementation of an algorithm to compute the a^d (mod m) """


def _to_modulo(number: int, modulo: int) -> int:
    """ Converts a number to the corresponding number in the modulo """
    assert modulo > 0, "Modulo must be positive"

    return (modulo + number if number < 0 else number) % modulo


def modular_exponentiation(number: int, degree: int, modulo: int) -> int:
    """ Computes the a^d (mod m) """
    number = _to_modulo(number, modulo)
    degree = _to_modulo(degree, modulo)

    binary_degree = [int(bit) for bit in bin(degree)[2:]]

    result = 1
    for bit in binary_degree:
        result = (result * result) % modulo
        if bit == 1:
            result = (result * number) % modulo

    return result


def test_modular_exponentiation():
    # Test case 1: a = 2, d = 3, m = 5
    result = modular_exponentiation(2, 3, 5)
    assert result == 3, f"Expected 2^3 (mod 5) = 3, but got {result}"

    # Test case 2: a = 5, d = 0, m = 7
    result = modular_exponentiation(5, 0, 7)
    assert result == 1, f"Expected 5^0 (mod 7) = 1, but got {result}"

    # Test case 3: a = 0, d = 10, m = 3
    result = modular_exponentiation(0, 10, 3)
    assert result == 0, f"Expected 0^10 (mod 3) = 0, but got {result}"

    # Test case 4: a = 3, d = -2, m = 11
    result = modular_exponentiation(3, -2, 11)
    assert result == 4, f"Expected 3^(-2) (mod 11) = 4, but got {result}"

    # Test case 5: a = 3, d = 123, m = 247
    result = modular_exponentiation(3, 123, 247)
    assert result == 183, f"Expected 3^123 (mod 247) = 183, but got {result}"

    print("All test cases passed!")


if __name__ == "__main__":
    test_modular_exponentiation()

""" Implementation of an algorithm to compute the a^d (mod m) """


from utils import _to_modulo


def modular_exponentiation1(number: int, degree: int, modulo: int) -> int:
    """ Computes the a^d (mod m) """
    number = _to_modulo(number, modulo)
    degree = _to_modulo(degree, modulo)

    degree_binary = bin(degree)

    degree_binary = degree_binary[2:]
    result = 1
    s = number

    for i in reversed(degree_binary):
        if i == '1':
            result = (result*s) % modulo

        s = (s*s) % modulo

    return result


def modular_exponentiation2(number: int, degree: int, modulo: int) -> int:
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


def case(algorithm: callable, number: int, degree: int, modulo: int, expected_result: int) -> None:
    result = algorithm(number, degree, modulo)
    assert result == expected_result, f"Expected {number}^{degree} (mod {modulo}) = {expected_result}, but got {result}"
    print(f"Test case passed: {number}^{degree} (mod {modulo}) = {expected_result}")


def test_modular_exponentiation(algorithm: callable):
    case(algorithm, 2, 3, 5, 3)

    case(algorithm, 5, 0, 7, 1)

    case(algorithm, 0, 10, 3, 0)

    case(algorithm, 3, -2, 11, 4)

    case(algorithm, 3, 123, 247, 183)

    case(algorithm, 2, 1000, 1001, 562)

    print("All test cases passed!")


def test_modular_exponentiation1():
    test_modular_exponentiation(modular_exponentiation1)


def test_modular_exponentiation2():
    test_modular_exponentiation(modular_exponentiation2)


if __name__ == "__main__":
    test_modular_exponentiation2()

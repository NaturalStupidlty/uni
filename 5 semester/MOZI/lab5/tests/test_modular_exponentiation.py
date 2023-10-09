from lab5.source.modular_exponentiation import modular_exponentiation1, modular_exponentiation2


def case(algorithm: callable, number: int, degree: int, modulo: int, expected_result: int) -> None:
    result = algorithm(number, degree, modulo)
    assert result == expected_result, f"Expected {number}^{degree} (mod {modulo}) = {expected_result}, but got {result}"
    print(f"Test case passed: {number}^{degree} (mod {modulo}) = {expected_result}")


def modular_exponentiation_test(algorithm: callable):
    case(algorithm, 2, 3, 5, 3)

    case(algorithm, 5, 0, 7, 1)

    case(algorithm, 0, 10, 3, 0)

    case(algorithm, 3, 123, 247, 183)

    case(algorithm, 2, 1000, 1001, 562)

    print("All test cases passed!")


def test_modular_exponentiation1():
    modular_exponentiation_test(modular_exponentiation1)


def test_modular_exponentiation2():
    modular_exponentiation_test(modular_exponentiation2)


if __name__ == "__main__":
    test_modular_exponentiation2()
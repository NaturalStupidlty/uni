""" Implementation of an algorithm to compute the a^d (mod m) """


from .utils import _to_modulo


def modular_exponentiation1(number: int, degree: int, modulo: int) -> int:
    """ Computes the a^d (mod m) """
    number = _to_modulo(number, modulo)

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

    binary_degree = [int(bit) for bit in bin(degree)[2:]]

    result = 1
    for bit in binary_degree:
        result = (result * result) % modulo
        if bit == 1:
            result = (result * number) % modulo

    return result

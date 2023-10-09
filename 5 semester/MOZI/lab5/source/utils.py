def _to_modulo(number: int, modulo: int) -> int:
    """ Converts a number to the corresponding number in the modulo """
    assert modulo > 0, "Modulo must be positive"

    return (modulo + number if number < 0 else number) % modulo

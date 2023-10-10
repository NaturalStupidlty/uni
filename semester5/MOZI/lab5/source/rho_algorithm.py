def gcd(a, b):
    """Computes the greatest common divisor of a and b."""
    while b != 0:
        a, b = b, a % b
    return a


def rho_algorithm(number: int, max_iterations: int = 1000):
    """Computes a non-trivial factor of n using the Pollard-Rho algorithm."""
    assert number > 2, "number must be greater than 2"

    a = 2
    b = 2

    for _ in range(max_iterations):
        a = (a * a + 1) % number
        b = (b * b + 1) % number
        b = (b * b + 1) % number  # зробити це двічі, щоб отримати "2b"

        d = gcd(abs(a - b), number)

        if 1 < d < number:
            return d  # ми знайшли нетривіальний дільник

    return None  # нетривіальний дільник не знайдено

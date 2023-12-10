def is_prime(x: int):
    """
    Check if a given number is prime.

    Parameters:
        x (int): The number to check for primality.

    Returns:
        bool: True if x is prime, False otherwise.
    """
    if x < 2:
        return False
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True


def next_prime(n: int):
    """
    Find the next prime number after n.

    Parameters:
        n (int): The starting number.

    Returns:
        int: The next prime number after n.
    """
    n += 1 if n % 2 == 0 else 2
    while not is_prime(n):
        n += 2
    return n


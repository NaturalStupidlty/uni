import random


def is_prime(num):
    if num <= 1:
        return False
    if num <= 3:
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False
    i = 5
    while i * i <= num:
        if num % i == 0 or num % (i + 2) == 0:
            return False
        i += 6
    return True


def generate_prime(bits):
    while True:
        num = random.getrandbits(bits)
        # Ensure that the number is odd and greater than 1
        num |= 1
        num |= (1 << (bits - 1))
        if is_prime(num):
            return num


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def mod_inverse(a, m):
    m0, x0, x1 = m, 0, 1
    while a > 1:
        q = a // m
        m, a = a % m, m
        x0, x1 = x1 - q * x0, x0
    return x1 % m0


def encrypt(message, public_key):
    e, n = public_key
    encrypted = [pow(ord(char), e, n) for char in message]
    return encrypted


def decrypt(encrypted, private_key):
    d, n = private_key
    decrypted = [chr(pow(char, d, n)) for char in encrypted]
    return ''.join(decrypted)


if __name__ == '__main__':
    p = generate_prime(32)
    q = generate_prime(32)

    n = p * q
    phi = (p - 1) * (q - 1)

    # Find an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) == 1
    e = random.randint(2, phi - 1)
    while gcd(e, phi) != 1:
        e = random.randint(2, phi - 1)

    # Calculate the modular multiplicative inverse d of e (d * e mod phi(n) = 1)
    d = mod_inverse(e, phi)

    public_key = (e, n)
    private_key = (d, n)

    message = "rusni pizda"
    encrypted_message = encrypt(message, public_key)
    decrypted_message = decrypt(encrypted_message, private_key)

    print(f"Original message: {message}")
    print(f"Encrypted message: {encrypted_message}")
    print(f"Decrypted message: {decrypted_message}")

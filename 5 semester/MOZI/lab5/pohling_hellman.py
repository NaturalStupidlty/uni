# coding: utf-8
from math import sqrt, ceil


def prime_factorization(p):
    """Find all prime factors of the number p."""
    d, prime_factors = 2, []
    while d * d <= p:
        while (p % d) == 0:
            prime_factors.append(d)
            p //= d
        d += 1
    if p > 1:
        prime_factors.append(p)
    return prime_factors


def count_occurrences(prime_factors):
    """Count occurrences of each prime factor."""
    return [[x, prime_factors.count(x)] for x in set(prime_factors)]


def extended_gcd(a, b):
    """Extended Euclidean algorithm for finding GCD."""
    a2, a1 = 1, 0
    b2, b1 = 0, 1
    while b:
        q, r = divmod(a, b)
        a1, a2 = a2 - q * a1, a1
        b1, b2 = b2 - q * b1, b1
        a, b = b, r
    return a, a2, b2


def modular_inverse(b, n):
    """Return x s.t. x ≡ a^(-1) (mod n)."""
    g, x, _ = extended_gcd(b, n)
    if g == 1:
        return x % n


def chinese_remainder(pairs):
    """Chinese remainder theorem for solving a system of congruences."""
    N, X = pairs[0][1], 0
    for ni in pairs[1:]:
        N *= ni[1]
    for (ai, ni) in pairs:
        mi = N // ni  # Changed / to //
        X += mi * ai * extended_gcd(mi, ni)[1]
    return X % N


def shanks_algorithm(alpha, beta, n):
    """Return x s.t. beta ≡ alpha^(x) (mod n)."""
    m = int(ceil(sqrt(n - 1)))
    a = pow(alpha, m, n)
    b = extended_gcd(alpha, n)[1]
    L1 = [(j, pow(a, j, n)) for j in range(0, m)]
    L2 = [(i, beta * (b ** i) % n) for i in range(0, m)]
    L1.sort(key=lambda tup: tup[1])
    L2.sort(key=lambda tup: tup[1])
    i, j, Found = 0, 0, False
    while (not Found) and (i < m) and (j < m):
        if L1[j][1] == L2[i][1]:
            return m * L1[j][0] + L2[i][0] % n
        elif abs(L1[j][1]) > abs(L2[i][1]):
            i = i + 1
        else:
            j = j + 1


def congruence_pair(g, h, p, q, e, e1, e2):
    """Return pair (x, q ** e) which represents one congruence."""
    alpha_inverse = modular_inverse(e1, p)
    x = 0  # x = x_{0} + x_{1} * q + x_{2} * q^{2} + ... + x_{e - 1} * q^{e - 1}
    for i in range(1, e + 1):
        a = pow(e1, q ** (e - 1), p)
        b = pow(e2 * (alpha_inverse ** x), q ** (e - i), p)
        x += shanks_algorithm(a, b, p) * (q ** (i - 1))
    return x, q ** e


def print_formatted(arg1, arg2, arg3, arg4, arg5):
    print(" {:3s} | {:3s} | {:13s} | {:13s} | {:45s}".format(str(arg1), str(arg2), str(arg3), str(arg4), str(arg5)))
    print("-" * 90)


def pohling_hellman(g, h, p):
    """Main function of Pohling-Hellman's algorithm."""

    count_occurrences_list = count_occurrences(prime_factorization(p - 1))
    congruence_list = []

    print("\n")
    print("-" * 90)
    print(" Solving %d ≡ %d^x (mod %d)" % (g, h, p))
    print("-" * 90)
    print_formatted("q", "e", "g^((p-1)/q^e)", "h^((p-1)/q^e)", "Solve (g^((p-1)/q^e))^x = h^((p-1)/q^e) for x")

    for i in range(len(count_occurrences_list)):
        e1 = (h ** ((p - 1) // (count_occurrences_list[i][0] ** count_occurrences_list[i][1]))) % p  # Changed / to //
        e2 = (g ** ((p - 1) // (count_occurrences_list[i][0] ** count_occurrences_list[i][1]))) % p  # Changed / to //
        # Add new congruence
        congruence_list.append(
            congruence_pair(g, h, p, count_occurrences_list[i][0], count_occurrences_list[i][1], e1, e2))
        e3 = congruence_list[len(congruence_list) - 1][0] % congruence_list[len(congruence_list) - 1][
            1]  # Changed / to //
        e4 = congruence_list[len(congruence_list) - 1][1]  # Changed / to //
        print_formatted(count_occurrences_list[i][0], count_occurrences_list[i][1], e1, e2,
                       "x ≡ %2d (mod %2d)" % (e3, e4))

    # Solve the system of congruences
    try:
        solution = chinese_remainder(congruence_list)
    except TypeError:
        print(" The congruence %d ≡ %d^x (mod %d) has no solution " % (h, g, p))
        print("-" * 90)
        print("\n")
        return

    print(" Solution x = %d" % solution)
    print("-" * 90)
    print("\n")
    return solution

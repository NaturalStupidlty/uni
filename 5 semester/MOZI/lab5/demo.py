from modular_exponentiation import modular_exponentiation1, modular_exponentiation2
from pohling_hellman import pohling_hellman


def interactive_algorithm_demo() -> None:
    """ Interactive demo of the algorithm """
    menu_verbose = True
    print("Interactive demo of the algorithm")
    while True:
        if menu_verbose:
            print(
                "~~~~~~~~~~~~Menu~~~~~~~~~~~~"
                "0. Exit",
                "1. Modular exponentiation1",
                "2. Modular exponentiation2",
                "3. Ro-algorithm",
                "4. Pollard-Hemming algorithm",
            )
        menu_verbose = False
        algorithm_name = input("Enter the algorithm name: ")
        if algorithm_name == "0":
            break
        elif algorithm_name == "1":
            interactive_modular_exponentiation1_demo()
        elif algorithm_name == "2":
            interactive_modular_exponentiation2_demo()
        elif algorithm_name == "3":
            interactive_ro_algorithm_demo()
        elif algorithm_name == "4":
            interactive_pollard_hemming_algorithm_demo()
        else:
            print("Invalid algorithm name.")
            menu_verbose = True


def interactive_modular_exponentiation_demo(algorithm: callable):
    print("This algorithm computes the a^d (mod m)")
    print("Enter values for a, d, m")
    a = int(input("a = "))
    d = int(input("d = "))
    m = int(input("m = "))

    result = algorithm(a, d, m)
    print(f"{a}^{d} (mod {m}) = {result}")


def interactive_modular_exponentiation1_demo():
    interactive_modular_exponentiation_demo(modular_exponentiation1)


def interactive_modular_exponentiation2_demo():
    interactive_modular_exponentiation_demo(modular_exponentiation2)


def interactive_ro_algorithm_demo():
    pass


def interactive_pollard_hemming_algorithm_demo():
    pass


def pohling_hellman_demo():
    print("=" * 90)
    print("Pohling-Hellman's algorithm for discrete logarithm")
    print("Formula: h ≡ g^x (mod p)")
    print("=" * 90)
    print("\n")

    while True:
        err = False
        h = int(input("h: "))
        g = int(input("g: "))
        p = int(input("p: "))

        if p < 2:
            print("Group order must be greater than one.\n")
            err = True

        if not err:
            try:
                pohling_hellman(h, g, p)
            except TypeError:
                print(" The congruence %d ≡ %d^x (mod %d) has no solution " % (h, g, p))
                print("-" * 90)
                print("\n")


if __name__ == "__main__":
    interactive_algorithm_demo()

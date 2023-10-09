from source.modular_exponentiation import modular_exponentiation1, modular_exponentiation2
from source.pohlig_hellman import pohlig_hellman
from source.po_algorithm import po_algorithm


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
                "4. Pohlig-Hellman algorithm",
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
            interactive_pohling_hellman_demo()
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


def interactive_po_algorithm_demo():
    print("Pollard's Rho Algorithm Demo")
    while True:
        try:
            n = int(input("Enter an integer greater than 2 (or enter 0 to quit): "))

            if n == 0:
                print("Exiting the program.")
                break

            if n <= 2:
                print("Please enter a number greater than 2.")
                continue

            result = po_algorithm(n)

            if result:
                print(f"A non-trivial divisor of {n} is {result}")
            else:
                print(f"No non-trivial divisor found for {n}")
        except ValueError:
            print("Invalid input. Please enter an integer.")


def interactive_pohling_hellman_demo():
    print("=" * 90)
    print("Pohling-Hellman's algorithm for discrete logarithm")
    print("Formula: h ≡ g^x (mod p)")
    print("=" * 90)
    print("\n")

    err = False
    h = int(input("h: "))
    g = int(input("g: "))
    p = int(input("p: "))

    if p < 2:
        print("Group order must be greater than one.\n")
        err = True

    if not err:
        try:
            pohlig_hellman(h, g, p)
        except TypeError:
            print(" The congruence %d ≡ %d^x (mod %d) has no solution " % (h, g, p))
            print("-" * 90)
            print("\n")


if __name__ == "__main__":
    interactive_algorithm_demo()

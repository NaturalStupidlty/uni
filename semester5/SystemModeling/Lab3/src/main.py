import sympy
from io_reader import read
from approximation import calculate


def run_approximation(path_to_data: str = '../txt/y8.txt', epsilon: float = 1e-16):
    mtx_input = read(path_to_data)

    c1, c2, c3, c4, m1, m2, m3 = sympy.symbols('c1 c2 c3 c4 m1 m2 m3')
    beta_init_real = {c1: 0.1, c2: 0.1, c3: 0.4}
    approximated = calculate(mtx_input,
                             {m1: 12, m2: 28, m3: 18, c4: 0.12},
                             [c1, c2, c3],
                             beta_init_real,
                             epsilon)
    print("Approximation:", approximated)


if __name__ == "__main__":
    run_approximation()

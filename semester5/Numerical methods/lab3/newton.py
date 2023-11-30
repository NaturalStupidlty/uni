import sympy as sp
import numpy as np
import val as v


def divided_difference(p1, p2, x1, x2):
    return (p2 - p1) / (x2 - x1)


def calculate_table(vals):
    curr = []
    args = []
    n = len(vals)
    table = np.zeros((n, n))
    for i in range(n):
        v = vals[i]
        args.append(v.argument())
        curr.append(v.function())
        table[i][0] = v.function()
    for i in range(1, len(vals)):
        next_c = []
        for j in range(0, len(curr) - 1):
            dd = divided_difference(curr[j], curr[j + 1], args[j], args[j + i])
            next_c.append(dd)
            table[j][i] = dd
        curr = next_c
    return table


def newton_interpolation(vals):
    x = sp.symbols('x')
    table = calculate_table(vals)
    prod = 1
    polynomial = 0
    n = len(vals)
    for i in range(0, n):
        polynomial = polynomial + prod * table[0][i]
        prod = prod * (x - vals[i].argument())
    return polynomial


def test():
    v1 = v.Val([-1, 1 / 3])
    v2 = v.Val([0, 1])
    v3 = v.Val([1, 3])

    p = newton_interpolation([v1, v2, v3])
    print(p)


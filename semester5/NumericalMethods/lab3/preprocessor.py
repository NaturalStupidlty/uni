import numpy as np
import val as v
import sympy as sp


def nth_derivative_at_x0(expr_str, n, x0):
    x = sp.symbols('x')
    expr = sp.sympify(expr_str)
    nth_derivative = sp.diff(expr, x, n)
    return nth_derivative.subs(x, x0)


def optimal_values(function, a, b, n, rank=0):
    if a > b:
        raise ValueError("Illegal range!")
    vals_arr = [to_add(function, a, rank)]
    ab_sum = (a + b) / 2
    ab_diff = (b - a) / 2
    m = n - 2
    for i in range(m):
        x = ab_sum + ab_diff * np.cos((2 * i + 1) * np.pi / (2 * (m + 1)))
        vals_arr.append(to_add(function, x, rank))
    vals_arr.append(to_add(function, b, rank))
    sorted_val_array = sorted(vals_arr, key=lambda val: val.argument())
    return sorted_val_array


def even_values(function, a, b, n, rank=0):
    if a > b:
        raise ValueError("Illegal range!")
    vals_arr = []
    if n == 1:
        x = (a + b) / 2
        vals_arr.append(to_add(function, x, rank))
        return vals_arr
    step = (b - a) / (n - 1)
    curr = a
    for i in range(n):
        x = curr
        curr += step
        vals_arr.append(to_add(function, x, rank))
    return vals_arr


def to_add(function, x, rank):
    f = v.at(function, x)
    arr = [x, f]
    for j in range(rank):
        arr.append(nth_derivative_at_x0(function, x, j))
    return v.Val(arr)

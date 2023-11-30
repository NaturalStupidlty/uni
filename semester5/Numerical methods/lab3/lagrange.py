import val as v
import sympy as sp


def v_product_except(v_prod, x, val):
    return v_prod / (x - val.argument())


def lagrange_interpolation(vals):
    x = sp.symbols('x')
    v_prod = v_product(vals, x)
    polynomial = 0
    for val in vals:
        v_prod_curr = v_product_except(v_prod, x, val)
        polynomial = polynomial + (v_prod_curr * val.function()) / (v.at(v_prod_curr, val.argument()))
    return polynomial


def v_product(vals, x):
    if not vals:
        return 1
    else:
        expression = 1
        for val in vals:
            expression *= (x - val.argument())
        return expression


def derivative_v_product(expression, x):
    return sp.diff(expression, x)


def test():
    v1 = v.Val([-1, 1 / 3])
    v2 = v.Val([0, 1])
    v3 = v.Val([1, 3])

    p = lagrange_interpolation([v1, v2, v3])
    print(p)


if __name__ == '__main__':
    test()
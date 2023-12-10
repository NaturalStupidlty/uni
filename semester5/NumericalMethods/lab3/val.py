import sympy as sp


class Val:
    def __init__(self, vals):
        self.vals = vals

    def argument(self):
        return self.vals[0]

    def function(self):
        return self.vals[1]

    def derivative(self, rank=1):
        return self.vals[1 + rank]


def at(expression, x_value):
    x = sp.symbols('x')
    x_map_t = {x: x_value}
    return expression.subs(x_map_t)


def simplify(expr):
    return sp.simplify(expr)

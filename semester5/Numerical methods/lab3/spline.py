import sympy as sp
import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d


def diagonal_element(vals, i):
    return (get_h(vals, i) + get_h(vals, i + 1)) / 3


def semi_diagonal_element(vals, i):
    return (get_h(vals, i)) / 6


def define_a(vals):
    m = len(vals) - 2
    a_matrix = np.zeros((m, m))
    for i in range(m):
        if i > 0:
            a_matrix[i][i - 1] = semi_diagonal_element(vals, i + 1)
        a_matrix[i][i] = diagonal_element(vals, i + 1)
        if i < m - 1:
            a_matrix[i][i + 1] = semi_diagonal_element(vals, i + 2)
    return a_matrix


def define_f(vals):
    f = []
    for v in vals:
        f.append(v.function())
    return f


def get_h(vals, i):
    return vals[i].argument() - vals[i - 1].argument()


def define_h(vals):
    m = len(vals) - 2
    h_matrix = np.zeros((m, m + 2))
    for i in range(m):
        h_matrix[i][i] = 1 / get_h(vals, i + 1)
        h_matrix[i][i + 1] = -1 / get_h(vals, i + 1) - 1 / get_h(vals, i + 2)
        h_matrix[i][i + 2] = 1 / get_h(vals, i + 2)
    return h_matrix


def solve(a_matrix, b_vector):
    return np.linalg.solve(a_matrix, b_vector)


def define_x(vals):
    x = []
    for v in vals:
        x.append(v.argument())
    return x


def nth_derivative_at_x0(expr_str, n, x0):
    x = sp.symbols('x')
    expr = sp.sympify(expr_str)
    nth_derivative = sp.diff(expr, x, n)
    return nth_derivative.subs(x, x0)


def to_full_vector(m_v):
    full_v = [0]
    for m in m_v:
        full_v.append(m)
    full_v.append(0)
    return full_v


def spline_interpolation(vals):
    if len(vals) < 2:
        print("Not enough points for spline interpolation!")
        return {}
    x = sp.symbols('x')
    a_matrix = define_a(vals)
    h_matrix = define_h(vals)
    f_vector = define_f(vals)
    x_vector = define_x(vals)
    b_vector = h_matrix.dot(f_vector).astype(np.float64)
    m_vector = solve(a_matrix, b_vector)
    splines = {}
    m_full = to_full_vector(m_vector)
    for i in range(1, len(m_full)):
        h = get_h(vals, i)
        s = (m_full[i - 1] * (x_vector[i] - x) ** 3 / (6 * h) +
             + m_full[i] * (x - x_vector[i - 1]) ** 3 / (6 * h) +
             + (f_vector[i - 1] - m_full[i - 1] * h ** 2 / 6) * (x_vector[i] - x) / h +
             + (f_vector[i] - m_full[i] * h ** 2 / 6) * (x - x_vector[i - 1]) / h)
        splines[(x_vector[i - 1], x_vector[i])] = s
    return splines


def linear_spline(function: callable, start: int = -5, end: int = 5, step: float = 0.5):
    x_values = np.arange(start, end + step, step)

    # Calculate function values for the x values
    y_values = function(x_values)

    # Perform linear spline interpolation
    linear_interp = interp1d(x_values, y_values, kind='linear')

    # Generate x values for interpolation result with smaller step size
    interpolation_step = 0.01
    x_interp = np.arange(start, end + interpolation_step, interpolation_step)

    # Calculate interpolated y values
    y_interp = linear_interp(x_interp)

    # Plot the interpolated function
    plt.plot(x_interp, y_interp, label='Interpolated Function', linestyle='--')

    # Plot the interpolated points
    plt.scatter(x_values, y_values, color='red', label='Interpolated Points')


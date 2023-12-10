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

def quadratic_coefficients(x0, y0, x1, y1, x2, y2):
    # Coefficients for quadratic equation: y = ax^2 + bx + c
    a = ((y2 - y0) / ((x2 - x0) * (x2 - x1))) - ((y1 - y0) / ((x1 - x0) * (x2 - x1)))
    b = ((y1 - y0) / (x1 - x0)) - a * (x0 + x1)
    c = y0 - (a * x0 ** 2) - (b * x0)
    return a, b, c

def spline_interpolation(vals):
    if len(vals) < 3:
        print("Not enough points for quadratic interpolation!")
        return {}

    # Sort the values based on x-coordinates
    vals.sort(key=lambda p: p.vals[0])  # Sort based on x-values
    x_values = np.array([p.vals[0] for p in vals])
    y_values = np.array([p.vals[1] for p in vals])

    quadratics = {}
    for i in range(len(vals) - 2):
        x0, y0 = x_values[i], y_values[i]
        x1, y1 = x_values[i + 1], y_values[i + 1]
        x2, y2 = x_values[i + 2], y_values[i + 2]

        a, b, c = quadratic_coefficients(x0, y0, x1, y1, x2, y2)

        # Store the quadratic function coefficients for this interval
        quadratics[(x0, x2)] = (a, b, c)

    return quadratics

def linear_spline(function: callable, start: int = -5, end: int = 5, step: float = 0.5):
    x_values = np.arange(start, end + step, step)

    # Calculate function values for the x values
    y_values = function(x_values)

    # Perform linear spline interpolation
    linear_interp = interp1d(x_values, y_values, kind='linear')

    def find_line_coefficients(x_values, y_values):
        lines = []  # To store the coefficients of each line

        # Ensure the lists x_values and y_values have the same length
        if len(x_values) != len(y_values):
            raise ValueError("The lists of x and y values must have the same length")

        # Calculate coefficients for each pair of points
        for i in range(len(x_values) - 1):
            x1, y1 = x_values[i], y_values[i]
            x2, y2 = x_values[i + 1], y_values[i + 1]

            # Calculate the coefficients 'a' and 'b' for the line equation
            a = (y2 - y1) / (x2 - x1)
            b = y1 - a * x1

            lines.append((a, b))  # Append coefficients of the line

        return lines

    lines = find_line_coefficients(linear_interp.x, linear_interp.y)

    # Display the equations of the lines
    for i, line in enumerate(lines):
        print("Point: {linear_interp.x[i], linear_interp.y[i]}")
        a, b = line
        print(f"Line {i + 1}: y = {a}x + {b}")

    # Generate x values for interpolation result with smaller step size
    interpolation_step = 0.01
    x_interp = np.arange(start, end + interpolation_step, interpolation_step)

    # Calculate interpolated y values
    y_interp = linear_interp(x_interp)

    # Plot the interpolated function
    plt.plot(x_interp, y_interp, label='Interpolated Function', linestyle='--')

    # Plot the interpolated points
    plt.scatter(x_values, y_values, color='red', label='Interpolated Points')


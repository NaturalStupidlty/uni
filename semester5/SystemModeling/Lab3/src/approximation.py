import sympy as sp
import numpy as np


def create_matrix_and_symbols():
    c1, c2, c3, c4, m1, m2, m3 = sp.symbols('c1 c2 c3 c4 m1 m2 m3')
    matrix_a = [
        [0, 1, 0, 0, 0, 0],
        [-(c2 + c1) / m1, 0, c2 / m1, 0, 0, 0],
        [0, 0, 0, 1, 0, 0],
        [c2 / m2, 0, -(c2 + c3) / m2, 0, c3 / m2, 0],
        [0, 0, 0, 0, 0, 1],
        [0, 0, c3 / m3, 0, -(c4 + c3) / m3, 0]
    ]
    return sp.Matrix(matrix_a)


def print_matrix(matrix, name='Matrix'):
    print(f"\n{name}\n")
    num_rows, num_cols = matrix.shape
    max_widths = [max(len(str(matrix[i, j])) for i in range(num_rows)) for j in range(num_cols)]
    for i in range(num_rows):
        row_str = ""
        for j in range(num_cols):
            element = str(matrix[i, j])
            padding = max_widths[j] - len(element)
            row_str += element + ' ' * (padding + 1) + "\t\t"
        print(row_str)


def derivative_of_vector(y_vector, b_vector):
    derivatives = [sp.diff(Yi, Bi) for Yi in y_vector for Bi in b_vector]
    num_cols = len(b_vector)
    derivative_matrix = [derivatives[i:i + num_cols] for i in range(0, len(derivatives), num_cols)]
    return sp.Matrix(derivative_matrix)


def to_y_map(y_matrix, i):
    y1, y2, y3, y4, y5, y6 = sp.symbols('y1 y2 y3 y4 y5 y6')
    return {
        y1: y_matrix[i][0],
        y2: y_matrix[i][1],
        y3: y_matrix[i][2],
        y4: y_matrix[i][3],
        y5: y_matrix[i][4],
        y6: y_matrix[i][5]
    }


def to_np_matrix(mtx):
    return np.array(mtx.tolist())


def to_y_map_simple(y_v):
    y1, y2, y3, y4, y5, y6 = sp.symbols('y1 y2 y3 y4 y5 y6')
    return {
        y1: y_v[0],
        y2: y_v[1],
        y3: y_v[2],
        y4: y_v[3],
        y5: y_v[4],
        y6: y_v[5]
    }


# 6 x 3
def calculate_f(u_matrix, a_filled, b_filled, h=0.2):
    return h * (np.dot(a_filled, u_matrix) + b_filled)


def calculate_u(a_filled, b_matrix, u_curr):
    b_filled = to_np_matrix(b_matrix)
    k1 = calculate_f(u_curr, a_filled, b_filled)
    k2 = calculate_f(u_curr + k1 / 2, a_filled, b_filled)
    k3 = calculate_f(u_curr + k2 / 2, a_filled, b_filled)
    k4 = calculate_f(u_curr + k3, a_filled, b_filled)
    return u_curr + (k1 + 2 * k2 + 2 * k3 + k4) / 6


def calculate_f_y(y_current, a_filled, h=0.2):
    return h * (np.dot(a_filled, y_current))


def calculate_y(a_filled, y_current):
    k1 = calculate_f_y(y_current, a_filled)
    k2 = calculate_f_y(y_current + k1 / 2, a_filled)
    k3 = calculate_f_y(y_current + k2 / 2, a_filled)
    k4 = calculate_f_y(y_current + k3, a_filled)
    return y_current + (k1 + 2 * k2 + 2 * k3 + k4) / 6


def y_one(y_matrix):
    return y_matrix[0]


def to_beta_vector(beta_init):
    c1, c2, c3 = sp.symbols('c1 c2 c3')
    return np.array([beta_init[c1], beta_init[c2], beta_init[c3]])


def update_beta_init(beta_vector):
    c1, c2, c3 = sp.symbols('c1 c2 c3')
    return {
        c1: beta_vector[0],
        c2: beta_vector[1],
        c3: beta_vector[2]
    }


# 0.14 0.3 0.2

def calculate(y_matrix, params, beta, beta_init, eps):
    a_matrix = create_matrix_and_symbols()
    a_filled = a_matrix.subs(params)
    print_matrix(a_filled, 'Matrix A')
    beta_vector = to_beta_vector(beta_init)
    while True:
        a_extra_filled = to_np_matrix(a_filled.subs(beta_init))
        u_matrix = np.zeros((6, 3))
        to_inv_integral = np.zeros((3, 3))
        to_mult_integral = np.zeros((1, 3))
        distance_integral = 0
        y_approx = y_one(y_matrix)
        for i in range(len(y_matrix)):
            ay_prod = a_filled * sp.Matrix(y_approx)
            b_matrix = derivative_of_vector(ay_prod, beta)

            prod = np.dot(u_matrix.T, u_matrix)
            to_inv_integral = (to_inv_integral + prod).astype('float64')

            mult_prod = np.dot(u_matrix.T, y_matrix[i] - y_approx)
            to_mult_integral = (to_mult_integral + mult_prod).astype('float64')

            distance = np.dot(y_matrix[i] - y_approx, y_matrix[i] - y_approx)
            distance_integral = distance_integral + distance

            u_matrix = calculate_u(a_extra_filled, b_matrix, u_matrix)
            y_approx = calculate_y(a_extra_filled, y_approx)
        to_inv_integral = to_inv_integral * 0.2
        to_mult_integral = to_mult_integral * 0.2
        distance_integral = distance_integral * 0.2
        vv = to_mult_integral.flatten()
        delta_beta = np.dot(np.linalg.pinv(to_inv_integral), vv)
        beta_vector = beta_vector + delta_beta
        beta_init = update_beta_init(beta_vector)
        print("Beta", beta_vector)
        print("Distance", distance_integral)
        if distance_integral < eps:
            return beta_init

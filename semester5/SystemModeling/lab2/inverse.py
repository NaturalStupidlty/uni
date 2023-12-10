import numpy as np


def calculate_first(a0):
    dt = multiply(a0.T, a0)
    if dt == 0:
        return np.vstack(a0)
    return np.vstack(a0 / dt)


def calculate_z(a_cur, a_inv):
    e = np.identity(a_cur.shape[1])
    prod = multiply(a_inv, a_cur)
    return e - prod


def multiply(*args):
    if len(args) == 0:
        return 0
    if len(args) == 1:
        return args[0]

    result = np.dot(args[0], args[1])
    for i in range(2, len(args)):
        result = np.dot(result, args[i])
    return result


def add_row(matrix, a):
    return np.vstack([matrix, a])


def add_col(matrix, a):
    return np.hstack((matrix, np.vstack(a)))


def append_to_inverse(inverse_matrix, a, z, denum):
    inverse_new = inverse_matrix - multiply(z, a, a.T, inverse_matrix) / denum
    row = multiply(z, a) / denum
    return add_col(inverse_new, row)


def append_zero_case(inverse_matrix, a, z):
    r = multiply(inverse_matrix, inverse_matrix.T)
    denum = 1 + multiply(a.T, r, a)
    inverse_new = inverse_matrix - multiply(z, a, a.T, inverse_matrix) / denum
    row = multiply(r, a) / denum
    return add_col(inverse_new, row)


def greville(matrix):
    eps = 0.001
    inverse_matrix = calculate_first(matrix[0])
    current_matrix = np.array([matrix[0]])
    n = matrix.shape[0]
    for i in range(1, n):
        a = matrix[i].reshape(-1, 1)
        z = calculate_z(current_matrix, inverse_matrix)
        current_matrix = add_row(current_matrix, matrix[i])

        denum = multiply(a.T, z, a)[0, 0]
        if np.abs(denum) < eps:
            inverse_matrix = append_zero_case(inverse_matrix, a, z)
        else:
            inverse_matrix = append_to_inverse(inverse_matrix, a, z, denum)

    return inverse_matrix


def check_distance(m1, m2):
    distance = np.sqrt(np.sum((m1 - m2) ** 2))
    return distance < 1e-6


def moore(a):
    delta = 10
    m = a.shape[0]
    n = a.shape[1]
    print("Epsilon: 1e-6")
    curr = np.zeros([n, m])
    i = 0
    if m < n:
        while True:
            prev = curr.copy()
            i += 1
            curr = multiply(a.T, np.linalg.inv(multiply(a, a.T) + delta * np.identity(m)))
            if check_distance(prev, curr):
                break
            delta /= 2
    else:
        while True:
            prev = curr.copy()
            i += 1
            curr = multiply(np.linalg.inv(multiply(a.T, a) + delta * np.identity(n)), a.T)
            if check_distance(prev, curr):
                break
            delta /= 2
    print("Steps:", i)
    return curr

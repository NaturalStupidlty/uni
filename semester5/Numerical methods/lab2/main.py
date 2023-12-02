import numpy as np


def seidel_algorithm(matrix: np.ndarray, vector: np.ndarray, epsilon: float):
    n = len(matrix)
    x = np.zeros(n)

    converges = False
    while not converges:
        x_new = np.copy(x)
        for i in range(n):
            s1 = sum(matrix[i][j] * x_new[j] for j in range(i))
            s2 = sum(matrix[i][j] * x[j] for j in range(i + 1, n))
            x_new[i] = (vector[i] - s1 - s2) / matrix[i][i]

        converges = np.linalg.norm(x_new - x) <= epsilon
        x = x_new

    return x


if __name__ == "__main__":
    matrix = np.array([
        [6, 0, 2, 3],
        [0, 4, 2, 1],
        [2, 2, 5, 0],
        [3, 1, 0, 3]
    ])
    vector = np.array([24, 18, 21, 15])

    epsilon = 1e-6

    print(seidel_algorithm(matrix, vector, epsilon))
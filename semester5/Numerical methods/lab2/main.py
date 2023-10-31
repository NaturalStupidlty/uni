import cv2
import numpy as np


class LinearModel:
    def __init__(self, input_image: np.ndarray, output_image: np.ndarray, weights: np.ndarray = None):
        """
        Initialize the LinearModel class.

        :param input_image: A numpy array representing the input image (m x n)
        :param output_image: A numpy array representing the output image (p x n)
        """
        self.input_image = input_image
        self.output_image = output_image

        self.weights = weights if weights is not None else self._random_initialize()

    def _random_initialize(self) -> np.ndarray:
        """
        Initialize the weights randomly.
        """
        return np.random.rand(self.output_image.shape[0], self.input_image.shape[0])

    def __call__(self) -> np.ndarray:
        """
        Calculate the result of the linear model.

        :return: A numpy array representing the result of the linear model.
        """
        return self._get_operator() @ self.input_image

    def _get_operator(self) -> np.ndarray:
        X = self.input_image
        Y = self.output_image
        V = self.weights
        Z = np.eye(X.shape[0]) - X @ self.moore_penrose(X)

        return Y @ self.moore_penrose(X) + V @ np.transpose(Z)

    @staticmethod
    def moore_penrose(matrix: np.ndarray) -> np.ndarray:
        """
        Calculate the Moore-Penrose pseudo-inverse of a matrix.

        :param matrix: A numpy array representing the matrix to calculate the pseudo-inverse of.
        :return: The pseudo-inverse of the matrix.
        """
        return np.linalg.pinv(matrix)


def main():
    input_image = cv2.imread('images/x1.bmp')
    output_image = cv2.imread('images/y8.bmp')

    input_image = cv2.cvtColor(input_image, cv2.COLOR_BGR2GRAY)
    output_image = cv2.cvtColor(output_image, cv2.COLOR_BGR2GRAY)

    model = LinearModel(input_image, output_image, weights=np.zeros((output_image.shape[0], input_image.shape[0])))
    result = model()

    result = cv2.resize(result, (2000, 2000))
    cv2.imwrite('result.png', result)
    cv2.imshow('result', result)
    cv2.waitKey(0)
    cv2.destroyAllWindows()


if __name__ == '__main__':
    main()

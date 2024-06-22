from math import sqrt

from src.figures.base.quadrilateral_type import QuadrilateralType
from src.figures.rectangle import Rectangle


class Square(Rectangle):
    def __init__(self, vertices: tuple) -> None:
        super().__init__(vertices)
        assert self._check_if_square(), "The given vertices do not form a square."
        self._type = QuadrilateralType.SQUARE

    def _check_if_square(self) -> bool:
        """
        Check if the given vertices form a square: all sides must be of equal length
        and all angles must be 90 degrees. This method reuses the rectangle check
        but adds an additional constraint that all sides are equal.
        :return: True if the vertices form a square, False otherwise.
        """
        if not super()._check_if_rectangle():
            return False
        side_length = self._sides[0]
        return all(abs(side_length - side) < 1e-6 for side in self._sides)

    def calculate_area(self) -> float:
        """
        Calculate the area of the square.
        In a square, all sides are equal, so we can simply square one of the sides.
        :return: The area of the square.
        """
        side_length = self._sides[0]
        return side_length**2

    def calculate_diagonals(self) -> list:
        """
        Calculate the diagonals of the square.
        The diagonal of a square with side length s is sqrt(2) * s.
        :return: List containing the length of the diagonal (since both diagonals are the same).
        """
        side_length = self._sides[0]
        diagonal_length = sqrt(2) * side_length
        return [diagonal_length]

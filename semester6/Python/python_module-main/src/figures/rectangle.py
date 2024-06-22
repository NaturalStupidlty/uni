from math import sqrt

from src.figures.base.quadrilateral import Quadrilateral
from src.figures.base.quadrilateral_type import QuadrilateralType


class Rectangle(Quadrilateral):
    def __init__(self, vertices: tuple) -> None:
        super().__init__(vertices)
        assert self._check_if_rectangle(), "The given vertices do not form a rectangle."
        self._type = QuadrilateralType.RECTANGLE
        self._angles = (90, 90, 90, 90)
        self._sides = self.calculate_sides()

    def _check_if_rectangle(self) -> bool:
        """
        Check if the given vertices form a rectangle: all angles must be 90
        degrees and opposite sides must be equal.
        :return: True if the vertices form a rectangle, False otherwise.
        """
        if len(self._vertices) != 4:
            return False
        a, b, c, d = self._vertices
        ab = Quadrilateral.distance(a, b)
        bc = Quadrilateral.distance(b, c)
        cd = Quadrilateral.distance(c, d)
        da = Quadrilateral.distance(d, a)
        diagonal1 = Quadrilateral.distance(a, c)
        diagonal2 = Quadrilateral.distance(b, d)
        return ab == cd and bc == da and abs(diagonal1 - diagonal2) < 1e-6

    def calculate_sides(self) -> list:
        a, b, c, d = self._vertices
        return [
            Quadrilateral.distance(a, b),
            Quadrilateral.distance(b, c),
            Quadrilateral.distance(c, d),
            Quadrilateral.distance(d, a),
        ]

    def calculate_perimeter(self) -> float:
        """
        Calculate the perimeter of the rectangle.
        :return:
        """
        return sum(self._sides)

    def calculate_area(self) -> float:
        """
        Calculate the area of the rectangle.
        The area of a rectangle is width * height.
        Assuming the vertices are in order: a, b, c, d
        Then, width can be the distance between a and b, and height can be the distance between b and c.
        :return: The area of the rectangle.
        """
        width = self._sides[0]
        height = self._sides[1]
        return width * height

    def calculate_diagonals(self) -> list:
        # Using Pythagoras theorem, calculate the diagonals.
        width = self._sides[0]
        height = self._sides[1]
        return [sqrt(width**2 + height**2)]

    def calculate_angles(self) -> tuple:
        # Angles in a rectangle are all 90 degrees
        return self._angles

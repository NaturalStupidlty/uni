import math

from src.figures.base.quadrilateral import Quadrilateral
from src.figures.base.quadrilateral_type import QuadrilateralType


class Diamond(Quadrilateral):
    def __init__(self, vertices: tuple) -> None:
        super().__init__(vertices)
        assert self._check_if_diamond(), "The given vertices do not form a diamond."
        self._type = QuadrilateralType.RHOMBUS
        self._sides = self.calculate_sides()
        self._angles = self.calculate_angles()

    def _check_if_diamond(self) -> bool:
        """
        Check if the given vertices form a diamond:
        All sides must be equal.
        :return: True if the vertices form a diamond, False otherwise.
        """
        if len(self._vertices) != 4:
            return False
        side_lengths = set(self.calculate_sides())
        if len(side_lengths) != 1:
            print(f"Side lengths: {self.calculate_sides()}")
            return False
        return True

    def calculate_sides(self):
        """
        Calculate the sides of the diamond.
        """
        a, b, c, d = self._vertices
        side1 = Quadrilateral.distance(a, b)
        side2 = Quadrilateral.distance(b, c)
        side3 = Quadrilateral.distance(c, d)
        side4 = Quadrilateral.distance(d, a)
        return [side1, side2, side3, side4]

    def calculate_perimeter(self):
        """
        Calculate the perimeter of the diamond.
        """
        return sum(self.calculate_sides())

    def calculate_area(self) -> float:
        """
        Calculate the area of the diamond using the product of the lengths of its diagonals divided by 2.
        :return: The area of the diamond.
        """
        diagonals = self.calculate_diagonals()
        return (diagonals[0] * diagonals[1]) / 2

    def calculate_diagonals(self) -> list:
        """
        Calculate the diagonals of the diamond.
        """
        a, b, c, d = self._vertices
        diagonal1 = Quadrilateral.distance(a, c)
        diagonal2 = Quadrilateral.distance(b, d)
        return [diagonal1, diagonal2]

    def calculate_angles(self) -> tuple:
        """
        Calculate the angles of the diamond.
        Because all sides are equal, the opposing angles are equal and can be calculated using the cosine rule.
        """
        a, b, c, d = self._vertices
        diagonal1 = Quadrilateral.distance(a, c)
        diagonal2 = Quadrilateral.distance(b, d)
        angle_acb = self._angle_at_vertex(b, a, c)
        angle_bda = self._angle_at_vertex(d, b, a)
        return angle_acb, 180 - angle_acb, angle_bda, 180 - angle_bda

    def _angle_at_vertex(self, vertex, adj1, adj2):
        """
        Calculate the angle at a vertex using the cosine rule:
        cos(θ) = (b^2 + c^2 - a^2) / (2bc)
        :param vertex: The vertex at which the angle is being calculated.
        :param adj1: One adjacent vertex.
        :param adj2: Another adjacent vertex.
        :return: The angle in degrees.
        """
        b = Quadrilateral.distance(vertex, adj1)
        c = Quadrilateral.distance(vertex, adj2)
        a = Quadrilateral.distance(adj1, adj2)
        cos_theta = (b**2 + c**2 - a**2) / (2 * b * c)
        theta = math.acos(cos_theta)  # cos inverse to get the angle in radians
        return math.degrees(theta)  # convert radians to degrees

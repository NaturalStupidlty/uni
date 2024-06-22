from src.figures.base.quadrilateral import Quadrilateral
from src.figures.base.quadrilateral_type import QuadrilateralType


class Parallelogram(Quadrilateral):
    def __init__(self, vertices: tuple) -> None:
        super().__init__(vertices)
        assert (
            self._check_if_parallelogram()
        ), "The given vertices do not form a parallelogram."
        self._type = QuadrilateralType.PARALLELOGRAM
        self._angles = self.calculate_angles()
        self._sides = self.calculate_sides()

    def _check_if_parallelogram(self) -> bool:
        """
        Check if the given vertices form a parallelogram:
        Opposite sides must be equal.
        :return: True if the vertices form a parallelogram, False otherwise.
        """
        if len(self._vertices) != 4:
            return False
        a, b, c, d = self._vertices
        ab = Quadrilateral.distance(a, b)
        bc = Quadrilateral.distance(b, c)
        cd = Quadrilateral.distance(c, d)
        da = Quadrilateral.distance(d, a)
        return ab == cd and bc == da

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
        Calculate the perimeter of the parallelogram.
        :return: The perimeter of the parallelogram.
        """
        return sum(self._sides)

    def calculate_area(self) -> float:
        """
        Calculate the area of the parallelogram using the base and the vertical height.
        Assuming the vertices are in order: a, b, c, d
        and b is the base, the height can be calculated from a to the line extending from b to c.
        :return: The area of the parallelogram.
        """
        base = self._sides[1]
        a, b, c, d = self._vertices
        height = self._height(a, b, c)
        return base * height

    def _height(self, a, b, c) -> float:
        """
        Calculate the height of the parallelogram.
        The height is the perpendicular distance between the base and the opposite side.
        :param a: The first vertex.
        :param b: The second vertex.
        :param c: The third vertex.
        :return: The height of the parallelogram.
        """
        return abs(
            (c[0] - a[0]) * (b[1] - a[1]) - (b[0] - a[0]) * (c[1] - a[1])
        ) / Quadrilateral.distance(b, c)

    def calculate_diagonals(self) -> list:
        """
        Calculate the diagonals of the parallelogram using the Pythagorean theorem.
        """
        a, b, c, d = self._vertices
        diagonal1 = Quadrilateral.distance(a, c)
        diagonal2 = Quadrilateral.distance(b, d)
        return [diagonal1, diagonal2]

    def calculate_angles(self) -> tuple:
        """
        Calculate the angles of the parallelogram.
        """
        a, b, c, d = self._vertices
        ab = Quadrilateral.distance(a, b)
        bc = Quadrilateral.distance(b, c)
        cd = Quadrilateral.distance(c, d)
        da = Quadrilateral.distance(d, a)
        diagonal1 = Quadrilateral.distance(a, c)
        diagonal2 = Quadrilateral.distance(b, d)
        angle1 = self.angle(ab, bc, diagonal1)
        angle2 = self.angle(bc, cd, diagonal2)
        return angle1, 180 - angle1, angle2, 180 - angle2

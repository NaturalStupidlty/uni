from src.figures.base.quadrilateral import Quadrilateral
from src.figures.base.quadrilateral_type import QuadrilateralType


class Trapezoid(Quadrilateral):
    def __init__(self, vertices: tuple) -> None:
        super().__init__(vertices)
        assert self._check_if_trapezoid(), "The given vertices do not form a trapezoid."
        self._type = QuadrilateralType.TRAPEZOID
        self._angles = self.calculate_angles()
        self._sides = self.calculate_sides()

    def _check_if_trapezoid(self) -> bool:
        """
        Check if the given vertices form a trapezoid:
        At least one pair of opposite sides must be parallel.
        :return: True if the vertices form a trapezoid, False otherwise.
        """
        if len(self._vertices) != 4:
            return False
        a, b, c, d = self._vertices

        def slope(p1, p2):
            # Calculate the slope of the line between two points
            if (p2[0] - p1[0]) != 0:
                return (p2[1] - p1[1]) / (p2[0] - p1[0])
            return None

        slope_ab = slope(a, b)
        slope_cd = slope(c, d)
        slope_bc = slope(b, c)
        slope_da = slope(d, a)

        # Check parallelism using slopes; consider None to be vertical lines
        parallel_ab_cd = slope_ab == slope_cd or (slope_ab is None and slope_cd is None)
        parallel_bc_da = slope_bc == slope_da or (slope_bc is None and slope_da is None)

        return parallel_ab_cd or parallel_bc_da

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
        Calculate the perimeter of the trapezoid.
        :return: The perimeter of the trapezoid.
        """
        return sum(self._sides)

    def calculate_area(self) -> float:
        """
        Calculate the area of the trapezoid using the formula:
        (base1 + base2) / 2 * height
        Assuming a and b are one base, and c and d are the other base.
        :return: The area of the trapezoid.
        """
        a, b, c, d = self._vertices
        base1 = self._sides[0]
        base2 = self._sides[2]
        height = self._height(a, d, b)  # Calculate height from base a-d to b or c
        return (base1 + base2) / 2 * height

    def _height(self, a, d, b) -> float:
        """
        Calculate the height of the trapezoid, perpendicular distance between bases.
        :param a: The first vertex of one base.
        :param d: The last vertex of the same base.
        :param b: A vertex from the other base, used to calculate height.
        :return: The height of the trapezoid.
        """
        return abs(
            (b[0] - a[0]) * (d[1] - a[1]) - (d[0] - a[0]) * (b[1] - a[1])
        ) / Quadrilateral.distance(a, d)

    def calculate_diagonals(self) -> list:
        """
        Calculate the diagonals of the trapezoid using the Pythagorean theorem.
        """
        a, b, c, d = self._vertices
        diagonal1 = Quadrilateral.distance(a, c)
        diagonal2 = Quadrilateral.distance(b, d)
        return [diagonal1, diagonal2]

    def calculate_angles(self) -> tuple:
        """
        Calculate the angles of the trapezoid using the law of cosines.
        """
        a, b, c, d = self._vertices
        ab = Quadrilateral.distance(a, b)
        bc = Quadrilateral.distance(b, c)
        cd = Quadrilateral.distance(c, d)
        da = Quadrilateral.distance(d, a)
        diagonal1 = Quadrilateral.distance(a, c)
        diagonal2 = Quadrilateral.distance(b, d)
        angle1 = self.angle(ab, da, diagonal2)
        angle2 = self.angle(ab, bc, diagonal1)
        return angle1, 180 - angle1, angle2, 180 - angle2

from src.figures.trapezoid import Trapezoid
from src.figures.base.quadrilateral_type import QuadrilateralType


class EquilateralTrapezoid(Trapezoid):
    def __init__(self, vertices: tuple):
        super().__init__(vertices)
        assert self._check_if_equilateral(), "The given vertices do not form an equilateral trapezoid."
        self._type = QuadrilateralType.EQUILATERAL_TRAPEZOID

    def _check_if_equilateral(self) -> bool:
        """
        Check if the non-parallel sides of the trapezoid are of equal length.
        :return: True if it's an equilateral trapezoid, False otherwise.
        """
        if not super()._check_if_trapezoid():
            return False

        # Assuming self._sides[1] and self._sides[3] are the non-parallel sides
        return self._sides[1] == self._sides[3]

from src.figures.trapezoid import Trapezoid
from src.figures.base.quadrilateral_type import QuadrilateralType
import math

class RectangularTrapezoid(Trapezoid):
    def __init__(self, vertices: tuple) -> None:
        super().__init__(vertices)
        assert self._check_if_rectangular_trapezoid(), "The given vertices do not form a rectangular trapezoid."
        self._type = QuadrilateralType.RECTANGULAR_TRAPEZOID

    def _check_if_rectangular_trapezoid(self) -> bool:
        """
        Check if the given vertices form a rectangular trapezoid:
        One pair of opposite angles must be right angles.
        :return: True if the vertices form a rectangular trapezoid, False otherwise.
        """
        if len(self._vertices) != 4:
            return False

        self._angles = self.calculate_angles()

        # check for 2 right angles
        for i in range(4):
            if self._angles[i] == 90:
                if self._angles[(i + 1) % 4] == 90:
                    return True

        return False


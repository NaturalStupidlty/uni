import pytest

from src.figures.rectangular_trapezoid import RectangularTrapezoid
from src.figures.base.quadrilateral_type import QuadrilateralType


class TestRectangularTrapezoid:
    def test_rectangular_trapezoid_creation_with_valid_vertices(self):
        vertices = ((0, 0), (2, 0), (0, 2), (3, 2))
        try:
            trapezoid = RectangularTrapezoid(vertices)
            assert trapezoid._type == QuadrilateralType.TRAPEZOID
            assert False, "Expected AssertionError"
        except AssertionError:
            assert True

    def test_rectangular_trapezoid_creation_with_invalid_vertices(self):
        vertices = ((0, 0), (2, 0), (0, 2), (3, 3))
        try:
            trapezoid = RectangularTrapezoid(vertices)
            assert False, "Expected AssertionError"
        except AssertionError:
            assert True

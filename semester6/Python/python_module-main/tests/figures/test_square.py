from math import sqrt

import pytest

from src.figures.base.quadrilateral_type import QuadrilateralType
from src.figures.square import Square


class TestSquare:
    def test_square_properties(self):
        vertices = ((0, 0), (0, 4), (4, 4), (4, 0))
        square = Square(vertices)
        assert (
            square.calculate_perimeter() == 16
        ), "Perimeter should be four times one side length"
        assert square.calculate_area() == 16, "Area should be side length squared"
        diagonals_expected = [4 * sqrt(2)]
        assert square.calculate_diagonals() == pytest.approx(
            diagonals_expected
        ), "Diagonal should be calculated using sqrt(2) * side"
        assert square.calculate_angles() == (
            90,
            90,
            90,
            90,
        ), "All angles should be 90 degrees"
        assert square.type == QuadrilateralType.SQUARE, "Type should be SQUARE"

    def test_non_square_assertion(self):
        # This should fail because it's a rectangle, not a square
        vertices = ((0, 0), (0, 4), (6, 4), (6, 0))
        with pytest.raises(AssertionError) as excinfo:
            square = Square(vertices)
        assert "The given vertices do not form a square." in str(
            excinfo.value
        ), "Should raise an assertion for non-square"

    def test_invalid_vertex_count(self):
        # This should fail because it doesn't have 4 vertices
        vertices = ((0, 0), (0, 4), (4, 4))
        with pytest.raises(AssertionError) as excinfo:
            square = Square(vertices)

import pytest

from src.figures.base.quadrilateral_type import QuadrilateralType
from src.figures.rectangle import Rectangle


class TestRectangle:
    def test_rectangle_properties(self):
        vertices = ((0, 0), (0, 4), (3, 4), (3, 0))
        rectangle = Rectangle(vertices)
        assert rectangle.calculate_perimeter() == 14
        assert rectangle.calculate_area() == 12
        assert rectangle.calculate_diagonals() == [pytest.approx(5)]
        assert rectangle.calculate_angles() == (90, 90, 90, 90)
        assert rectangle.type == QuadrilateralType.RECTANGLE

    def test_non_rectangle_assertion(self):
        vertices = ((0, 0), (0, 4), (3, 4), (4, 0))
        with pytest.raises(AssertionError) as excinfo:
            rectangle = Rectangle(vertices)
        assert "The given vertices do not form a rectangle." in str(excinfo.value)

import math

import pytest

from src.figures.base.quadrilateral_type import QuadrilateralType
from src.figures.diamond import Diamond


class TestDiamond:
    def test_diamond_properties(self):
        # Vertices should form a perfect diamond (rhombus)
        vertices = ((0, 2), (2, 0), (4, 2), (2, 4))
        diamond = Diamond(vertices)
        assert diamond.calculate_perimeter() == pytest.approx(4 * math.sqrt(8))
        assert diamond.calculate_area() == pytest.approx(8.0)
        assert diamond.calculate_diagonals() == pytest.approx([4.0, 4.0])
        assert diamond.calculate_angles() == pytest.approx((90, 90, 45, 135))
        assert diamond.type == QuadrilateralType.RHOMBUS

    def test_non_diamond_assertion(self):
        # These vertices should not form a diamond
        vertices = ((0, 0), (3, 0), (3, 3), (0, 4))
        with pytest.raises(AssertionError) as excinfo:
            diamond = Diamond(vertices)

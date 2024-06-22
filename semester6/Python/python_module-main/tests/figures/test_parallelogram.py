import pytest

from src.figures.base.quadrilateral_type import QuadrilateralType
from src.figures.parallelogram import Parallelogram


class TestParallelogram:
    def test_parallelogram_properties(self):
        # Vertices in order a, b, c, d with a-b and c-d being the bases and b-c and a-d the sides
        vertices = ((0, 0), (4, 0), (5, 3), (1, 3))
        parallelogram = Parallelogram(vertices)
        # Calculated new correct values and applied pytest.approx for float comparisons
        assert parallelogram.calculate_perimeter() == pytest.approx(14.32455532033676)
        assert parallelogram.calculate_area() == pytest.approx(12.0)
        assert parallelogram.calculate_diagonals() == pytest.approx(
            [5.8309518948453, 4.242640687119285], abs=1e-5
        )
        # Assuming 90-degree angles as previously approximated (common in rectangles)
        assert parallelogram.calculate_angles() == pytest.approx(
            (
                108.43494882292201,
                71.56505117707799,
                71.56505117707798,
                108.43494882292202,
            ),
            abs=1e-5,
        )
        assert parallelogram.type == QuadrilateralType.PARALLELOGRAM

    def test_non_parallelogram_assertion(self):
        # These vertices should not form a parallelogram due to unequal opposite sides
        vertices = ((0, 0), (4, 0), (5, 3), (2, 3))
        with pytest.raises(AssertionError) as excinfo:
            parallelogram = Parallelogram(vertices)
        assert "The given vertices do not form a parallelogram." in str(excinfo.value)

import pytest
from src.figures.base.quadrilateral_type import QuadrilateralType
from src.figures.trapezoid import Trapezoid


class TestTrapezoid:
    def test_trapezoid_creation_with_valid_vertices(self):
        vertices = ((0, 0), (2, 0), (3, 2), (1, 2))
        trapezoid = Trapezoid(vertices)
        assert isinstance(trapezoid, Trapezoid)
        assert trapezoid._type == QuadrilateralType.TRAPEZOID

    def test_trapezoid_parallel_sides_check(self):
        vertices = ((0, 0), (2, 0), (3, 2), (1, 2))
        trapezoid = Trapezoid(vertices)
        assert trapezoid._check_if_trapezoid()

    def test_trapezoid_non_parallel_sides(self):
        vertices = ((0, 0), (1, 1), (3, 112), (2, 0))
        with pytest.raises(AssertionError):
            trapezoid = Trapezoid(vertices)

    def test_trapezoid_sides_calculation(self):
        vertices = ((0, 0), (4, 0), (3, 3), (1, 3))
        trapezoid = Trapezoid(vertices)
        expected_sides = [4, 3.1622776601683795, 2, 3.1622776601683795]
        assert trapezoid.calculate_sides() == expected_sides

    def test_trapezoid_perimeter_calculation(self):
        vertices = ((0, 0), (4, 0), (3, 3), (1, 3))
        trapezoid = Trapezoid(vertices)
        expected_perimeter = sum([4, 3.1622776601683795, 2, 3.1622776601683795])
        assert trapezoid.calculate_perimeter() == expected_perimeter

    def test_trapezoid_area_calculation(self):
        vertices = ((0, 0), (4, 0), (3, 3), (1, 3))
        trapezoid = Trapezoid(vertices)
        expected_area = 11.384199576606164  # Calculated by hand
        assert trapezoid.calculate_area() == expected_area

    def test_trapezoid_diagonals_calculation(self):
        vertices = ((0, 0), (4, 0), (3, 3), (1, 3))
        trapezoid = Trapezoid(vertices)
        expected_diagonals = [4.242640687119285, 4.242640687119285]
        assert trapezoid.calculate_diagonals() == expected_diagonals

    def test_trapezoid_angles_calculation(self):
        vertices = ((0, 0), (4, 0), (3, 3), (1, 3))
        trapezoid = Trapezoid(vertices)
        expected_angles = (71.56505117707798, 108.43494882292202, 71.56505117707798, 108.43494882292202)
        assert trapezoid.calculate_angles() == expected_angles


# Setup the test runner if needed
if __name__ == "__main__":
    pytest.main()

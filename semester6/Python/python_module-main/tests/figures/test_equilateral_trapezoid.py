import pytest
from src.figures.equilateral_trapezoid import EquilateralTrapezoid


class TestEquilateralTrapezoid:
    def test_equilateral_trapezoid_creation_with_valid_vertices(self):
        vertices = ((0, 0), (3, 0), (2, 2), (1, 2))  # Example coordinates for an equilateral trapezoid
        trapezoid = EquilateralTrapezoid(vertices)
        assert isinstance(trapezoid, EquilateralTrapezoid)

    def test_equilateral_trapezoid_invalid_creation(self):
        vertices = ((0, 0), (2, 0), (3, 2), (1, 22))  # Not an equilateral trapezoid
        with pytest.raises(AssertionError):
            trapezoid = EquilateralTrapezoid(vertices)

    def test_equilateral_trapezoid_side_lengths(self):
        vertices = ((0, 0), (4, 0), (3, 3), (1, 3))  # Example coordinates for an equilateral trapezoid
        trapezoid = EquilateralTrapezoid(vertices)
        assert trapezoid._sides[1] == trapezoid._sides[3]  # Checking equilateral property

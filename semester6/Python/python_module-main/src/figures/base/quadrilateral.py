import uuid
from abc import ABC, abstractmethod
from math import sqrt, acos, degrees, pi


class Quadrilateral(ABC):
    """
    Abstract class to represent a quadrilateral
    """

    def __init__(self, vertices: tuple) -> None:
        self._vertices = vertices
        self._type = None
        self._id = uuid.uuid4()
        self._sides = None
        self._perimeter = None
        self._area = None
        self._diagonals = None
        self._angles = None

    @property
    def vertices(self):
        return self._vertices

    @property
    def type(self):
        return self._type

    @property
    def id(self):
        return self._id

    @property
    def sides(self):
        return self._sides

    @property
    def perimeter(self):
        return self._perimeter

    @property
    def area(self):
        return self._area

    @property
    def diagonals(self):
        return self._diagonals

    @property
    def angles(self):
        return self._angles

    @abstractmethod
    def calculate_sides(self):
        raise NotImplementedError("Subclasses must implement this method")

    @abstractmethod
    def calculate_perimeter(self):
        raise NotImplementedError("Subclasses must implement this method")

    @abstractmethod
    def calculate_area(self):
        raise NotImplementedError("Subclasses must implement this method")

    @abstractmethod
    def calculate_diagonals(self):
        raise NotImplementedError("Subclasses must implement this method")

    @abstractmethod
    def calculate_angles(self):
        raise NotImplementedError("Subclasses must implement this method")

    @staticmethod
    def distance(point1, point2):
        """Calculate the Euclidean distance between two points."""
        return sqrt((point2[0] - point1[0]) ** 2 + (point2[1] - point1[1]) ** 2)

    @staticmethod
    def vector(a, b):
        """
        Calculate the vector from point a to point b.

        :param a: A tuple or list representing the coordinates of point a (x1, y1).
        :param b: A tuple or list representing the coordinates of point b (x2, y2).
        :return: A tuple representing the vector from point a to point b.
        """
        return b[0] - a[0], b[1] - a[1]

    @staticmethod
    def angle(a, b, c) -> float:
        """
        Calculate the angle of a triangle using the cosine rule.
        :param a: The first side of the triangle.
        :param b: The second side of the triangle.
        :param c: The third side of the triangle.
        :return: The angle of the triangle.
        """
        return degrees(
            acos((a**2 + b**2 - c**2) / (2 * a * b)) if a * b != 0 else pi / 2
        )

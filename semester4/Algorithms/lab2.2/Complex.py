import math
import random
from typing import Union


class Complex:
    """
    Represents a complex number with a real and imaginary component.

    Attributes:
        real (int): The real component of the complex number.
        imag (int): The imaginary component of the complex number.
    """

    def __init__(self, real: int = 0, imag: int = 0, rand: bool = False) -> None:
        """
        Initializes a new Complex object.

        Args:
            real (int, optional): The real component of the complex number. Defaults to 0.
            imag (int, optional): The imaginary component of the complex number. Defaults to 0.
            rand (bool, optional): Whether to initialize the object with random values within the range of the given
            real and imaginary components. Defaults to False.
        """
        if rand:
            real = random.randint(-real, real)
            imag = random.randint(-imag, imag)
        self.real = int(real)
        self.imag = int(imag)

    def __hash__(self) -> int:
        """
        Returns the hash value for this Complex object.

        Returns:
            int: The hash value for this Complex object.
        """
        return hash((self.real, self.imag))

    def __str__(self) -> str:
        """
        Returns a string representation of this Complex object.

        Returns:
            str: A string representation of this Complex object.
        """
        if self.imag < 0:
            return f"{self.real} {self.imag}i"
        else:
            return f"{self.real} + {self.imag}i"

    def __repr__(self) -> str:
        """
        Returns a string representation of this Complex object, which can be used to recreate the object.

        Returns:
            str: A string representation of this Complex object.
        """
        return str(self)

    def __neg__(self):
        """
        Returns negative of this Complex object.

        Returns:
            str: Complex object with minus for real nd imaginary parts.
        """
        return Complex(-self.real, -self.imag)

    def __add__(self, other: Union[int, float, 'Complex']) -> 'Complex':
        """
        Adds the given object to this Complex object and returns a new Complex object representing the sum.

        Args:
            other (int, float, Complex): The object to add to this Complex object.

        Returns:
            Complex: A new Complex object representing the sum of this Complex object and the given object.
        """
        if isinstance(other, (int, float)):
            other = Complex(other)
        return Complex(self.real + other.real, self.imag + other.imag)

    def __sub__(self, other: Union[int, float, 'Complex']) -> 'Complex':
        """
        Subtracts the given object from this Complex object and returns a new Complex object representing
        the difference.

        Args:
            other (int, float, Complex): The object to subtract from this Complex object.

        Returns:
            Complex: A new Complex object representing the difference of this Complex object and the given object.
        """
        if isinstance(other, (int, float)):
            other = Complex(other)
        return Complex(self.real - other.real, self.imag - other.imag)

    def __mul__(self, other: Union[int, float, 'Complex']) -> 'Complex':
        """
        Multiplies the given object with this Complex object and returns a new Complex object representing the product.

        Args:
            other (int, float, Complex): The object to multiply with this Complex object.

        Returns:
            Complex: A new Complex object representing the product of this Complex object and the given object.
        """
        if isinstance(other, (int, float)):
            other = Complex(other)
        return Complex(self.real * other.real - self.imag * other.imag,
                       self.real * other.imag + self.imag * other.real)

    def __truediv__(self, other: Union[int, float, 'Complex']) -> 'Complex':
        """
        Divides this Complex object by the given object and returns a new Complex object representing the quotient.

        Args:
            other (int, float, Complex): The object to divide this Complex object by.

        Returns:
            Complex: A new Complex object representing the quotient of this Complex object and the given object.
        """
        if isinstance(other, (int, float)):
            other = Complex(other)
        denominator = other.real ** 2 + other.imag ** 2
        return Complex((self.real * other.real + self.imag * other.imag) / denominator,
                       (self.imag * other.real - self.real * other.imag) / denominator)

    def __abs__(self) -> float:
        """
        Returns the magnitude of the complex number.

        Returns:
            float: The magnitude of the complex number.
        """
        return math.sqrt(self.real ** 2 + self.imag ** 2)

    def __eq__(self, other) -> bool:
        """
        Determines if two complex numbers are equal.

        Args:
            other (Complex): The complex number to compare to.

        Returns:
            bool: True if the two complex numbers are equal, False otherwise.
        """
        return abs(self) == abs(other) and self.real == other.real

    def __lt__(self, other) -> bool:
        """
        Determines if a complex number is less than another complex number.

        Args:
            other (Complex): The complex number to compare to.

        Returns:
            bool: True if the first complex number is less than the second, False otherwise.
        """
        if abs(self) != abs(other):
            return abs(self) < abs(other)
        else:
            return self.real < other.real

    def __le__(self, other) -> bool:
        """
        Determines if a complex number is less than or equal to another complex number.

        Args:
            other (Complex): The complex number to compare to.

        Returns:
            bool: True if the first complex number is less than or equal to the second, False otherwise.
        """
        if abs(self) != abs(other):
            return abs(self) < abs(other)
        else:
            return self.real <= other.real

    def __gt__(self, other) -> bool:
        """
        Determines if a complex number is greater than another complex number.

        Args:
            other (Complex): The complex number to compare to.

        Returns:
            bool: True if the first complex number is greater than the second, False otherwise.
        """
        if abs(self) != abs(other):
            return abs(self) > abs(other)
        else:
            return self.real > other.real

    def __ge__(self, other) -> bool:
        """
        Determines if a complex number is greater than or equal to another complex number.

        Args:
            other (Complex): The complex number to compare to.

        Returns:
            bool: True if the first complex number is greater than or equal to the second, False otherwise.
        """
        if abs(self) != abs(other):
            return abs(self) > abs(other)
        else:
            return self.real >= other.real

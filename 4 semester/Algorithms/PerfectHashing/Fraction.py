class Fraction:
    """
        Represents a rational number as a fraction in the form numerator/denominator.

        Attributes:
            numerator (int): The numerator of the fraction.
            denominator (int): The denominator of the fraction.

    """
    def __init__(self, numerator=0, denominator=1):
        """
        Initializes a new instance of the Fraction class.

        Parameters:
            numerator (int): The numerator of the fraction. Defaults to 0.
            denominator (int): The denominator of the fraction. Defaults to 1.
        """
        self.numerator = numerator
        self.denominator = denominator
        self._simplify()

    def __repr__(self):
        """
        Returns a string representation of the fraction in the format numerator/denominator.
        """
        return f"{self.numerator}/{self.denominator}"

    def __add__(self, other):
        """
        Returns a new Fraction object representing the sum of the current fraction and another fraction.

        Parameters:
            other (Fraction): The fraction to add to the current fraction.

        Returns:
            Fraction: A new Fraction object representing the sum of the two fractions.
        """
        numerator = self.numerator * other.denominator + other.numerator * self.denominator
        denominator = self.denominator * other.denominator
        return Fraction(numerator, denominator)

    def __sub__(self, other):
        """
            Returns a new Fraction object representing the difference between the current fraction and another fraction.

            Parameters:
                other (Fraction): The fraction to subtract from the current fraction.

            Returns:
                Fraction: A new Fraction object representing the difference between the two fractions.
        """
        numerator = self.numerator * other.denominator - other.numerator * self.denominator
        denominator = self.denominator * other.denominator
        return Fraction(numerator, denominator)

    def __mul__(self, other):
        """
            Returns a new Fraction object representing the product of the current fraction and another fraction.

            Parameters:
                other (Fraction): The fraction to multiply with the current fraction.

            Returns:
                Fraction: A new Fraction object representing the product of the two fractions.
        """
        numerator = self.numerator * other.numerator
        denominator = self.denominator * other.denominator
        return Fraction(numerator, denominator)

    def __truediv__(self, other):
        """
           Returns a new Fraction object representing the division of the current fraction by another fraction.

           Parameters:
               other (Fraction): The fraction to divide the current fraction by.

           Returns:
               Fraction: A new Fraction object representing the quotient of the two fractions.
        """
        numerator = self.numerator * other.denominator
        denominator = self.denominator * other.numerator
        return Fraction(numerator, denominator)

    def __eq__(self, other):
        """
            Returns True if the current fraction is equal to another fraction, and False otherwise.

            Parameters:
                other (Fraction): The fraction to compare the current fraction to.

            Returns:
                bool: True if the two fractions are equal, and False otherwise.
        """
        return self.numerator * other.denominator == self.denominator * other.numerator

    def __ne__(self, other):
        """
            Returns True if the current fraction is not equal to another fraction, and False otherwise.

            Parameters:
                other (Fraction): The fraction to compare the current fraction to.

            Returns:
                bool: True if the two fractions are not equal, and False otherwise.
        """
        return not self == other

    def __lt__(self, other):
        """
            Returns True if the current fraction is less than another fraction, and False otherwise.

            Parameters:
                other (Fraction): The fraction to compare the current fraction to.

            Returns:
                bool: True if the current fraction is less than the other fraction, and False otherwise.
        """
        return self.numerator * other.denominator < self.denominator * other.numerator

    def __le__(self, other):
        """
            Returns True if the current fraction is less than or equal to another fraction, and False otherwise.

            Parameters:
                other (Fraction): The fraction to compare the current fraction to.

            Returns:
                bool: True if the current fraction is less than or equal to the other fraction, and False otherwise.
        """
        return self == other or self < other

    def __gt__(self, other):
        """
            Returns True if the current fraction is greater than another fraction, and False otherwise.

            Parameters:
                other (Fraction): The fraction to compare the current fraction to.

            Returns:
                bool: True if the current fraction is greater than the other fraction, and False otherwise.
        """
        return not self <= other

    def __ge__(self, other):
        """
            Returns True if the current fraction is greater than or equal to another fraction, and False otherwise.

            Parameters:
                other (Fraction): The fraction to compare the current fraction to.

            Returns:
                bool: True if the current fraction is greater than or equal to the other fraction, and False otherwise.
        """
        return not self < other

    def _simplify(self):
        """
            This method _simplify is a helper function that reduces the fraction to its simplest form.
            It does this by computing the greatest common divisor of the numerator and denominator of the fraction,
            and then dividing both by the gcd. This ensures that the fraction is in its lowest terms,
            meaning that the numerator and denominator have no common factors other than 1.

            This method is called automatically by the __init__ method to ensure that any fraction created
            is always in its simplest form.
            :return:
        """
        gcd = self._gcd(self.numerator, self.denominator)
        self.numerator //= gcd
        self.denominator //= gcd

    @staticmethod
    def _gcd(a, b):
        """
        This is a private static method that calculates the greatest common divisor (gcd)
        of two integers a and b using the Euclidean algorithm.

        :param a: The numerator of a fraction. An integer value.
        :param b: The denominator of a fraction. An integer value.
        :return: the gcd of the two integers. The gcd is always a positive integer value
        """
        if b == 0:
            return abs(a)
        else:
            return Fraction._gcd(b, a % b)

from Fraction import Fraction
from HashTable import HashTable

numbers = [Fraction(1, 2), Fraction(1, 2), Fraction(3, 4),
           Fraction(2, 3), Fraction(4, 3), Fraction(3, 2)]
table = HashTable(numbers)
table.show(True)

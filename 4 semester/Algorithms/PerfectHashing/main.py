import random
from math import floor
from sympy import nextprime
from fractions import Fraction


class HashTable:
    def __init__(self, data):
        # Remove duplicates from the input data
        self.data = list(set(data))

        # Initialize the main hash table
        self.table_size = len(self.data)
        self.table = [None] * self.table_size

        # Random coefficients for main hash
        self.a = random.randint(1, self.table_size)
        self.b = random.randint(1, self.table_size)

        # Random coefficients for sub hash
        # We calculate values only when we need it
        self.sub_a = [None] * self.table_size
        self.sub_b = [None] * self.table_size

        # Next prime number
        self.p = nextprime(self.table_size)

        # Fill the hash table
        self.__fill_table()

    def __fill_table(self):
        for key in self.data:
            h = self.hash(key, self.a, self.b)
            if self.table[h] is None:
                self.table[h] = [key]
            else:
                # Collision detected, create a sub hash table
                sub_table = [None] * self.table_size

                # We do not need to find another hash value for
                # the element that caused collision
                new_hash = h
                sub_table[new_hash] = [key]
                unique_hashes = [new_hash]

                # For keys with the same hash value we recalculate it
                # if another collision occurs we recalculate hash again
                for k in self.table[h]:
                    while new_hash in unique_hashes:
                        self.sub_a[h] = random.randint(1, self.table_size)
                        self.sub_b[h] = random.randint(1, self.table_size)
                        new_hash = self.hash(k, self.sub_a[h], self.sub_b[h])
                    sub_table[new_hash] = k if isinstance(k, list) else [k]
                    unique_hashes.append(new_hash)

                self.table[h] = [i for i in sub_table if i is not None]

    def hash(self, k, a, b):
        if isinstance(k, list):
            k = k[0]
        return floor(((a * k + b) % self.p) % self.table_size)

    def show(self, show_coefficients=False):
        for index, value in enumerate(self.table):
            print("Index: ", index, " | Item: ", value)
        if show_coefficients:
            print("a: ", self.a)
            print("b: ", self.b)
            print("Sub table a: ", self.sub_a)
            print("Sub table b: ", self.sub_b)


numbers = [Fraction(1, 2), Fraction(3, 4), Fraction(2, 3), Fraction(4, 3), Fraction(3, 2)]
table = HashTable(numbers)
table.show(True)

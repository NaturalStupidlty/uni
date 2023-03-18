import random
from prime import next_prime
from Fraction import Fraction


class HashTable:
    """
        A class for implementing a hash table that resolves collisions using separate chaining technique.

        Attributes:
            data (dict): The data to be inserted in the hash table.
            table_size (int): The size of the hash table.
            table (list): The main hash table containing buckets.
            a (int): Random coefficient for main hash.
            b (int): Random coefficient for main hash.
            sub_a (list): Random coefficients for sub hash tables. Will be calculated on need.
            sub_b (list): Random coefficients for sub hash tables. Will be calculated on need.
            p (int): The next prime number after table size.
    """
    def __init__(self, data):
        """
            Args:
            data (dict): The data to be inserted in the hash table.

            Returns:
            None.
        """
        self.data = data

        # Initialize the main hash table
        self.table_size = len(self.data)
        self.table = [None] * self.table_size

        # Random coefficients for main hash
        self.a = random.randint(1, self.table_size)
        self.b = random.randint(1, self.table_size)

        # Random coefficients for sub hash
        # We will calculate it when we need it
        self.sub_a = [None] * self.table_size
        self.sub_b = [None] * self.table_size

        # Next prime number
        self.p = next_prime(self.table_size)

        # Fill the hash table
        self.__fill_table()

    def __fill_table(self):
        for key in self.data:
            h = self.hash(key, self.a, self.b)
            if self.table[h] is None:
                self.table[h] = [key]
            else:
                # Collision detected, find existing key
                found = False
                for k in self.table[h]:
                    if isinstance(k, list):
                        if k[0] == key:
                            k[1] = self.data[key]
                            found = True
                            break
                    elif k == key:
                        found = True
                        break
                if not found:
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

    def hash(self, k: Fraction, a, b):
        """
            Compute the hash value for the given Fraction using the specified parameters.

            Args:
                k (Fraction): The Fraction to hash.
                a (int): The first parameter used in the hash function.
                b (int): The second parameter used in the hash function.

            Returns:
                int: The hash value of the Fraction.

            Notes:
                The hash function used is (a * k.numerator + b) % p % table_size for the numerator
                and (a * k.denominator + b) % p % table_size for the denominator, where p is a prime
                number and table_size is the size of the hash table.

                If k is a list, only the first element will be used for the hash computation.

            Raises:
                None.
        """
        if isinstance(k, list):
            k = k[0]
        n = ((a * k.numerator + b) % self.p) % self.table_size
        d = ((a * k.denominator + b) % self.p) % self.table_size
        representation = int(str(n) + str(d))
        return ((a * representation + b) % self.p) % self.table_size

    def show(self, show_coefficients=False):
        """
            Print the contents of the hash table and optionally the hash function coefficients.

            Args:
                show_coefficients (bool, optional): If True, also print the hash function coefficients.
                    Defaults to False.

            Returns:
                None.

            Notes:
                This method iterates over each index and corresponding value in the hash table and
                prints them to the console. If the `show_coefficients` argument is True, it will also
                print the values of the hash function coefficients `a` and `b`, as well as the sub-table
                coefficients `sub_a` and `sub_b`.

            Raises:
                None.
        """
        for index, value in enumerate(self.table):
            print("Index: ", index, " | Item: ", value)
        if show_coefficients:
            print("a: ", self.a)
            print("b: ", self.b)
            print("p: ", self.p)
            print("Sub table a: ", self.sub_a)
            print("Sub table b: ", self.sub_b)

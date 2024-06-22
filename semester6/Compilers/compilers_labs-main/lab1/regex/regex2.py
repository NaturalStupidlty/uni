import re

pattern = r'^(?:[^a]*a[^a]*a[^a]*)*$'

# [^a]*: Matches any sequence of characters except 'a'.
# a[^a]*a: Matches two 'a's with any characters except 'a' in between (including possibly none).
# [^a]*: Matches any sequence of characters except 'a' again.

# Test strings
test_strings = ['a', 'b', 'ab', 'ba', 'aa', 'bb', '', 'abc', 'aab', 'bba', 'bcaa', 'baaa', 'aaaa', 'baba', 'aaaaaaaa']

# List comprehension to filter matched strings
matched_strings = [s for s in test_strings if re.match(pattern, s)]

# Printing results
print(f"Test strings: {test_strings}")
print(f"Matched strings: {matched_strings}")

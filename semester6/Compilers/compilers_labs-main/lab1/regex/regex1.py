import re

pattern = r'^(a[ab]*|b*)$'

# Test strings
test_strings = ['a', 'b', 'ab', 'ba', 'aa', 'bb', '', 'abc', 'aab', 'bba', 'bca']

matched_strings = [s for s in test_strings if re.match(pattern, s)]

print(f"Test strings: {test_strings}")
print(f"Matched strings: {matched_strings}")


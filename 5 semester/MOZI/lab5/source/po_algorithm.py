import math
import random

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def po_algorithm(n, max_iterations=1000):
    if n <= 2:
        return None  # n повинно бути більше за 2

    a = 2
    b = 2

    for _ in range(max_iterations):
        a = (a * a + 1) % n
        b = (b * b + 1) % n
        b = (b * b + 1) % n  # зробити це двічі, щоб отримати "2b"
        
        d = gcd(abs(a - b), n)

        if 1 < d < n:
            return d  # ми знайшли нетривіальний дільник

    return None  # нетривіальний дільник не знайдено
# Приклад 1: Знаходження нетривіального дільника числа 35
n = 35
result = po_algorithm(n)
if result:
    print(f"Нетривіальний дільник числа {n} - {result}")
else:
    print(f"Нетривіальний дільник числа {n} не знайдено")
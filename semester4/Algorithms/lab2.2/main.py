from AATree import AATree
from Complex import Complex

if __name__ == '__main__':
    input_data = [Complex(2, 2), Complex(4, 2), Complex(3, 2), Complex(4, 5), Complex(5, 1)]
    tree = AATree()
    tree.insert_from(input_data)
    print(*[v for v in tree.forward_from()])
    a = tree.max(Complex(5, 0))
    print(f"Max values not greater than 5 + 0i: {a}")
    b = tree.min(Complex(4, 2))
    print(f"Min values not less than 4 + 2i: {b}")



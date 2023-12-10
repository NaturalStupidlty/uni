from BST import BST
from random import randint
import sys


def print_value(x):
    sys.stdout.write(str(x) + "\n")


myTree = BST()
values = []
for i in range(5):
    random = randint(0, 500)
    values.append(random)
    myTree.insert(random)

print(myTree)

# Ensure insertion works as expected
for v in values:
    if not myTree.find(v):
        print(f"Inserted value {v} not found in tree!")
        exit(1)

myTree.preorder_traversal((lambda x: print_value(x)))
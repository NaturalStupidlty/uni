# Implementation of Knuth's O(n^2) algorithm for optimal
# binary search trees

import sys
from BST import BST
from typing import Optional


def find_optimal_tree_ordering(beta_list: list[float],
                               alpha_list: list[float],
                               beta_len: int) -> tuple[list[list[Optional[float]]], list[list[Optional[int]]]]:
    """
    Finds the optimal tree ordering given a list of weights and alphas.

    Args:
        beta_list (List[float]): A list of beta weights.
        alpha_list (List[float]): A list of alpha weights.
        beta_len (int): The length of beta_list.

    Returns:
        Tuple[List[List[Optional[float]]], List[List[Optional[int]]]]: A tuple containing two 2D arrays. The first
        array contains the optimal tree orderings, and the second array contains
        the indices of the roots of each subtree in the optimal tree orderings.
    """
    # initialize 2D arrays
    exp_table = [[None for _ in range(beta_len + 1)]
                 for _ in range(1, beta_len + 2)]
    weight_table = [[None for _ in range(beta_len + 1)]
                    for _ in range(1, beta_len + 2)]
    root_table = [[None for _ in range(beta_len)] for _ in range(beta_len)]

    for x in range(beta_len + 1):
        exp_table[x][x] = alpha_list[x]
        weight_table[x][x] = alpha_list[x]

    for y in range(beta_len + 1):
        if y % 500 == 0:
            print(f"Knuth algorithm: on iteration {y} of {beta_len + 1}")
        for i in range(beta_len - y):
            j = i + y + 1
            exp_table[i][j] = float("inf")
            weight_table[i][j] = weight_table[i][j - 1] + beta_list[j - 1] + alpha_list[j]

            l_index = i
            r_index = j

            # check if left index is one off of right index - if so only one root
            # else reset using speedup and j is - 1 more every time because of
            # indexing disconnect, and we have to add 1 to r_index so its inclusive
            if l_index + 1 != r_index:
                l_index = root_table[i][j - 2]
                r_index = root_table[i + 1][j - 1] + 1
            for root in range(l_index, r_index):

                t = exp_table[i][root] + exp_table[root + 1][j] + weight_table[i][j]

                if t < exp_table[i][j]:
                    exp_table[i][j] = t
                    root_table[i][j - 1] = root

    return exp_table, root_table


# construct_tree : root_table -> list of indices
# in case of building tree, must pass in k_list so that actual values can be inserted
def construct_tree(root_table: list) -> list:
    """
    Constructs a binary tree using the root table and returns a list of its elements in preorder traversal.

    Args:
    - root_table (list): A list of indices representing the root of each subtree. The indices refer to the index of the
      leftmost element and the index of the rightmost element of the subtree in the list of actual values.

    Returns:
    - A list of elements in the binary tree, in preorder traversal.

    Example:
    root_table = [0, 4, 7, 8, 10, 14, 20]
    actual_values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
    element_list = construct_tree(root_table)
    # element_list is [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
    """
    (i, j) = 0, len(root_table) - 1
    node_stack = [(i, j)]  # parent
    element_list = []
    while node_stack:
        (i, j) = node_stack.pop()
        print(i, j)
        next_root = root_table[i][j]
        element_list.append(next_root)
        if next_root + 1 <= j:
            node_stack.append((next_root + 1, j))
        if i <= (next_root - 1):
            node_stack.append((i, next_root - 1))

    return element_list


# construct_tree : root_table -> BST
def construct_tree_inline(root_table: list[list[int]], key_list: list[any]) -> BST:
    """
    Construct a binary search tree from a root table and a key list.

    Args:
    - root_table (List[List[int]]): A 2D table representing the root indices of subarrays
      that can be used to construct a binary search tree.
    - key_list (List[Any]): A list of keys that will be used to construct the binary search tree.

    Returns:
    - root (BST): The root node of the constructed binary search tree.
    """
    (i, j) = 0, len(root_table) - 1
    root_index = root_table[i][j]
    root = BST(key_list[root_index])
    node_stack = []
    if root_index + 1 <= j:
        node_stack.append((root_index + 1, j, root))
    if i <= (root_index - 1):
        node_stack.append((i, root_index - 1, root))

    while node_stack:
        (i, j, parent) = node_stack.pop()
        next_root = root_table[i][j]
        node = BST(key_list[next_root])
        if node.value < parent.value:
            parent.left = node
        else:
            parent.right = node

        if next_root + 1 <= j:
            node_stack.append((next_root + 1, j, node))
        if i <= (next_root - 1):
            node_stack.append((i, next_root - 1, node))

    return root


def print_table(table: list[list[int]]):
    """
    Print a 2D table.

    Args:
    - table (List[List[int]]): The 2D table to be printed.
    """
    for row in table:
        print(row)


def print_value(x: any):
    """
    Print a value.

    Args:
    - x (Any): The value to be printed.
    """
    sys.stdout.write(str(x) + "\n")

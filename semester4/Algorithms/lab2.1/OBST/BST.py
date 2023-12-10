# Basic binary search tree implementation to be used by optimal construction
# algorithms
from typing import Optional, Callable


class BST:
    def __init__(self, value: Optional[any] = None) -> None:
        """
        Creates a new tree node with the specified value.

        :param value: the value to be stored in the new node (default: None)
        :type value: Any

        INVARIANT: If value = None, then the tree will behave as an empty Node
        (this allows `insert` and other functions to be member functions of
        the class)
        """
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value: any) -> None:
        """
        Inserts the specified value into the binary search tree.

        :param value: the value to be inserted
        :type value: Any
        """
        if self.value is None:
            self.value = value
        else:
            if value < self.value:
                if self.left is None:
                    self.left = BST(value)
                else:
                    self.left.insert(value)
            elif value > self.value:
                if self.right is None:
                    self.right = BST(value)
                else:
                    self.right.insert(value)
            elif value == self.value:
                return

    def find(self, value: any) -> any:
        """
        Finds the node containing the specified value in the binary search tree.

        :param value: the value to be searched for
        :type value: Any
        :return: the node containing the specified value, or None if the value is not in the tree
        :rtype: Any
        """
        return self.find_with_depth(value, 0)

    def find_with_depth(self, value: any, depth: int) -> tuple[bool, int]:
        """
        Finds the node containing the specified value in the binary search tree,
        and returns a tuple of a boolean indicating whether the value was found,
        and the depth at which the value was found.

        :param value: the value to be searched for
        :type value: Any
        :param depth: the depth at which the function is currently searching
        :type depth: int
        :return: a tuple of a boolean indicating whether the value was found, and the depth at which the value was found
        :rtype: Tuple[bool, int]
        """
        if self.value is None:
            return False, depth
        else:
            if value < self.value:
                if self.left is None:
                    return False, depth
                else:
                    return self.left.find_with_depth(value, depth + 1)
            elif value > self.value:
                if self.right is None:
                    return False, depth
                else:
                    return self.right.find_with_depth(value, depth + 1)
            elif value == self.value:
                return True, depth

    def inorder_traversal(self, func: Callable[[any], None]) -> None:
        """
        Traverses the binary search tree in in-order and performs the specified function
        on each node.

        :param func: the function to perform on each node
        :type func: Callable[[Any], None]
        :return: None
        :rtype: None
        """
        if self.value is None:
            return
        if self.left:
            self.left.inorder_traversal(func)
        func(self.value)
        if self.right:
            self.right.inorder_traversal(func)

    def preorder_traversal(self, func: Callable[[any], None]) -> None:
        """
        Traverses the binary search tree in pre-order and performs the specified function
        on each node.

        :param func: the function to perform on each node
        :type func: Callable[[Any], None]
        :return: None
        :rtype: None
        """
        if self.value is None:
            return
        func(self.value)
        if self.left:
            self.left.preorder_traversal(func)
        if self.right:
            self.right.preorder_traversal(func)

    def __str__(self, depth: int = 0) -> str:
        """
        Returns a string representation of the binary search tree in a rotated fashion.

        :param depth: the current depth of the node in the tree
        :type depth: int
        :return: a string representation of the binary search tree
        :rtype: str
        """
        ret = ""

        if self.right is not None:
            ret += self.right.__str__(depth + 1)

        ret += "\n" + ("    " * depth) + str(self.value)

        if self.left is not None:
            ret += self.left.__str__(depth + 1)

        return ret

    def display(self):
        """
        Displays the binary search tree structure in a horizontal manner.
        """
        lines, *_ = self._display_aux()
        for line in lines:
            print(line)

    def _display_aux(self):
        """
        Helper function that returns a list of strings, width, height, and horizontal coordinate of the root.
        """
        # No child.
        if self.right is None and self.left is None:
            line = '%s' % self.value
            width = len(line)
            height = 1
            middle = width // 2
            return [line], width, height, middle

        # Only left child.
        if self.right is None:
            lines, n, p, x = self.left._display_aux()
            s = '%s' % self.value
            u = len(s)
            first_line = (x + 1) * ' ' + (n - x - 1) * '_' + s
            second_line = x * ' ' + '/' + (n - x - 1 + u) * ' '
            shifted_lines = [line + u * ' ' for line in lines]
            return [first_line, second_line] + shifted_lines, n + u, p + 2, n + u // 2

        # Only right child.
        if self.left is None:
            lines, n, p, x = self.right._display_aux()
            s = '%s' % self.value
            u = len(s)
            first_line = s + x * '_' + (n - x) * ' '
            second_line = (u + x) * ' ' + '\\' + (n - x - 1) * ' '
            shifted_lines = [u * ' ' + line for line in lines]
            return [first_line, second_line] + shifted_lines, n + u, p + 2, u // 2

        # Two children.
        left, n, p, x = self.left._display_aux()
        right, m, q, y = self.right._display_aux()
        s = '%s' % self.value
        u = len(s)
        first_line = (x + 1) * ' ' + (n - x - 1) * '_' + s + y * '_' + (m - y) * ' '
        second_line = x * ' ' + '/' + (n - x - 1 + u + y) * ' ' + '\\' + (m - y - 1) * ' '
        if p < q:
            left += [n * ' '] * (q - p)
        elif q < p:
            right += [m * ' '] * (p - q)
        zipped_lines = zip(left, right)
        lines = [first_line, second_line] + [a + u * ' ' + b for a, b in zipped_lines]
        return lines, n + m + u, max(p, q) + 2, n + u // 2

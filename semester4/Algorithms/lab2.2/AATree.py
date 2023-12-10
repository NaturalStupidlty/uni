def _nodes_simple_comparison(v1, v2):
    """ Sorting function by default """
    if v1 == v2:
        return 0
    else:
        return -1 if v1 < v2 else 1


def make_compare_function_by_key(key):
    """ Takes a key extraction function and makes comparison function """
    return lambda v1, v2: _nodes_simple_comparison(key(v1), key(v2))


class _AATreeNode:
    """ Represents tree node """

    def __init__(self, val, parent, direction=None):
        self.level = self.len = 1
        self.left = self.right = None
        self.val = val
        self.is_array = False
        self.parent = parent
        self.direction = direction

    def getval(self):
        return self.val if not self.is_array else self.val[0]

    def addval(self, val):
        if self.is_array:
            self.val.append(val)
        else:
            self.val = [self.val, val]
            self.is_array = True
        self.len += 1

    def drop_value(self, val, all_copies):
        """ This method is used only if AATree has 'remove' method """
        if self.is_array:
            i = 0
            while i < self.len:
                if val == self.val[i]:
                    self.len -= 1
                    self.val = self.val[0: i] + self.val[i + 1:]
                    if not all_copies:
                        break
        else:
            if val == self.val:
                self.len = 0


class AATree:
    """ Self-balancing binary search tree, AA-tree form.
    https://en.wikipedia.org/wiki/AA_tree """

    def __init__(self, comparison_func=_nodes_simple_comparison, source=None):
        """ Constructor. Parameters:
        comparison_func - function (or lambda) that receives 2 parameters
          and returns -1 if first 'less' then second, 1 if 'greater' and
          0 if parameters considered as 'equal'. If not specified, default
          comparison used (in such case stored objects must implement '<'
          and '==' operations).
        source - iterable object. Convenient for immediate initialization."""
        self.root = None
        self.comp_f = comparison_func
        self._len = 0
        if source is not None:
            self.insert_from(source)

    def __len__(self):
        return self._len

    def insert(self, val):
        """ Inserts value into the tree. """
        self.root = self._insert_into_node(self.root, val, None)

    def insert_from(self, source):
        """ Inserts all values from iterable source. """
        for val in source:
            self.root = self._insert_into_node(self.root, val, None)

    @staticmethod
    def _skew(node):
        if node is None or node.left is None:
            return node
        elif node.left.level == node.level:
            L = node.left
            node.left = L.right
            if L.right:
                L.right.parent = node
                L.right.direction = 'L'
            L.right = node
            L.parent = node.parent
            L.direction = node.direction
            node.parent = L
            node.direction = 'R'
            return L
        else:
            return node

    @staticmethod
    def _split(node):
        if node is None or node.right is None or node.right.right is None:
            return node
        elif node.level == node.right.right.level:
            R = node.right
            node.right = R.left
            if R.left:
                R.left.parent = node
                R.left.direction = 'R'
            R.left = node
            R.parent = node.parent
            R.direction = node.direction
            node.parent = R
            node.direction = 'L'
            R.level += 1
            return R
        else:
            return node

    def _insert_into_node(self, node, val, parent, direction=None):
        if node is None:
            self._len += 1
            return _AATreeNode(val, parent, direction)
        else:
            cmp = self.comp_f(val, node.getval())
            if cmp < 0:  # val < node.getval()
                node.left = self._insert_into_node(node.left, val, node, 'L')
            elif cmp > 0:  # val > node.getval()
                node.right = self._insert_into_node(node.right, val, node, 'R')
            else:  # val == node.getval()
                self._len += 1
                node.addval(val)
                return node
            node = self._skew(node)
            node = self._split(node)
            return node

    def forward_from(self, start=None, inclusive=True,
                     stop=None, stop_incl=False):
        """ Creates and returns generator object which can be used for
          tree traversal in 'forward' direction. Parameters:
        start - starting value. If not specified, tree will be traversed
          from minimal value.
        inclusive - boolean - include or not values that 'equal' to 'start'.
          True (means include) by default.
        stop - value that stops iteration. If not specified, tree will be
          traversed to the end.
        stop_incl - boolean - include or not values that 'equal' to 'stop'.

        Default values for 'start' and 'stop' (True for 'inclusive' and False
        for 'stop_incl' respectively) are reminds behavior of 'start' and
        'stop' parameters of 'range' object."""
        node = self.root
        curr = None
        # cumbersome traversal because tree can be rebalanced during iteration
        while node:
            cmp = -1 if start is None else self.comp_f(start, node.getval())
            if cmp == 0:
                if inclusive:
                    curr = node
                    node = None
                else:
                    node = node.right
            elif cmp < 0:
                curr = node
                node = node.left
            else:
                node = node.right
        while curr:
            if curr.len > 0:
                if stop is not None:
                    cmp = self.comp_f(curr.getval(), stop)
                    if cmp > 0 or cmp == 0 and not stop_incl:
                        return
                if curr.is_array:
                    i = 0  # 'for' is not used because of possible update of curr.val
                    while i < curr.len:
                        yield curr.val[i]
                        i += 1
                else:
                    yield curr.val
            # step forward
            if curr.right:
                curr = curr.right
                while curr.left:
                    curr = curr.left
            else:
                new_curr = curr.parent
                while new_curr and curr.direction == 'R':
                    curr = new_curr
                    new_curr = curr.parent
                curr = new_curr

    def backward_from(self, start=None, inclusive=True,
                      stop=None, stop_incl=False):
        """ Creates and returns generator object which can be used for
          tree traversal in 'backward' direction. Parameters:
        start - starting value. If not specified, tree will be traversed
          from maximal value.
        inclusive - boolean - include or not values that 'equal' to 'start'.
          True (means include) by default.
        stop - value that stops iteration. If not specified, tree will be
          traversed to the end.
        stop_incl - boolean - include or not values that 'equal' to 'stop'."""
        node = self.root
        curr = None
        while node:
            cmp = 1 if start is None else self.comp_f(start, node.getval())
            if cmp == 0:
                if inclusive:
                    curr = node
                    node = None
                else:
                    node = node.left
            elif cmp > 0:
                curr = node
                node = node.right
            else:
                node = node.left
        while curr:
            if curr.len > 0:
                if stop is not None:
                    cmp = self.comp_f(curr.getval(), stop)
                    if cmp < 0 or cmp == 0 and not stop_incl:
                        return
                if curr.is_array:
                    i = 0
                    while i < curr.len:
                        yield curr.val[i]
                        i += 1
                else:
                    yield curr.val
            # step backward
            if curr.left:
                curr = curr.left
                while curr.right:
                    curr = curr.right
            else:
                new_curr = curr.parent
                while new_curr and curr.direction == 'L':
                    curr = new_curr
                    new_curr = curr.parent
                curr = new_curr

    def min(self, limit=None, inclusive=True):
        """ Returns minimal value that is not less (if 'inclusive'
        parameter is True) or greater (inclusive=False) than
        specified limit. """
        for val in self.forward_from(limit, inclusive):
            return val
        return None

    def max(self, limit=None, inclusive=True):
        """ Returns maximal value that is not greater (if 'inclusive'
        parameter is True) or less (inclusive=False) than specified
        limit. """
        for val in self.backward_from(limit, inclusive):
            return val
        return None

    def nodes_list(self):
        """ Returns list of _AATreeNode objects. Could be useful
        in some cases."""
        return self._nodes_list(self.root)

    def _nodes_list(self, node):
        if not node:
            return []
        else:
            return self._nodes_list(node.left) + [node] \
                   + self._nodes_list(node.right)

    # --------- If you don't need 'remove', finish copy-paste here ---------

    def remove(self, val, all_copies=False):
        """ Removes value from the tree. Parameters:
        val - value to be removed
        all_copies - boolean - suggests remove all the exact copies of
          specified 'val'. """
        if val is not None:
            self.root = self._delete(val, self.root, all_copies)

    def _delete(self, val, node, all_copies):
        if node is None:
            return None
        cmp = self.comp_f(val, node.getval())
        if cmp > 0:
            node.right = self._delete(val, node.right, all_copies)
        elif cmp < 0:
            node.left = self._delete(val, node.left, all_copies)
        else:
            node_len_before_deletion = node.len
            node.drop_value(val, all_copies)
            self._len -= node_len_before_deletion - node.len
            if node.len == 0:
                if node.left is None and node.right is None:
                    return None
                elif node.left is None:  # node.right exists
                    NN = node.right
                    while NN.left:
                        NN = NN.left
                    if NN != node.right:
                        if NN.right:
                            NN.right.parent = NN.parent
                            NN.right.direction = 'L'
                        NN.parent.left = NN.right
                        RN = NN.parent
                        while RN != node:
                            self._decrease_level(RN)
                            RN = RN.parent
                        NN.right = node.right
                        NN.right.parent = NN
                    NN.parent = node.parent
                    NN.direction = node.direction
                    NN.level = node.level
                    node.right = NN
                    node = NN
                else:  # node.left exists and node.right maybe too
                    PN = node.left
                    while PN.right:
                        PN = PN.right
                    if PN != node.left:
                        if PN.left:
                            PN.left.parent = PN.parent
                            PN.left.direction = 'R'
                        PN.parent.right = PN.left
                        RN = PN.parent
                        while RN != node:
                            self._decrease_level(RN)
                            RN = RN.parent
                        PN.left = node.left
                        PN.left.parent = PN
                    PN.parent = node.parent
                    PN.direction = node.direction
                    PN.level = node.level
                    PN.right = node.right
                    if PN.right:
                        PN.right.parent = PN
                    node.left = PN
                    node = PN
        self._decrease_level(node)
        return node

    @staticmethod
    def _decrease_level(node):
        should_be = max(node.left.level if node.left else 0,
                        node.right.level if node.right else 0) + 1
        if should_be < node.level:
            node.level = should_be
            if should_be < (node.right.level if node.right else 0):
                node.right.level = should_be


if __name__ == "__main__":
    print()

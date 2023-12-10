# Testing runtimes of different binary search tree construction algorithms

import time
import resource

# Complex numbers
from Complex import Complex

# Knuth's n^2 tree
from OptimalBST import find_optimal_tree_ordering as knuth_find
from OptimalBST import construct_tree_inline as knuth_build
from generate_test import generate_probs


def test(data=None):
    if data is None:
        data = []
        for i in range(10):
            data.append(Complex(5, 5, True))

    alphas, betas, beta_values = generate_probs(data)
    corpus_repeats = 2

    print("OPTIMAL KNUTH")
    start = time.time()
    exp, root = knuth_find(betas, alphas, len(betas))
    print(alphas, betas, beta_values)
    print(exp, root)
    Knuth_tree = knuth_build(root, beta_values)
    end = time.time()
    cons_time = end - start
    Knuth_tree.display()

    depths = []
    start = time.time()
    for x in range(corpus_repeats):
        for k in data:
            depths.append(Knuth_tree.find(k)[1])
    end = time.time()
    print("BUILD TIME:", cons_time,
          "AVG SEARCH TIME:", (end - start) / (len(data) * corpus_repeats),
          "AVG DEPTH:", float(sum(depths)) / len(depths))
    print("\nMemory:", float(resource.getrusage(resource.RUSAGE_SELF).ru_maxrss) / 1000000, "megabytes used")


test_data = [Complex(1, 0), Complex(1, 0), Complex(2, 0), Complex(2, 0),
             Complex(3, 0), Complex(3, 0), Complex(4, 0), Complex(5, 0)]
test(test_data)

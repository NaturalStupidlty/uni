"""
Laboratory work "Construction of quadrature formulas". Implement the solution using Python 3.0

1. Construct a quadrature formula of interpolation type with a weighting factor of 1.0 based on the Lagrange polynomial for 5 equidistant nodes in the interval [2; 6].
2. Determine the algebraic degree of accuracy of the constructed formula.
3. Determine the estimate of the residual term.

Be very attentive to details. Think step by step, according the mathematical formulas
"""
import math
import numpy as np

# Function to generate equidistant nodes
def equidistant_nodes(a, b, n):
    return np.linspace(a, b, n)

# Function to calculate Lagrange basis polynomials
def lagrange_basis(x, nodes, j):
    n = len(nodes)
    basis = 1.0
    for m in range(n):
        if m != j:
            basis *= (x - nodes[m]) / (nodes[j] - nodes[m])
    return basis

# Function to construct quadrature formula using Lagrange polynomial
def quadrature_formula(nodes, func):
    n = len(nodes)
    integral = 0.0
    for j in range(n):
        integral += func(nodes[j]) * lagrange_basis(nodes[j], nodes, j)
    return integral

# Given function to integrate
def f(x):
    return x**3 - 2*x + 1

# Step 1: Generate equidistant nodes
a = 2
b = 6
n = 5
nodes = equidistant_nodes(a, b, n)

# Step 2: Construct quadrature formula
integral_approximation = quadrature_formula(nodes, f)
print("Approximation of the integral:", integral_approximation)

# Step 3: Determine algebraic degree of accuracy
# For an interpolation type formula with n nodes, the degree of accuracy is 2n - 1
degree_of_accuracy = 2 * n - 1
print("Algebraic degree of accuracy:", degree_of_accuracy)

# Step 4: Determine estimate of the residual term
# The residual term estimation formula for Lagrange interpolation is h^(n+1) * f^(n+1)(zeta) / (n+1)!
# where h is the step size (here, (b-a)/n) and zeta is in the interval [a, b]
h = (b - a) / n
zeta = np.random.uniform(a, b)  # Randomly choosing zeta in the interval [a, b]
residual_estimate = (h**(n+1)) * abs(math.factorial(n+1) * f(zeta)) / (n+1)
print("Estimate of the residual term:", residual_estimate)

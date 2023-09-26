from polynomial import Polynomial
import math
from typing import Tuple
from equation_solver import EquationSolver
from relaxation import Relaxation
from modified_newton import ModifiedNewton
from fixed_point_iteration import FixedPointIteration


def interactive_test(solver: EquationSolver,
                     equation: Polynomial,
                     default_interval: Tuple[float, float],
                     default_accuracy: float = 1e-3):
    interval = input("Enter the interval (e.g., 0,1): or press enter to skip:")
    interval = tuple(map(float, interval.split(","))) if interval else default_interval

    desired_accuracy = input("Enter the desired accuracy (e.g., 1e-3) or press enter to skip: ")
    desired_accuracy = float(desired_accuracy) if desired_accuracy else default_accuracy

    solution = solver(interval, equation)
    print(f"Solution found: {solution:.{-int(math.log10(desired_accuracy))}} (with accuracy {desired_accuracy})")


if __name__ == "__main__":
    # x^3 + 2x^2 - x - 2
    relaxation = Relaxation(config={"accuracy": 1e-3})
    interactive_test(solver=relaxation,
                     equation=Polynomial([-2, -1, 2, 1]),
                     default_interval=(-1.5, -0.5),
                     default_accuracy=1e-3)

    # x^3 - 2x^2 - x + 2
    modified_newton = ModifiedNewton(config={"accuracy": 1e-3})
    interactive_test(solver=modified_newton,
                     equation=Polynomial([2, -1, -2, 1]),
                     default_interval=(0.5, 1.556),
                     default_accuracy=1e-3)

    # x^3 - 4x^2 + x + 6
    fixed_point_iteration = FixedPointIteration(config={"function": lambda x: 1e-2, "accuracy": 1e-3})
    interactive_test(solver=fixed_point_iteration,
                     equation=Polynomial([6, 1, -4, 1]),
                     default_interval=(1.3, 2.7),
                     default_accuracy=1e-3)

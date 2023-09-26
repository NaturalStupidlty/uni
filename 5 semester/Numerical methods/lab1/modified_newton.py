from typing import Tuple

from polynomial import Polynomial
from equation_solver import EquationSolver


class ModifiedNewton(EquationSolver):
    def __init__(self, config: dict = None):
        super().__init__("modified_newton", config)

    def __call__(self, interval: Tuple, equation: Polynomial):
        super().__call__(interval, equation)
        initial_guess_derivative = equation.derivative().evaluate(self.config["initial_guess"])

        for iteration in range(0, self.config["max_iterations"], 1):
            previous_result = self.result
            self.result = previous_result - equation.evaluate(previous_result) / initial_guess_derivative

            print(f"{iteration}\t{self.result:.{self.decimal_places}f}\t{equation.evaluate(self.result):.{self.decimal_places}f}")

            if abs(self.result - previous_result) < self.config["accuracy"]:
                break

        return self.result

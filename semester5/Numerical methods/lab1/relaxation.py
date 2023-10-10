from typing import Tuple

from polynomial import Polynomial
from equation_solver import EquationSolver


class Relaxation(EquationSolver):
    def __init__(self, config: dict = None):
        super().__init__("relaxation", config)

    def __call__(self, interval: Tuple[float, float], equation: Polynomial):
        super().__call__(interval, equation)
        relaxation_factor = 1 / 2
        for iteration in range(0, self.config["max_iterations"], 1):
            previous_result = self.result
            self.result = self.result - relaxation_factor * equation.evaluate(self.result)

            print(f"{iteration}\t{self.result:.{self.decimal_places}f}\t{equation.evaluate(self.result):.{self.decimal_places}f}")

            if abs(self.result - previous_result) < self.config["accuracy"]:
                break

        return self.result

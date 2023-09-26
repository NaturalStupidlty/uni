import random
import math
from typing import Tuple

from polynomial import Polynomial


class EquationSolver:
    def __init__(self, method: str, config=None):
        if config is None:
            config = {}
        self.method = method
        if method == "relaxation":
            initial_config = {
                "accuracy": 1e-22,
                "initial_guess": None,
            }
        elif method == "modified_newton":
            initial_config = {
                "accuracy": 1e-22,
                "initial_guess": None,
            }
        elif method == "fixed_point_iteration":
            initial_config = {
                "function": lambda x: 1e-2,
                "accuracy": 1e-22,
                "initial_guess": None,
            }
        else:
            raise NotImplemented("Invalid method")
        self.config = {**initial_config, **config}
        self.equation = None

    def __call__(self, interval: Tuple[float, float], equation: Polynomial):
        self.equation = equation
        self.interval = interval
        assert self.check_interval_for_roots(interval), "Invalid interval: no roots"
        assert self.check_if_root_is_single(interval), "Invalid interval: multiple roots"

        self.config["max_iterations"] = self.approximate_max_iterations(interval)
        if self.config["initial_guess"] is None:
            self.config["initial_guess"] = self.get_random_initial_guess(interval)

        self.result = self.config["initial_guess"]
        self.decimal_places = -int(math.log10(self.config["accuracy"]))
        print(f"Solving equation: {equation} with method {self.method} and accuracy {self.config['accuracy']}")
        print(f"Interval: {interval}")
        print(f"Initial guess: {self.result:.{self.decimal_places}f}")
        print("Step\tApproximation\tFunction Value")

    def check_interval_for_roots(self, interval: Tuple[float, float]) -> bool:
        return self.equation.evaluate(interval[0]) * self.equation.evaluate(interval[1]) < 0

    def check_if_root_is_single(self, interval: Tuple[float, float]) -> bool:
        if self.equation.evaluate(interval[0]) * self.equation.evaluate(interval[1]) < 0:
            return True

        critical_point_count = 0

        for x in interval:
            if abs(self.equation.derivative().evaluate(x)) < self.config["accuracy"]:
                critical_point_count += 1
                if critical_point_count > 1:
                    return False

        return critical_point_count == 1

    def approximate_max_iterations(self, interval: Tuple[float, float]) -> int:
        return int(math.log2((interval[1] - interval[0]) / self.config["accuracy"])) + 1

    @staticmethod
    def get_random_initial_guess(interval: Tuple[float, float]) -> float:
        return random.uniform(interval[0], interval[1])

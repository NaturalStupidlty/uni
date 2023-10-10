class Polynomial:
    def __init__(self, coefficients: list):
        if not all(isinstance(coeff, (int, float)) for coeff in coefficients):
            raise ValueError("Coefficients must be numerical values")
        self.coefficients = coefficients

    def evaluate(self, x):
        result = 0
        for i, coefficient in enumerate(self.coefficients):
            result += coefficient * (x ** i)
        return result

    def derivative(self):
        derivative_coefficients = [i * coefficient for i, coefficient in enumerate(self.coefficients)][1:]
        return Polynomial(derivative_coefficients)

    def __str__(self):
        terms = []
        for i, coefficient in enumerate(self.coefficients):
            if coefficient == 0:
                continue
            if i == 0:
                term = str(coefficient)
            elif i == 1:
                term = f"{coefficient}x"
            else:
                term = f"{coefficient}x^{i}"
            if coefficient < 0:
                term = "-" + term[1:]
            terms.append(term)
        return " + ".join(terms) if terms else "0"

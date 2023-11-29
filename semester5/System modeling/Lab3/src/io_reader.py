import numpy as np


def read(filename):
    try:
        with open(filename, 'r') as file:
            lines = file.readlines()
            rows = len(lines)
            if rows != 6:
                raise ValueError("The file should contain 6 rows.")

            data = []

            for line in lines:
                values = line.strip().split()
                row_data = [float(value) for value in values]
                data.append(row_data)

            y = np.array(data).T
            return y
    except FileNotFoundError:
        print(f"File '{filename}' not found.")
        return None
    except Exception as e:
        print(f"An error occurred: {e}")
        return None

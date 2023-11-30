from PIL import Image


def read_image(filename):
    try:
        with Image.open(filename) as img:
            img = img.convert("L")
            pixel_matrix = list(img.getdata())
            width, height = img.size
            pixel_matrix = [pixel_matrix[i * width:(i + 1) * width] for i in range(height)]
            return pixel_matrix
    except Exception as e:
        print(f"Error Reading image: {e}")
        return None


def write_image(filename, matrix):
    try:
        img = Image.new('L', (len(matrix[0]), len(matrix)))
        img.putdata([pixel for row in matrix for pixel in row])
        img.save(filename)
    except Exception as e:
        print(f"Error Writing image: {e}")

import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
from scipy.ndimage import gaussian_filter1d

def convolve2d(image, kernel):
    """
    Apply a 2D convolution operation using the given kernel on the image.
    The kernel is flipped to perform convolution (as opposed to correlation).
    """
    kernel = np.flipud(np.fliplr(kernel))
    m, n = kernel.shape
    height, width = image.shape
    pad_h, pad_w = m // 2, n // 2
    padded_image = np.pad(image, ((pad_h, pad_h), (pad_w, pad_w)), mode='constant')
    output = np.zeros_like(image, dtype=float)

    for i in range(height):
        for j in range(width):
            region = padded_image[i:i + m, j:j + n]
            output[i, j] = np.sum(region * kernel)
    return output


def generate_sobel_kernels(size=3):
    """
    Generate Sobel operator kernels for edge detection.
    Parameters:
      size: int
          Must be an odd number; currently supports 3 or 5.
    Returns:
      (sobel_x, sobel_y): tuple of numpy arrays
          Sobel kernels in the x and y directions.
    """
    if size == 3:
        derivative = np.array([-1, 0, 1])
        smoothing = np.array([1, 2, 1])
    elif size == 5:
        derivative = np.array([-2, -1, 0, 1, 2])
        smoothing = np.array([1, 4, 6, 4, 1])
    else:
        raise ValueError("Only 3x3 and 5x5 Sobel kernels are supported in this example.")

    sobel_x = np.outer(smoothing, derivative)  # smoothing in rows, derivative in columns
    sobel_y = np.outer(derivative, smoothing)  # derivative in rows, smoothing in columns
    return sobel_x, sobel_y


def apply_sobel_operator(image, size=3):
    """
    Apply a Sobel operator of a given size to the input image.
    Parameters:
      image: numpy array (grayscale)
      size: int (3 or 5)
    Returns:
      gradient_magnitude: numpy array (uint8)
    """
    sobel_x, sobel_y = generate_sobel_kernels(size=size)
    grad_x = convolve2d(image, sobel_x)
    grad_y = convolve2d(image, sobel_y)

    gradient_magnitude = np.sqrt(grad_x ** 2 + grad_y ** 2)
    # Normalize to 0-255
    gradient_magnitude = (gradient_magnitude / gradient_magnitude.max()) * 255
    return gradient_magnitude.astype(np.uint8)


def main():
    # 1. Load and convert the image to grayscale (if not already)
    img = Image.open('cameraman.tif').convert('L')
    img_array = np.array(img)

    # 2. Apply the 3x3 and 5x5 Sobel operators
    edges_3x3 = apply_sobel_operator(img_array, size=3)
    edges_5x5 = apply_sobel_operator(img_array, size=5)

    # 3. Compute the histogram of the original image
    hist, bin_edges = np.histogram(img_array, bins=256, range=(0, 256))

    # (Optional) Smooth the histogram to reduce noise
    hist_smooth = gaussian_filter1d(hist, sigma=1.0)

    # 4. Compute the second derivative of the smoothed histogram
    first_derivative = np.diff(hist_smooth, n=1)
    second_derivative = np.diff(hist_smooth, n=2)

    # 5. Find the inflection points where the second derivative changes sign
    inflection_points = []
    for i in range(1, len(second_derivative)):
        if (second_derivative[i-1] > 0 and second_derivative[i] < 0) or \
           (second_derivative[i-1] < 0 and second_derivative[i] > 0):
            # +1 because second_derivative is 2 elements shorter than hist
            inflection_points.append(i + 1)

    print("Inflection points:", inflection_points)

    # 6. Dissect the image using the inflection points as thresholds
    inflection_points = sorted(inflection_points)
    thresholds = [0] + inflection_points + [255]

    dissected_img = np.zeros_like(img_array, dtype=np.uint8)
    label = 1
    for t_low, t_high in zip(thresholds[:-1], thresholds[1:]):
        mask = (img_array >= t_low) & (img_array < t_high)
        # Scale each region to a unique gray level
        dissected_img[mask] = label * (255 // (len(thresholds) - 1))
        label += 1

    # 7. Plot everything
    fig, axes = plt.subplots(1, 3, figsize=(25, 5))

    # Original image
    axes[0].imshow(img_array, cmap='gray')
    axes[0].set_title('Original Image')
    axes[0].axis('off')

    # Sobel 3x3
    axes[1].imshow(edges_3x3, cmap='gray')
    axes[1].set_title('3x3 Sobel Edges')
    axes[1].axis('off')

    # Sobel 5x5
    axes[2].imshow(edges_5x5, cmap='gray')
    axes[2].set_title('5x5 Sobel Edges')
    axes[2].axis('off')

    plt.savefig('sobel.png')
    plt.tight_layout()
    plt.show()

    fig, axes = plt.subplots(1, 3, figsize=(25, 5))

    # Histogram & second derivative
    axes[0].plot(hist_smooth, label='Smoothed Hist')
    axes[0].plot(range(2, 256), second_derivative, label='2nd Derivative')
    # Plot inflection points
    axes[0].scatter(inflection_points, hist_smooth[inflection_points],
                    color='red', zorder=5, label='Inflection Points')
    axes[0].set_title('Histogram & 2nd Derivative')
    axes[0].set_xlabel('Intensity')
    axes[0].set_ylabel('Frequency')
    axes[0].legend()

    # Dissected image
    axes[1].imshow(dissected_img, cmap='gray')
    axes[1].set_title('Dissected Image')
    axes[1].axis('off')

    # Dissected + Sobel 3x3
    axes[2].imshow(dissected_img + edges_3x3, cmap='gray')
    axes[2].set_title('Dissected Image + Sobel 3x3')
    axes[2].axis('off')

    plt.savefig('histogram.png')
    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()

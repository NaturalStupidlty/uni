import numpy as np
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt


def discrete_fourier_transform(samples: np.ndarray) -> np.ndarray:
    """
    Compute the discrete Fourier transform of the samples.

    :param samples: observations
    :return: discrete Fourier transform of the samples
    """
    N = len(samples)
    n = np.arange(N)
    k = n.reshape((N, 1))
    e = np.exp(-2j * np.pi * k * n / N)
    return np.dot(e, samples)


def test_dft_implementation(samples: np.ndarray) -> None:
    """
    Test function to compare your DFT implementation with NumPy's FFT implementation.

    :param samples: observations
    :return: None
    """
    my_dft_result = discrete_fourier_transform(samples)
    numpy_fft_result = np.fft.fft(samples)

    max_absolute_error = np.max(np.abs(my_dft_result - numpy_fft_result))

    if max_absolute_error < 1e-6:
        print("DFT implementation matches NumPy's FFT.")
    else:
        print("DFT implementation does not match NumPy's FFT.")
        print(f"Maximum absolute error: {max_absolute_error}")


def find_frequencies_contribution(samples: np.ndarray, observation_interval: int = 5):
    """
    Find the frequencies' contribution of the samples. The frequencies' contribution is the frequency of the
    local maxima of the discrete Fourier transform of the samples.

    :param samples: observations
    :param observation_interval: observation interval
    :return:
    """
    num_samples = len(samples)
    time_step = 1 / observation_interval

    discrete_fourier_transform_modules = np.abs(discrete_fourier_transform(samples))
    plot_discrete_fourier_transform_modules(discrete_fourier_transform_modules,
                                            time_step,
                                            'discrete_fourier_transform_modules.png')

    local_maxima_indices = []
    for k in range(1, num_samples - 1):
        if (discrete_fourier_transform_modules[k] > discrete_fourier_transform_modules[k - 1]) and \
           (discrete_fourier_transform_modules[k] > discrete_fourier_transform_modules[k + 1]):
            local_maxima_indices.append(k)

    frequencies = [k * time_step for k in local_maxima_indices]

    return frequencies


def plot_discrete_fourier_transform_modules(discrete_fourier_transform_modules: np.ndarray,
                                            time_step: float, save_path: str) -> None:
    """
    Plot the discrete Fourier transform of the samples.

    :param discrete_fourier_transform_modules: discrete Fourier transform of the samples
    :param time_step: time step
    :param save_path: path to save the plot
    :return: None
    """
    num_samples = len(discrete_fourier_transform_modules)
    frequencies = [k * time_step for k in range(1, num_samples)]

    plt.plot(frequencies, discrete_fourier_transform_modules[1:num_samples])
    plt.xlabel('Частота (Hz)')
    plt.ylabel('Амплітуда')
    plt.savefig(save_path)


observations = np.loadtxt('f8.txt')
test_dft_implementation(observations)
print(find_frequencies_contribution(observations))

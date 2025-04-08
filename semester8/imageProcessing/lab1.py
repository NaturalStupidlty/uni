import argparse
import numpy as np
import plotly.graph_objects as go
from scipy import signal


def load_data(file_path):
	"""
	Load the observed data from a text file.

	Parameters:
		file_path (str): Path to the data file.

	Returns:
		np.ndarray: 1D array of observed data.
	"""
	return np.loadtxt(file_path)


def custom_butterworth_filter(x, T=0.01, fc=10, order=2):
	"""
	Apply a custom Butterworth low-pass filter using a bilinear transform
	of the analog Butterworth prototype.

	This implementation currently supports only a second-order filter.

	Parameters:
		x (np.ndarray): Input signal.
		T (float): Sampling interval in seconds.
		fc (float): Cutoff frequency in Hz.
		order (int): Filter order (only order=2 is supported).

	Returns:
		np.ndarray: Filtered signal.
	"""
	if order != 2:
		raise NotImplementedError("Only second-order custom Butterworth filter is implemented.")

	N = len(x)
	fs = 1 / T

	# Prewarp the cutoff frequency for the bilinear transform
	K = np.tan(np.pi * fc / fs)

	# For a second-order Butterworth filter the analog prototype is:
	#       ω_c^2
	# H(s)= ---------
	#      s^2 + √2 ω_c s + ω_c^2
	#
	# After applying the bilinear transform, the digital filter coefficients are:
	a0 = 1 + np.sqrt(2) * K + K ** 2
	b0 = K ** 2 / a0
	b1 = 2 * K ** 2 / a0
	b2 = K ** 2 / a0
	a1 = 2 * (K ** 2 - 1) / a0
	a2 = (1 - np.sqrt(2) * K + K ** 2) / a0

	y = np.zeros_like(x)
	y[0] = b0 * x[0]
	if N > 1:
		y[1] = b0 * x[1] + b1 * x[0] - a1 * y[0]
	for n in range(2, N):
		y[n] = (b0 * x[n] + b1 * x[n - 1] + b2 * x[n - 2] -
				a1 * y[n - 1] - a2 * y[n - 2])
	return y


def scipy_butterworth_filter(x, T=0.01, fc=10, order=2):
	"""
	Apply a SciPy Butterworth low-pass filter.

	Parameters:
		x (np.ndarray): Input signal.
		T (float): Sampling interval in seconds.
		fc (float): Cutoff frequency in Hz.
		order (int): Filter order.

	Returns:
		np.ndarray: Filtered signal.
	"""
	fs = 1 / T
	Wn = fc / (fs / 2)  # Normalize cutoff frequency by the Nyquist frequency
	b, a = signal.butter(order, Wn, btype='low', analog=False)
	return signal.lfilter(b, a, x)


def plot_signals(t, original, custom, scipy_filtered, title):
	"""
	Plot the original signal and the two filtered signals using Plotly.

	Parameters:
		t (np.ndarray): Time vector.
		original (np.ndarray): Original signal.
		custom (np.ndarray): Signal filtered by the custom Butterworth filter.
		scipy_filtered (np.ndarray): Signal filtered by the SciPy Butterworth filter.
		title (str): Title for the plot.
	"""
	fig = go.Figure()
	fig.add_trace(go.Scatter(x=t, y=original,
							 mode='lines',
							 name='Original Signal',
							 line=dict(color='blue')))
	fig.add_trace(go.Scatter(x=t, y=custom,
							 mode='lines',
							 name='Custom Butterworth Filter',
							 line=dict(color='red', dash='dash')))
	fig.add_trace(go.Scatter(x=t, y=scipy_filtered,
							 mode='lines',
							 name='SciPy Butterworth Filter',
							 line=dict(color='green', dash='dot')))
	fig.update_layout(title=title,
					  xaxis_title='Time (s)',
					  yaxis_title='Amplitude',
					  legend=dict(x=0, y=1),
					  template='plotly_white')
	fig.show()


def main():
	parser = argparse.ArgumentParser(
		description="Compare custom and SciPy Butterworth low-pass filters.")
	parser.add_argument("--file", type=str, default="lab1.txt",
						help="Path to the input data file")
	parser.add_argument("--T", type=float, default=0.01,
						help="Sampling interval in seconds")
	parser.add_argument("--fc", type=float, default=10,
						help="Cutoff frequency in Hz")
	parser.add_argument("--order", type=int, default=2,
						help="Order of the Butterworth filter")
	args = parser.parse_args()

	# Load the observed data
	x = load_data(args.file)
	N = len(x)
	t = np.arange(N) * args.T

	# Apply the custom and SciPy Butterworth filters
	y_custom = custom_butterworth_filter(x, T=args.T, fc=args.fc, order=args.order)
	y_scipy = scipy_butterworth_filter(x, T=args.T, fc=args.fc, order=args.order)

	# Plot the results
	plot_signals(t, x, y_custom, y_scipy,
				 title="Comparison: Custom vs SciPy Butterworth Low-pass Filters")


if __name__ == '__main__':
	main()

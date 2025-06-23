# Signal Processing

A repository containing my notes and projects for signal processing. The roadmap is as follows:

🔹 Week 1: Signals & Systems Basics
✅ Concepts to Learn:

- What are signals? (Continuous vs. Discrete)

- Basic signal operations (Shifting, Scaling, Reversal)

- Classification of signals (Periodic, Aperiodic, Deterministic, Random)

- Introduction to Linear Time-Invariant (LTI) Systems

- Convolution (concept, graphical understanding)

📚 Resources:

- Signals and Systems by Alan V. Oppenheim (Chapters 1-2)

- MIT OCW - Signals & Systems

- YouTube: Signals and Systems by NPTEL

👨‍💻 Hands-On Practice:

- Write a Python script (or MATLAB) to generate and plot basic signals (sinusoids, step, impulse)

- Perform basic signal operations (shifting, scaling) and visualize results


🔹 Week 2: Discrete-Time Signals & Sampling
✅ Concepts to Learn:

- Discrete-Time Signals vs. Continuous-Time Signals

- Nyquist Theorem & Sampling Rate

- Aliasing & How to Avoid It

- Quantization & Bit Depth in Digital Signals

- Practical considerations of ADC & DAC

📚 Resources:

- DSP First by McClellan, Schafer, Yoder (Chapters 2-3)

- Sampling Theorem Explanation

- YouTube: Aliasing & Sampling Theorem

👨‍💻 Hands-On Practice:

- Generate a sampled sine wave with different sampling rates

- Demonstrate aliasing by undersampling a signal and visualizing the distortion


🔹 Week 3: Fourier Series & Fourier Transform
✅ Concepts to Learn:

Introduction to Frequency Domain Representation

Fourier Series (for periodic signals)

Fourier Transform (for aperiodic signals)

Properties of Fourier Transform

Interpretation of Magnitude and Phase Spectrum

📚 Resources:

The Scientist and Engineer's Guide to DSP by Steven W. Smith (Chapters 8-9)

Fourier Transform Tutorial

MIT Fourier Series Lecture

👨‍💻 Hands-On Practice:

Compute the Fourier Series coefficients of a simple function

Implement Fourier Transform in Python using NumPy and visualize frequency components

🔹 Week 4: Discrete Fourier Transform (DFT) & Fast Fourier Transform (FFT)
✅ Concepts to Learn:

Discrete Fourier Transform (DFT)

Relationship Between DFT and Fourier Transform

Fast Fourier Transform (FFT) Algorithm

Windowing & Leakage in FFT

📚 Resources:

Understanding Digital Signal Processing by Richard G. Lyons (Chapters 4-5)

FFTW Library: FFTW.org

FFT Visualization

👨‍💻 Hands-On Practice:

Implement DFT from scratch and compare it with FFT from NumPy/Matlab

Apply FFT to an audio file and analyze its frequency spectrum

🔹 Week 5: Convolution & Linear Systems
✅ Concepts to Learn:

Convolution Integral (Continuous) vs. Convolution Sum (Discrete)

Impulse Response & LTI System Properties

Frequency Response of LTI Systems

Convolution Theorem

📚 Resources:

Signals and Systems by Oppenheim & Willsky (Chapter 3)

Convolution Theorem Explanation

YouTube: Convolution Operation

👨‍💻 Hands-On Practice:

Implement convolution of two signals in Python/MATLAB

Experiment with impulse responses and their effect on different input signals

🔹 Week 6: Z-Transform & Laplace Transform
✅ Concepts to Learn:

Z-Transform (Definition, ROC, Poles & Zeros)

Inverse Z-Transform (Partial Fraction Expansion, Long Division)

Difference Equations & System Stability

Laplace Transform & Its Relationship with Fourier Transform

📚 Resources:

Digital Signal Processing: Principles, Algorithms, and Applications by Proakis & Manolakis (Chapters 5-6)

MIT Z-Transform Lecture

👨‍💻 Hands-On Practice:

Compute Z-transform of basic sequences and analyze their pole-zero plots

Solve simple difference equations using Z-transform

🔹 Week 7: Probability & Random Signals
✅ Concepts to Learn:

Random Processes & White Noise

Autocorrelation & Cross-Correlation

Power Spectral Density (PSD)

Gaussian & Non-Gaussian Signals

📚 Resources:

Probability and Random Processes for Electrical and Computer Engineers by Gubner

Lecture Notes on Random Signals

👨‍💻 Hands-On Practice:

Generate white noise and analyze its power spectrum

Implement an autocorrelation function and compare it with FFT-based methods

🔹 Week 8: Practical Applications & Review
✅ Concepts to Learn:

Application of DSP in Audio & Speech Processing

DSP in Image Processing & Communications

Overview of DSP in Embedded Systems (FPGA, ARM)

📚 Resources:

Real-World DSP Applications

MIT DSP Applications Course

👨‍💻 Hands-On Practice:

Implement a simple noise removal filter for audio signals

Review and consolidate all previous concepts


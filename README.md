# Signal Processing

A repository containing my notes and projects for signal processing. The roadmap is as follows:

1. Phase 1: Mathematics and fundamentals of signal processing
2. Phase 2: DSP in C++ with a focus on algorithms and command line usage (CLI)
3. Phase 3: Advanced DSP in C++ with a focus on real-time implementation 

## Phase 1 : Math and Fundamentals

### **Week 1**: Signals & Systems Basics
Concepts to Learn:

- What are signals? (Continuous vs. Discrete)

- Basic signal operations (Shifting, Scaling, Reversal)

- Classification of signals (Periodic, Aperiodic, Deterministic, Random)

- Introduction to Linear Time-Invariant (LTI) Systems

- Convolution (concept, graphical understanding)

Resources:

- Signals and Systems by Alan V. Oppenheim (Chapters 1-2)

- MIT OCW - Signals & Systems

- YouTube: Signals and Systems by NPTEL

Hands-On Practice:

- Write a Python script (or MATLAB) to generate and plot basic signals (sinusoids, step, impulse)

- Perform basic signal operations (shifting, scaling) and visualize results


### **Week 2**: Discrete-Time Signals & Sampling
Concepts to Learn:

- Discrete-Time Signals vs. Continuous-Time Signals

- Nyquist Theorem & Sampling Rate

- Aliasing & How to Avoid It

- Quantization & Bit Depth in Digital Signals

- Practical considerations of ADC & DAC

Resources:

- DSP First by McClellan, Schafer, Yoder (Chapters 2-3)

- Sampling Theorem Explanation

- YouTube: Aliasing & Sampling Theorem

Hands-On Practice:

- Generate a sampled sine wave with different sampling rates

- Demonstrate aliasing by undersampling a signal and visualizing the distortion


### **Week 3**: Fourier Series & Fourier Transform
Concepts to Learn:

- Introduction to Frequency Domain Representation

- Fourier Series (for periodic signals)

- Fourier Transform (for aperiodic signals)

- Properties of Fourier Transform

- Interpretation of Magnitude and Phase Spectrum

Resources:

- The Scientist and Engineer's Guide to DSP by Steven W. Smith (Chapters 8-9)

- Fourier Transform Tutorial

- MIT Fourier Series Lecture

Hands-On Practice:

- Compute the Fourier Series coefficients of a simple function

- Implement Fourier Transform in Python using NumPy and visualize frequency components

### **Week 4**: Discrete Fourier Transform (DFT) & Fast Fourier Transform (FFT)
Concepts to Learn:

- Discrete Fourier Transform (DFT)

- Relationship Between DFT and Fourier Transform

- Fast Fourier Transform (FFT) Algorithm

- Windowing & Leakage in FFT

Resources:

- Understanding Digital Signal Processing by Richard G. Lyons (Chapters 4-5)

- FFTW Library: FFTW.org

- FFT Visualization

Hands-On Practice:

- Implement DFT from scratch and compare it with FFT from NumPy/Matlab

- Apply FFT to an audio file and analyze its frequency spectrum

### **Week 5**: Convolution & Linear Systems
Concepts to Learn:

- Convolution Integral (Continuous) vs. Convolution Sum (Discrete)

- Impulse Response & LTI System Properties

- Frequency Response of LTI Systems

- Convolution Theorem

Resources:

- Signals and Systems by Oppenheim & Willsky (Chapter 3)

- Convolution Theorem Explanation

- YouTube: Convolution Operation

Hands-On Practice:

- Implement convolution of two signals in Python/MATLAB

- Experiment with impulse responses and their effect on different input signals

### **Week 6**: Z-Transform & Laplace Transform
Concepts to Learn:

- Z-Transform (Definition, ROC, Poles & Zeros)

- Inverse Z-Transform (Partial Fraction Expansion, Long Division)

- Difference Equations & System Stability

- Laplace Transform & Its Relationship with Fourier Transform

Resources:

- Digital Signal Processing: Principles, Algorithms, and Applications by Proakis & Manolakis (Chapters 5-6)

- MIT Z-Transform Lecture

Hands-On Practice:

- Compute Z-transform of basic sequences and analyze their pole-zero plots

- Solve simple difference equations using Z-transform

### **Week 7**: Probability & Random Signals
Concepts to Learn:

- Random Processes & White Noise

- Autocorrelation & Cross-Correlation

- Power Spectral Density (PSD)

- Gaussian & Non-Gaussian Signals

Resources:

- Probability and Random Processes for Electrical and Computer Engineers by Gubner

- Lecture Notes on Random Signals

Hands-On Practice:

- Generate white noise and analyze its power spectrum

- Implement an autocorrelation function and compare it with FFT-based methods

### **Week 8**: Practical Applications & Review
Concepts to Learn:

- Application of DSP in Audio & Speech Processing

- DSP in Image Processing & Communications

- Overview of DSP in Embedded Systems (FPGA, ARM)

Resources:

- Real-World DSP Applications

- MIT DSP Applications Course

Hands-On Practice:

- Implement a simple noise removal filter for audio signals

- Review and consolidate all previous concepts

## Phase 2 : DSP Algorithms in C++

### **Week 1**: Setting Up Your C++ DSP Environment
Concepts to Learn:

- Setting up a C++ development environment (GCC, Clang, CMake)

- Introduction to Eigen and Armadillo for linear algebra

- Using FFTW for fast Fourier transforms

- Handling complex numbers in C++ (std::complex)

- Basics of file I/O for signal processing

Resources:

- Eigen Library Documentation

- Armadillo C++ Library

- FFTW Library

Hands-On Practice:

- Install Eigen, FFTW, and Armadillo on your system

- Read a .wav file and extract the raw audio data

- Perform basic vector and matrix operations in Eigen

### **Week 2**: Discrete-Time Signals in C++
Concepts to Learn:

- Representing discrete-time signals in C++ arrays or vectors

- Generating sinusoids, square waves, and impulses

- Implementing sampling & quantization

- Visualizing signals using Matplotlib C++ bindings

Resources:

- Numerical Recipes in C++ (Chapters on Signal Processing)

- Matplotlib for C++

Hands-On Practice:

- Generate and plot a sampled sine wave

- Implement a simple quantizer with different bit depths

- Simulate aliasing by undersampling a signal

### **Week 3**: Implementing the Fourier Transform
Concepts to Learn:

- Implementing Discrete Fourier Transform (DFT) from scratch

- Using FFTW to compute Fast Fourier Transform (FFT)

- Understanding Spectral Leakage & Windowing

- Visualizing frequency domain representations

Resources:

- FFTW Library Tutorial

- Understanding Digital Signal Processing by Richard G. Lyons (FFT Chapter)

Hands-On Practice:

- Implement DFT in C++ and compare it with FFTW’s output

- Apply FFT to a real-world audio signal

- Experiment with different windowing functions (Hamming, Hanning, Blackman)

### **Week 4**: Convolution and Filtering
Concepts to Learn:

- Implementing linear convolution in C++

- Fast convolution using FFT-based convolution

- Designing a simple moving average filter

- Introduction to Finite Impulse Response (FIR) Filters

Resources:

- Discrete-Time Signal Processing by Oppenheim & Schafer

- DSP-Related Convolution Explanation

Hands-On Practice:

- Implement convolution from scratch in C++

- Apply a moving average filter to smooth a noisy signal

- Use FFT to implement fast convolution

### **Week 5**: Digital Filter Design
Concepts to Learn:

- Designing Low-pass, High-pass, Band-pass FIR filters

- Windowing techniques for FIR filter design

- Introduction to Infinite Impulse Response (IIR) Filters

- Implementing Butterworth, Chebyshev filters

Resources:

- Digital Filters Design Handbook by Williams

- MIT FIR & IIR Filter Design

- GNU Octave Signal Processing Toolkit

Hands-On Practice:

- Design a low-pass FIR filter in C++ using windowing methods

- Implement an IIR Butterworth filter in C++

- Apply these filters to real-world audio signals

### **Week 6**: Real-Time DSP Processing
Concepts to Learn:

- Streaming and processing real-time audio data

- Introduction to PortAudio & RtAudio for real-time sound

- Optimizing DSP memory & performance

- Multi-threading in DSP processing (OpenMP, pthreads)

Resources:

- PortAudio Library

- RtAudio Library

Hands-On Practice:

- Capture real-time audio and process it in C++

- Apply a low-pass filter in real-time

- Implement multi-threaded processing to optimize DSP computations

### **Week 7**: Spectrograms & Advanced Analysis
Concepts to Learn:

- Short-Time Fourier Transform (STFT)

- Spectrogram generation & visualization

- Time-frequency analysis methods

Resources:

- Time-Frequency Signal Analysis by Boashash

- Spectrogram Algorithm

Hands-On Practice:

- Compute a spectrogram of an audio signal

- Implement STFT in C++

- Analyze real-world speech and music signals

### **Week 8**: Final Projects & Optimization
Concepts to Learn:

- Optimizing FFT & convolution algorithms

- Implementing DSP on GPUs (CUDA, OpenCL)

- Advanced filter design (Adaptive filters, Kalman filters)

- Exploring DSP in Embedded Systems

Resources:

- Real-Time Digital Signal Processing by Sen M. Kuo

- NVIDIA CUDA Tutorials

- ARM CMSIS-DSP Library

Final Projects:

- Build a real-time equalizer for audio processing

- Implement a speech enhancement algorithm

- Optimize FFT-based filtering on a GPU

## Phase 3: Advanced DSP & Real-Time Implementation

### Week 1: Real-Time Signal Processing & Optimization
✅ Concepts to Learn:

Real-time constraints in DSP

Low-latency signal processing techniques

Optimizing DSP code for speed (SIMD, vectorization)

Efficient memory management in DSP (cache-friendly algorithms)

📚 Resources:

Real-Time Digital Signal Processing by Sen M. Kuo

Intel SIMD Programming Guide

ARM Cortex DSP Optimizations

👨‍💻 Hands-On Practice:

Profile a DSP algorithm and reduce its execution time

Implement FFT with SIMD optimizations

Test low-latency filtering on real-time audio

### Week 2: Adaptive Filtering
✅ Concepts to Learn:

LMS & RLS algorithms

Adaptive noise cancellation

Real-time applications of adaptive filters

📚 Resources:

Adaptive Signal Processing by Haykin

LMS Algorithm Explanation

👨‍💻 Hands-On Practice:

Implement an LMS adaptive filter in C++

Use adaptive filtering for real-time noise cancellation

Compare LMS vs. RLS performance

### Week 3: Multi-Rate Signal Processing
✅ Concepts to Learn:

Downsampling & Upsampling

Polyphase decomposition

Decimation & Interpolation Filters

📚 Resources:

Multirate Digital Signal Processing by Crochiere & Rabiner

Polyphase Filtering Tutorial

👨‍💻 Hands-On Practice:

Implement a polyphase FIR filter

Design a resampling system for audio

### Week 4: Wavelet Transforms & Time-Frequency Analysis
✅ Concepts to Learn:

Continuous & Discrete Wavelet Transform (CWT, DWT)

Applications in image/audio processing

Choosing wavelet bases (Haar, Daubechies)

📚 Resources:

Wavelet Methods for Time Series Analysis by Percival & Walden

Wavelet Transform Explanation

👨‍💻 Hands-On Practice:

Implement DWT in C++

Use wavelets for denoising speech signals

### Week 5: Machine Learning for DSP
✅ Concepts to Learn:

Feature extraction from signals

Applying Neural Networks for DSP

DSP applications in speech & music analysis

📚 Resources:

Deep Learning for Signal Processing by Zhang & Wu

Google ML Audio Classification

👨‍💻 Hands-On Practice:

Train a neural network for speech recognition

Implement spectrogram-based ML feature extraction

### Week 6: Software-Defined Radio (SDR) & RF DSP
✅ Concepts to Learn:

Basics of SDR & Digital Modulation

Implementing DSP in GNURadio

RF filtering & signal demodulation

📚 Resources:

SDR for Engineers by Collins

GNURadio Tutorials

👨‍💻 Hands-On Practice:

Capture and process FM signals with SDR

Implement a real-time demodulator

### Week 7: Embedded DSP Programming
✅ Concepts to Learn:

DSP on ARM Cortex-M & TI DSP Processors

Fixed-Point vs. Floating-Point DSP

Real-time DSP on microcontrollers

📚 Resources:

ARM CMSIS-DSP Library Guide

TI C6000 DSP Programming Manual

👨‍💻 Hands-On Practice:

Implement a real-time FIR filter on an ARM board

Optimize DSP code for low-power applications

### Week 8: Final DSP Project
✅ Project Ideas:

Real-time speech enhancement system

Deep learning-based audio classification

Embedded DSP implementation of a noise cancellation filter

📚 Resources:

DSP Online Courses

👨‍💻 Final Submission:

Optimize your project for real-time performance

Test it in real-world noisy conditions

#include "math.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
#include <complex>

void impulse(std::vector<double>& out,int n, double A = 1.0) {
    if (n < 0 || n > out.size()) 
        throw std::out_of_range("Impulse index out of range");

    std::fill(out.begin(), out.end(), 0.0);
    out[n] = A;
}

void step(std::vector<double>& out,int n, double A = 1.0) {
    if (n < 0 || n > out.size()) 
        throw std::out_of_range("Step index out of range");

    std::fill(out.begin(), out.begin() + n, 0.0);
    std::fill(out.end() - n, out.end(),A);
}

std::vector<double> signal_generator(int length, std::function<double(int)> func) {
    std::vector<double> x(length);
    for (int n = 0; n < length; ++n)
    {
        x[n] = func(n);
    }
    return x;
}

std::vector<double> convolve(const std::vector<double>& signal, const std::vector<double>& impulse) {
    // Takes in input signal and manually convolves it with an impulse response. Returns a vector y of the convolved signal.
    int N = signal.size();
    int M = impulse.size();
    int y_length = N + M - 1;
    std::vector<double> y(y_length, 0.0);

    double response;
    int k_min, k_max;

    for (int i = 0; i < y_length; i++)
    {
        response = 0.0;
        k_min = std::max(0, i - (M-1));
        k_max = std::min(i, N - 1);
        for (int k = k_min; k < k_max+1; k++)
        {
            response += signal[k] * impulse[i-k];
        }
        y[i] = response;
    }
    return y;
}


std::vector<double> autocorrelation(const std::vector<double>& x) {
    size_t N = x.size();
    std::vector<double> R(N,0.0);

    for (size_t lag = 0; lag < N; ++lag)
    {
        double summation = 0.0;
        for (size_t n = 0; n < N - lag; ++n)
        {
            summation += x[n] * x[n + lag];
        }
        R[lag] = summation / (N - lag);
    }
    return R;
}

std::vector<double> crosscorrelation(const std::vector<double>& x, const std::vector<double>& y) {
    size_t N = std::min(x.size(),y.size());

    std::vector<double> C(N,0.0);

    for (size_t lag = 0; lag < N; ++lag)
    {
        double summation = 0.0;
        for (size_t n = 0; n < N - lag; ++n)
        {
            summation += x[n] * y[n + lag];
        }
        C[lag] = summation / (N - lag);
    }
    return C;
}

std::complex<double> dft_coeff(std::vector<double>& x, const int N, int k) {
    std::complex<double> c_k(0.0,0.0);
    std::complex<double> j(0.0,1.0);
    for (int n = 0; n < N; n++)
    {
        c_k += (1.0/static_cast<double>(N))*x[n]*std::exp(-j * (2.0*PI*n*k/N) );
    }
    return c_k;
}

std::vector<double> dft_freq(const int N, int T=1.0) {
    std::vector<double> fft_freq(N,0.0);
    for (int i = -N/2; i < N/2; i++)
    {
        fft_freq[i] = i/(N*T);
    }
    return fft_freq;
}

std::vector<double> dft_full(std::vector<double>& x, const int N, int k, int T = 1.0) {
    std::vector<double> freqs = dft_freq(N,T/N);
    std::vector<double> cks;
    for (int k = 0; k < N; k++)
    {
        cks.push_back((x,N,k));
    }
    return cks;
}
    
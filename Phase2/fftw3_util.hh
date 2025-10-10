#include "math.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
#include <complex>
#include <limits>
#include <fftw3.h>

//double PI = acos(-1);

std::vector<double> phase_spectrum_fftw(const fftw_complex* X,
                                   int N,
                                   bool unwrap = false,
                                   double eps = 1e-16) {
    std::vector<double> phase(N);

    for (int i = 0; i < N; i++) {
        double re = X[i][0];
        double im = X[i][1];
        double mag = std::sqrt(re*re + im*im);

        if (mag > eps)
            phase[i] = std::atan2(im, re);
        else
            phase[i] = std::numeric_limits<double>::quiet_NaN();
    }

    if (unwrap && N > 1) {
        for (int i = 1; i < N; i++) {
            if (std::isnan(phase[i]) || std::isnan(phase[i-1])) continue;

            double dp = phase[i] - phase[i-1];
            while (dp > M_PI)  dp -= 2*M_PI;
            while (dp < -M_PI) dp += 2*M_PI;
            phase[i] = phase[i-1] + dp;
        }
    }

    return phase;
}

std::vector<double> magnitude_spectrum_fftw(const fftw_complex* X, int N) {
    std::vector<double> magnitude(N);

    for (int i = 0; i < N; i++) {
        double re = X[i][0];
        double im = X[i][1];
        double mag = std::sqrt(re*re + im*im);
        magnitude[i] = mag;
    }
    return magnitude;
}
// demo.cpp — DSP examples with Eigen + FFTW
// Compile with:
// g++ -std=c++17 -O3 -I/path/to/eigen -lfftw3 -lm demo.cpp -o demo
#define _USE_MATH_DEFINES

#include <iostream>
#include <Eigen/Dense>
#include <fftw3.h>
#include <complex>
#include <cstring> // memcpy, memset
#include <cmath>
#include <fstream>

using namespace Eigen;

// Generate a test signal: sum of sines + noise
VectorXd generate_signal(int N, double fs) {
    VectorXd x(N);
    double f1 = 50.0, f2 = 120.0;
    for (int n=0; n<N; ++n) {
        double t = n/fs;
        x[n] = 0.7*sin(2*M_PI*f1*t) + 0.3*sin(2*M_PI*f2*t) + 0.05*std::rand()/RAND_MAX;
    }
    return x;
}

// Hamming window generator
VectorXd hamming(int N) {
    VectorXd w(N);
    for (int n=0; n<N; ++n)
        w[n] = 0.54 - 0.46*cos(2*M_PI*n/(N-1));
    return w;
}

// Frame signal into overlapping columns (window length win, hop size hop)
MatrixXd frame_signal(const VectorXd& x, int win, int hop) {
    int nFrames = 1 + (x.size() - win) / hop;
    MatrixXd frames(win, nFrames);
    for (int k=0; k<nFrames; ++k) {
        frames.col(k) = x.segment(k*hop, win);
    }
    return frames;
}

// Compute Welch PSD estimate (power spectral density)
VectorXd welch_psd(const VectorXd& x, int win, int hop, int nfft) {
    int nFrames = 1 + (x.size() - win) / hop;
    MatrixXd frames = frame_signal(x, win, hop);
    VectorXd w = hamming(win);
    frames = frames.array().colwise() * w.array();

    int nbins = nfft/2 + 1;
    VectorXd psd = VectorXd::Zero(nbins);

    // FFTW buffers and plan
    double* in = fftw_alloc_real(nfft);
    fftw_complex* out = fftw_alloc_complex(nbins);
    fftw_plan p = fftw_plan_dft_r2c_1d(nfft, in, out, FFTW_ESTIMATE);

    for (int k=0; k<nFrames; ++k) {
        std::memset(in, 0, sizeof(double)*nfft);
        std::memcpy(in, frames.col(k).data(), sizeof(double)*win);
        fftw_execute(p);
        Map<VectorXcd> X(reinterpret_cast<std::complex<double>*>(out), nbins);
        psd += X.cwiseAbs2().real();
    }
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);

    psd /= nFrames; // average

    // Normalize by window power (coherent gain)
    double win_power = w.squaredNorm();
    psd /= win_power;

    return psd;
}

// Simple FIR filter (direct convolution)
VectorXd conv_naive(const VectorXd& x, const VectorXd& h) {
    int n = x.size(), m = h.size();
    VectorXd y = VectorXd::Zero(n + m -1);
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            y[i+j] += x[i]*h[j];
    return y;
}

// Levinson-Durbin recursion to solve Yule-Walker for LPC coefficients
VectorXd levinson_durbin(const VectorXd& r, int p) {
    VectorXd a = VectorXd::Zero(p);
    VectorXd E(p+1);
    E(0) = r(0);

    for (int i=1; i<=p; ++i) {
        double acc = r(i);
        for (int j=1; j<i; ++j)
            acc += a(j-1)*r(i-j);
        double k = -acc / E(i-1);
        VectorXd anew = a;
        for (int j=1; j<i; ++j)
            anew(j-1) += k*a(i-j-1);
        anew(i-1) = k;
        a = anew;
        E(i) = E(i-1)*(1 - k*k);
    }
    return a;
}

int main() {
    constexpr int N = 2048;
    constexpr double fs = 1000; // sampling freq 1000 Hz

    std::cout << "Generating test signal...\n";
    VectorXd x = generate_signal(N, fs);

    std::cout << "Computing Welch PSD...\n";
    int win = 256, hop = 128, nfft = 512;
    VectorXd psd = welch_psd(x, win, hop, nfft);

    // Export PSD to file for gnuplot
    std::ofstream psd_file("psd_data.txt");
    if (psd_file.is_open()) {
        double freq_res = fs / nfft;
        for (int i = 0; i < psd.size(); ++i) {
            psd_file << i * freq_res << " " << psd[i] << "\n";
        }
        psd_file.close();
        std::cout << "PSD data saved to psd_data.txt\n";
    } else {
        std::cerr << "Failed to open psd_data.txt for writing.\n";
    }

    std::cout << "First 10 PSD values:\n";
    for (int i=0; i<10; ++i) {
        double freq = (fs/nfft)*i;
        std::cout << freq << " Hz: " << psd[i] << "\n";
    }

    std::cout << "Applying FIR smoothing filter...\n";
    VectorXd h(3);
    h << 0.25, 0.5, 0.25;
    VectorXd y = conv_naive(x, h);

    std::cout << "Computing autocorrelation for LPC...\n";
    int p = 10; // LPC order
    VectorXd r = VectorXd::Zero(p+1);
    for (int lag=0; lag<=p; ++lag) {
        r(lag) = x.head(N - lag).dot(x.segment(lag, N - lag));
    }

    VectorXd a = levinson_durbin(r, p);
    std::cout << "LPC coefficients:\n" << a.transpose() << "\n";

    std::cout << "Demo finished.\n";
    return 0;
}

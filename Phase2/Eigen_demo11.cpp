/*
This is a compact sketch combining previous pieces. (I omit error checks and full boilerplate to keep it short; you can paste into a single .cpp and add includes/main.)
*/

// sketch: welch_psd(x, win, hop, nfft) -> freq bins x PSD vector
// Steps: frame (MatrixXd), window, per-frame FFT, periodogram average.
#define _USE_MATH_DEFINES

#include <Eigen/Dense>
#include <fftw3.h>
#include <cmath>

using Eigen::VectorXd;
using Eigen::VectorXcd;
using Eigen::MatrixXd;
using Eigen::Map;


MatrixXd welch_psd(const VectorXd& x, int win, int hop, int nfft) {
    // frame
    int nFrames = 1 + (x.size() - win) / hop;
    MatrixXd frames(win, nFrames);
    for (int k=0; k<nFrames; ++k) frames.col(k) = x.segment(k*hop, win);

    VectorXd w = hamming(win);
    frames = frames.array().colwise() * w.array();

    int nbins = nfft/2 + 1;
    MatrixXd PSD = MatrixXd::Zero(nbins,1);

    // prepare FFTW buffers only ONCE
    double* in = fftw_alloc_real(nfft);
    fftw_complex* out = fftw_alloc_complex(nbins);
    fftw_plan p = fftw_plan_dft_r2c_1d(nfft, in, out, FFTW_ESTIMATE);

    for (int k = 0; k < nFrames; ++k)
    {
        // copy and zero pad
        std::memset(in, 0, sizeof(double)*nfft);
        std::memcpy(in, frames.col(k).data(), sizeof(double)*win);
        fftw_execute(p);
        //map output
        Map<VectorXcd> X(reinterpret_cast<std::complex<double>*>(out), nbins);
        PSD.col(0) += (X.cwiseAbs2()).real();
    }
    
    fftw_destroy_plan(p);
    fftw_free(in); fftw_free(out);
    PSD /= nFrames; // averaging step
    return PSD;
}

// apply window e.g. Hamming window
VectorXd hamming(int N) {
    VectorXd w(N);
    for (int n = 0; n < N; ++N)
    {
        w[n] = 0.54 - 0.46 * cos(2*M_PI*n/(N-1));
    }
    return w;
}
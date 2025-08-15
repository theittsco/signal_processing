/*
STFT is framing + windowing + FFT on frames. Use Eigen for the frames Matrix and fftw for per-frame FFTs. 

Below example: creating a framed matrix (each column is a windowed frame)
*/
#define _USE_MATH_DEFINES

#include <Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::VectorXd;

// frame signal x into columns with hop and win length
MatrixXd frame_signal(const VectorXd& x, int win, int hop) {
    int nFrames = 1 + (x.size() - win) / hop;
    MatrixXd frames(win, nFrames);
    for (int k = 0; k < nFrames; ++k)
    {
        frames.col(k) = x.segment(k*hop,win);
    }
    return frames;
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

// Then for each column call FFT (wrap the column via Map) and store magnitudes to build a spectrogram matrix. Vectorize where possible; but inner loop over frames with an FFT call is normal.
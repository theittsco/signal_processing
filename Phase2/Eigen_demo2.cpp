/*
Direct convolution (time domain) can be implemented with matrix multiplication via a Toeplitz matrix. For small kernels this is fine; for long signals use FFT convolution.

Direct convolution (naïve O(N*M)):
*/
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

VectorXd conv_naive(const VectorXd& x, const VectorXd& h) {
    int n = x.size(), m = h.size(); // x is input signal, h is system impulse response
    VectorXd y = VectorXd::Zero(n+m-1); // initializing output signal using DSP properties; output will be length n+m-1
    for (int i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            y[i+j] += x[i]*h[j]; // Just matrix multiplication by def
        }
    }
    return y;
}

// Toeplitz approach (matrix multiply — elegant for small sizes; useful for linear-algebra reasoning)

MatrixXd toeplitz_conv_matrix(const VectorXd& x, int m) {
    int n = x.size();
    MatrixXd T = MatrixXd::Zero(n+m-1,m);
    for (int col = 0; col < m; ++col)
    {
        T.block(col,col,n,1) = x;
    }
    // shift columns down
    for (int col = 0; col < m; ++col)
    {
        T.col(col).conservativeResize(n+m-1);
    }
    for (int col = 0; col < m; ++col)
    {
        T.col(col).segment(col, x.size()) = x;
    }
    return T;
    // usage y = T * h
}

//(Implementation note: for large signals this allocates large matrices — prefer FFT.)


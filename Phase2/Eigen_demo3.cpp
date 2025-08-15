/*
FFTW is the go-to FFT library. Use Eigen::Map to avoid copying.

Minimal example: real-input forward FFT (R2C) using FFTW and Eigen.
*/

#include <Eigen/Dense>
#include <fftw3.h>
#include <complex>

using Eigen::Map;
using Eigen::VectorXd;
using Eigen::VectorXcd;

int main(int argc, char const *argv[])
{
    int N = 1024;
    VectorXd x = VectorXd::Random(N);

    // create FFTW arrays
    double* in = fftw_alloc_real(N);
    fftw_complex* out = fftw_alloc_complex(N/2+1);

    // copy into FFTW input
    std::memcpy(in, x.data(), sizeof(double)*N);

    // plan and execute
    fftw_plan p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
    fftw_execute(p);

    // wrap output with Eigen (no copy)
    Map<VectorXcd> X(reinterpret_cast<std::complex<double>*>(out), N/2+1);

    // Do LinAlg on X
    VectorXd mag = X.cwiseAbs();

    // cleanup
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);
}

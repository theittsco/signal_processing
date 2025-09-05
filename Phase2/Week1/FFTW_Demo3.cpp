// FFT-based circular convolution of two signals 
#include <iostream>
#include <fftw3.h>
#include <vector>
#include <cstring>

int next_pow2(int n) {
    int p = 1;
    while (p<n)
    {
        p <<= 1;
    }
    return p;
}

int main(int argc, char const *argv[])
{
    std::vector<double> x = {1,2,3,4};
    std::vector<double> h = {1,0.5,0.25};

    int n = x.size(), m = h.size();
    int L = next_pow2(n+m-1);

    double* X_in = fftw_alloc_real(L);
    fftw_complex* X_out = fftw_alloc_complex(L/2 + 1);

    double* H_in = fftw_alloc_real(L);
    fftw_complex* H_out = fftw_alloc_complex(L/2 + 1);

    double* y_out = fftw_alloc_real(L);

    fftw_plan plan_x = fftw_plan_dft_r2c_1d(L, X_in, X_out, FFTW_ESTIMATE);
    fftw_plan plan_h = fftw_plan_dft_r2c_1d(L, H_in, H_out, FFTW_ESTIMATE);
    fftw_plan plan_inv = fftw_plan_dft_c2r_1d(L, X_out, y_out, FFTW_ESTIMATE);

    std::memset(X_in, 0, sizeof(double)*L);
    std::memset(H_in, 0, sizeof(double)*L);

    for (int i=0; i<n; ++i) X_in[i] = x[i];
    for (int i=0; i<m; ++i) H_in[i] = h[i];

    fftw_execute(plan_x);
    fftw_execute(plan_h);

    // element-wise multiply X_out and H_out
    for (int i=0; i<(L/2 + 1); ++i) {
        double re = X_out[i][0]*H_out[i][0] - X_out[i][1]*H_out[i][1];
        double im = X_out[i][0]*H_out[i][1] + X_out[i][1]*H_out[i][0];
        X_out[i][0] = re;
        X_out[i][1] = im;
    }

    fftw_execute(plan_inv);

    // normalization time!!
    for (int i = 0; i < (n+m-1); ++i)
    {
        std::cout << "y[" << i << "] = " << y_out[i]/L << "\n";
    }
    
    fftw_destroy_plan(plan_x);
    fftw_destroy_plan(plan_h);
    fftw_destroy_plan(plan_inv);

    fftw_free(X_in); fftw_free(X_out);
    fftw_free(H_in); fftw_free(H_out);
    fftw_free(y_out);

    return 0;
}

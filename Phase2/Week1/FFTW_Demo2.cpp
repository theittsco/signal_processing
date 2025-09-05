// Inverse FFT from complex input to real output
#include <iostream>
#include <fftw3.h>

int main(int argc, char const *argv[])
{
    const int N = 8;
    fftw_complex in[N/2+1] ={{8,0},{1,-2},{0,0},{1,2},{0,0}};
    double out[N];

    fftw_plan p = fftw_plan_dft_c2r_1d(N,in, out,FFTW_ESTIMATE);
    fftw_execute(p);

    for (int i = 0; i < N; ++i)
    {
        std::cout << "time" << i << ": " << out[i] / N << "\n";
    }
    
    fftw_destroy_plan(p);
    return 0;
}

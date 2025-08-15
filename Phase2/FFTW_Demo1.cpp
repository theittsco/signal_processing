// Forward FFT of real input
#include <iostream>
#include <fftw3.h>

int main(int argc, char const *argv[])
{
    const int N = 8;
    double in[N] ={1,0,0,0,0,0,0,0};
    fftw_complex out[N/2+1];

    fftw_plan p = fftw_plan_dft_r2c_1d(N,in, out,FFTW_ESTIMATE);
    fftw_execute(p);

    for (int i = 0; i < N/2+1; ++i)
    {
        std::cout << "freq bin" << i << ": (" << out[i][0] << ", " << out[i][1] << "i)\n";
    }
    
    fftw_destroy_plan(p);
    return 0;
}

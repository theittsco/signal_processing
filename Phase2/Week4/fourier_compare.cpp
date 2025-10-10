#include "../signal.hh"
#include "timer.cpp"
#include <iostream>
#include <fftw3.h>
#include "../fftw3_util.hh"
#include <fstream>

#define _USE_MATH_DEFINES

int main(int argc, char const *argv[])
{
    
    int N = 1024; // number of sample points
    double duration = 1.0; // 1 sec duration
    double fs = N / duration; // sample frequency
    double T = 1.0 / fs; // sample period

    std::vector<double> mult_freq_sig = signal_generator(N, [T](int n) {return std::cos(50 * 2 * PI * n * T) + 2*std::cos(100 * 2 * PI * n * T); });

    Timer t; // Timing info
    fftw_complex out[N/2+1];
    fftw_plan p = fftw_plan_dft_r2c_1d(N,mult_freq_sig.data(),out,FFTW_ESTIMATE);
    fftw_execute(p);

    std::cout << "Elapsed: " << t.elapsed() << " ms\n";

    std::vector<double> phase_fftw = phase_spectrum_fftw(out,N,true,1e-13);
    std::vector<double> magnitude_fftw = magnitude_spectrum_fftw(out,N);

    // Out file
    std::ofstream out2("fftw_test.txt");

    if (out2.is_open()) {
        for (int i = 0; i < N/2; ++i) {
            out2 << i << " " << /*dft_freq_test[i] << " "  << mult_freq_sig[i] << " " << dft_cks[i] << " " << dft_size[i] << " " <<*/ phase_fftw[i] << " " << magnitude_fftw[i]/N << "\n";
        }
        out2.close();
        std::cout << "y data saved to fftw_test.txt\n";
    } else {
        std::cerr << "Failed to open fftw_test.txt for writing.\n";
    }

    return 0;
}

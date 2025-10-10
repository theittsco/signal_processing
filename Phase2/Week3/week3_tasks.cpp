#include <iostream>
#include <vector>
#include <fstream>
#include "../signal.hh"
#include "../Week4/timer.cpp"
#define _USE_MATH_DEFINES

int main(int argc, char const *argv[])
{
    int N = 1024; // number of sample points
    double duration = 1.0; // 1 sec duration
    double fs = N / duration; // sample frequency
    double T = 1.0 / fs; // sample period

    std::vector<double> mult_freq_sig = signal_generator(N, [T](int n) {return std::cos(50 * 2 * PI * n * T) + 2*std::cos(100 * 2 * PI * n * T); });

    Timer t; // Timing info
    std::vector<double> dft_freq_test = dft_freq(N,fs); // freq axis for dft
    std::vector<std::complex<double>> dft_cks = dft_full(mult_freq_sig, N); // dft for input
    std::vector<double> dft_size(dft_cks.size(),0.0);
    std::cout << "Elapsed: " << t.elapsed() << " ms\n";

    std::vector<double> phase = phase_spectrum(dft_cks,true,1e-8);
    std::vector<double> magnitude = magnitude_spectrum(dft_cks);

    for (int i = 0; i < dft_size.size()/2; i++)
    {
        dft_size[i] = std::abs(dft_cks[i]); // taking the magnitude and positive part to plot
    }
    
    // Out file
    std::ofstream out2("dft_test.txt");

    if (out2.is_open()) {
        for (int i = 0; i < N/2; ++i) {
            out2 << i << " " << dft_freq_test[i] << " "  << mult_freq_sig[i] << " " << dft_cks[i] << " " << dft_size[i] << " " << phase[i] << " " << magnitude[i] << "\n";
        }
        out2.close();
        std::cout << "y data saved to dft_test.txt\n";
    } else {
        std::cerr << "Failed to open dft_test.txt for writing.\n";
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
#include "signal.hh"
#define _USE_MATH_DEFINES

double PI = acos(-1);

int main(int argc, char const *argv[])
{
    //std::vector<double> x = {1.3,2.5,-6,-4.5,0,3.8};
    //std::vector<double> h = {1,3,2,0};

    /*
    std::vector<double> x(400);
    step(x,200,2.0);
    std::vector<double> h(20);
    impulse(h,3,3.0);
    */

    std::vector<double> x = signal_generator(200, [](int n) { return std::exp(-0.5 * n); } );
    std::vector<double> h = signal_generator(20, [](int n) { return std::cos(100 * 2 * PI * n); } );


    std::vector<double> y = convolve(x,h);
    std::vector<double> R = autocorrelation(y);

    std::ofstream out("convolution.txt");
    if (out.is_open()) {
        for (int i = 0; i < y.size(); ++i) {
            out << i << " " << y[i] << " " << R[i] << "\n";
        }
        out.close();
        std::cout << "y data saved to convolution.txt\n";
    } else {
        std::cerr << "Failed to open convolution.txt for writing.\n";
    }

    return 0;
}

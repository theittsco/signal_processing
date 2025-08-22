#include <iostream>
#include <vector>
#include <fstream>


std::vector<double> convolve(const std::vector<double> signal, const std::vector<double> impulse) {
    // Takes in input signal and manually convolves it with an impulse response. Returns a vector y of the convolved signal.
    int N = signal.size();
    int M = impulse.size();
    int y_length = N + M - 1;
    std::vector<double> y;

    double response;
    int k_min, k_max;

    for (int i = 0; i < y_length; i++)
    {
        response = 0.0;
        k_min = std::max(0, i - (M-1));
        k_max = std::min(i, N - 1);
        for (int k = k_min; k < k_max+1; k++)
        {
            response += signal.at(k) * impulse.at(i - k);
        }
        y.push_back(response);
    }
    return y;
}

int main(int argc, char const *argv[])
{
    std::vector<double> x = {1.3,2.5,-6,-4.5,0,3.8};
    std::vector<double> h = {1,3,2,0};

    std::vector<double> y = convolve(x,h);

    std::ofstream out("convolution.txt");
    if (out.is_open()) {
        for (int i = 0; i < y.size(); ++i) {
            out << i << " " << y[i] << "\n";
        }
        out.close();
        std::cout << "y data saved to convolution.txt\n";
    } else {
        std::cerr << "Failed to open convolution.txt for writing.\n";
    }

    return 0;
}

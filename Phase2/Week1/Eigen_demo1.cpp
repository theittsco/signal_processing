/*
Signals <-> column vectors. Use VectorXd for real-valued signals and VectorXcd for complex.

Use Eigen::Map to wrap raw C arrays (zero copy), very useful when interoperating with C FFT libraries or audio buffers:
*/
#include <Eigen/Dense>
using Eigen::VectorXd;
using Eigen::VectorXcd;

int main(int argc, char const *argv[])
{
    VectorXd x(8);
    x << 1,0,0,0,0,0,0,0;
    VectorXcd X = x.cast<std::complex<double>>();
    
    double raw[1024]; // Some signal filled elsewhere
    Eigen::Map<VectorXd> xm(raw, 1024);
}

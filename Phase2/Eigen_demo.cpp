#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

int main() {
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;

    // A rule of thumb is to use fixed-size matrices for size 4-by-4 and smaller.
    MatrixXd m2 = MatrixXd::Random(3,3);
    m2 = (m2 + MatrixXd::Constant(3,3,1.2)) * 50;
    std::cout << "m2 =" << std::endl << m2 << std::endl;
    VectorXd v(3);
    v << 1, 2, 3;
    std::cout << "m * v =" << std::endl << m2 * v << std::endl;
}
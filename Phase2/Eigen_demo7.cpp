/*
Solve Toeplitz Yule–Walker equations for AR model (order p):

R * a = -r (where R is Toeplitz autocorr matrix, r is autocorr vector)

You can form Toeplitz and solve using Eigen's solvers — for Toeplitz, specialized solvers exist, but for reasonable p (≤100) direct solve is fine.
*/
#include <Eigen/Dense>
using Eigen::VectorXd;

VectorXd levinson_durbin(const VectorXd& r, int p) {
    // r[0..p] autocorrelation; returns a[1..p] (LPC coefficients)
    VectorXd a = VectorXd::Zero(p);
    VectorXd E = VectorXd::Zero(p+1);
    VectorXd ref = VectorXd::Zero(p+1);

    E[0] = r[0];
    for (int i = 1; i < p; i++)
    {
        double acc = r[i];
        for (int j = 0; j < i; j++)
        {
            acc += a[j-1]*r[i-j];
        }
        double k = -acc / E[i-1];
        // update a
        VectorXd anew = a;
        for (int j=1; j<i;j++) anew[j-1] += k * a[i-j-1];
        anew[i-1] = k;
        a = anew;
        E[i] = (1-k*k)*E[i-1];
    }
    return a;
}

// (Levinson–Durbin is preferred for stability and O(p^2).)
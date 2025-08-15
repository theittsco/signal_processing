// For simple IIR direct-form filtering, implement a filter function with state:

#include <Eigen/Dense>
using Eigen::VectorXd;

// General diff equation: y[n] = sum b[k]*x[n-k] - sum a[k]*y[n-k]
VectorXd filter_df(const VectorXd& b, const VectorXd& a, const VectorXd& x) {
    int N = x.size(), nb = b.size(), na = a.size();
    VectorXd y = VectorXd::Zero(N);
    for (int n = 0; n < N; ++n)
    {
        double acc = 0.0;
        for (int k=0; k<nb; ++k) if (n-k >= 0) acc += b[k]*x[n-k];
        for (int k=1; k<na; ++k) if (n-k >= 0) acc -= a[k]*y[n-k];
        acc /= a[0];
        y[n] = acc;
    }
    return y;
}

// For steady-state/real-time, maintain circular buffers for state instead of re-accessing history.
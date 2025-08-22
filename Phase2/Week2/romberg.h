#include "interp_1d.h"
#include "quadrature.h"

template <class T>
double qromb(T &func, const double a, const double b, const double eps=1.0e-10) {
    const int JMAX = 20, JMAXP = JMAX + 1, K = 5;

    std::vector<double> s(JMAX), h(JMAXP);
    Poly_interp polint(h,s,K);
    h[0] =1.0;
    Trapzd<T> t(func,a,b);
    for (int j = 1; j < JMAX; j++)
    {
        s[j-1]=t.next();
        if (j>=K) {
            double ss=polint.rawinterp(j-K,0.0);
            if (abs(polint.dy) <= eps*abs(ss)) return ss;
        }
        h[j]=0.25*h[j-1];
    }
    throw("Too many steps in routine qromb");
}
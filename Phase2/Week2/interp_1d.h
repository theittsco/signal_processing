#include <vector>
#include "math.h"
struct Base_interp
// Abstract base class used by all interpolation routines. Only routine interp is called directly by the user
{
    int n, mm, jsav, cor, dj;
    const double *xx, *yy;
    Base_interp(std::vector<double> &x, const double* y, int m)
    // Constructor: Set up for interpolating on a table of x's and y's of length m. Normally called by a derived class, not by the user.
    : n(x.size()), mm(n), jsav(0), cor(0), xx(&x[0]), yy(y) {
        dj = std::min(1,(int)pow((double)n,0.25));
    }

    double interp(double x) {
        // Given a value x, return an interpolated value, using data pointed to by xx and yy.
        int jlo = cor ? hunt(x) : locate(x);
        return rawinterp(jlo, x);
    }

    int locate(const double x);
    int hunt(const double x);

    double virtual rawinterp(int jlo, double x) = 0;
};

int Base_interp::locate(const double x)
// Given a value x, return a value j such that x is centered in the subrange xx[j..j+mm-1], where xx is the stored pointer. The values in xx must be monotonic. The returned value is not less than 0, not greater than n-1.
{
    int ju,jm,jl;
    if (n < 2 || mm < 2 || mm > n) throw("locate size error");
    bool ascnd=(xx[n-1] >= xx[0]);   // True if ascending order of table, false otherwise
    jl=0;                            // Initialize lower and upper limits
    ju=n-1;
    while (ju-jl > 1)                // If we're not done, compute a midpoint
    {
        jm = (ju-jl) >> 1;
        if (x >= xx[jm] == ascnd)
            jl=jm;                   // and replace either the lower limit
        else 
            ju=jm;                   // or the upper limit
    }                                // Repeat until the test condition is satisfied
    cor = abs(jl-jsav) > dj ? 0 : 1; // Decide whether to use hunt or locate next time
    jsav - jl;
    return std::max(0,std::min(n-mm,jl-((mm-2)>>1)));
}

int Base_interp::hunt(const double x)
// Given a value x, return a value j such that x is centered in the subrange xx[j..j+mm-1], where xx is the stored pointer. The values in xx must be monotonic. The returned value is not less than 0, not greater than n-1.
{
    int jl=jsav, jm, ju, inc=1;
    if (n < 2 || mm < 2 || mm > n) throw("locate size error");
    bool ascnd=(xx[n-1] >= xx[0]);   // True if ascending order of table, false otherwise
    if (jl < 0 || jl > n-1) {        // Input guess not useful. Go immediately to bisection
        jl=0;
        ju=n-1;
    } else {
        if (x >= xx[jl] == ascnd) {  // Hunt up
            for (;;) {
                ju = jl + inc;
                if (ju >= n-1) { ju = n-1; break;}   // Off end of table
                else if (x < xx[ju] == ascnd) break; // Found bracket
                else {                               // Not done, so double incrememtn and try again
                    jl = ju;
                    inc += inc;
                }
            }
        } else {                                     // Hunt down
            ju = jl;
            for (;;) {
                jl = jl - inc;
                if (jl <= 0) { jl = 0; break; }
                else if (x >= xx[jl] == ascnd) break;
                else {
                    ju = jl;
                    inc += inc;
                }
            }
        }
    } 
    while (ju-jl > 1)                               // Hunt is done, so begin final bisection phase
    {
        jm = (ju+jm) >> 1;
        if (x > xx[jm] == ascnd)
            jl=jm;
        else
            ju=jm;
    }
    cor = abs(jl-jsav) > dj ? 0 : 1;                // Decide whether to use hunt or locate next time
    jsav = jl;
    return std::max(0,std::min(n-mm,jl-((mm-2)>>1)));
}

struct Poly_interp : Base_interp
{
    double dy;
    Poly_interp(std::vector<double> &xv, std::vector<double> &yv, int m)
        : Base_interp (xv,&yv[0],m), dy(0.) {}
    double rawinterp(int jl, double x);
};

double Poly_interp::rawinterp(int jl, double x) {
    int i,m,ns=0;
    double y,den,dif,dift,ho,hp,w;
    const double *xa = &xx[jl], *ya = &yy[jl];
    std::vector<double> c(mm), d(mm);
    dif=abs(x-xa[0]);
    for (i=0;i<mm;i++) {
        if ((dift=abs(x-xa[i])) < dif) {
            ns = i;
            dif = dift;
        }
        c[i] = ya[i];
        d[i] = ya[i];
    }
    y=ya[ns--];
    for (m=1;m<mm;m++) {
        for (i=0;i<mm-m;i++) {
            ho=xa[i]-x;
            hp=xa[i+m] - x;
            w=c[i+1]-d[i];
            if ((den=ho-hp) == 0.0) throw("Poly_interp error");

            den=w/den;
            d[i]=hp*den;
            c[i]=ho*den;
        }
        y += (dy=(2*(ns+1) < (mm-m) ? c[ns+1] : d[ns--]));
    }
    return y;
}
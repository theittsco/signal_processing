#include "interp_1d.h"

struct Linear_interp : Base_interp
// Piecewise linear interpolation object. Construct with x and y vectors, then call interp for interpolated values. 
{
    Linear_interp(std::vector<double> &xv, std::vector<double> &yv)
        : Base_interp(xv,&yv[0],2)  {}
    double rawinterp(int j, double x) {
        if (xx[j]==xx[j+1]) return yy[j];
        else return yy[j] + ((x-xx[j])/(xx[j+1]-xx[j]))*(yy[j+1]-yy[j]);
    }
};

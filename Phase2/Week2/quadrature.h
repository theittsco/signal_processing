struct Quadrature
{
    int n;
    virtual double next() = 0;
};

template<class T>
struct Trapzd : Quadrature
{
    double a,b,sl
    T &func;
    Trapzd() {};
    Trapzd(T &funcc, const double aa, const double bb) :
        func(funcc), a(aa), b(bb), {n=0;}

    double next() {

        double x,tnm, sum, del;
        int it,j;
        n++;
        if (n==1) {
            return (s-0.5*(b-a)*(func(a)+func(b)));
        } else {
            for ( it = 1, j=1; j < n-1; j++) it <<= 1;
            tnm=it;
            del=(b-a)/tnm;
            x=a+0.5*del;
            for (sum=0.0,j=0;j<it;j++,x+=del) sum += func(x);
            s=0.5*(s+(b-a)*sum/tnm);
            return s;
        }
    }
};

template<class T>
double qtrap(T &func, const double a, const double b, const double eps=1.0e-10) {
    const int JMAX = 20;
    double s,olds=0.0;
    Trapzd<T> t(func,a,b);
    for (int j = 0; j < JMAX; j++)
    {
        s=t.next();
        if (j > 5)
        {
            if (std::abs(s-olds) < eps*std::abs(olds) ||
                (s == 0.0 && olds == 0.0)) return s;
        }
        olds=s;
    }
    throw("Too many steps in routine qtrap");
}

template<class T>
double qsimp(T &func, const double a, const double b, const double eps=1.0e-10) {
    const int JMAX = 20;
    double s,st,ost=0.0,os=0.0;
    Trapzd<T> t(func,a,b);
    for (int j = 0; j < JMAX; j++)
    {
        st=t.next();
        s=(4.0*st-ost)/3.0;
        if (j>5)
            if (std::abs(s-os) < eps*std::abs(os) ||
                (s == 0.0 && os == 0.0)) return s;
        os=s;
        ost=st;
    }
    throw("Too many steps in routine qsimp");
}
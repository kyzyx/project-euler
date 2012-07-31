// See Soddy Circles (mathworld.wolfram.com/SoddyCircles.html)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#define PI 3.1415926535898
#define D 10

using namespace std;

class Gap {
public:
    double r1,r2,r3;
    bool inner;

    Gap() {
    }
    Gap(double a, double b, double c, bool in) :
    r1(a), r2(b), r3(c), inner(in) 
    {
        ;
    }

    void set(double a, double b, double c, bool in) {
        r1 = a;
        r2 = b;
        r3 = c;
        inner = in;
    }

    inline double soddy() {
        return r1*r2*r3/(r1*r2 + r1*r3 + r2*r3 + 2*sqrt(r1*r2*r3*(r1+r2+r3)));
    }
    inline double rsoddy() {
        return -r1*r2*r3/(-r1*r2 + -r1*r3 + r2*r3 - 2*sqrt(-r1*r2*r3*(-r1+r2+r3)));
    }
};

inline double area(double r) {
    return PI*r*r;
}

    Gap gaps[8*59049];
int main() {
    double lr = -1./(3-2*sqrt(3));
    /*Gap g(lr,1,1,false);
    cout << g.rsoddy() << endl;
    return 0;*/
    int ng = 0;
    double tot = 3*area(1);
    gaps[ng++].set(1,1,1,true);
    gaps[ng++].set(lr,1,1,false);
    gaps[ng++].set(lr,1,1,false);
    gaps[ng++].set(lr,1,1,false);
    int s = 0;
    for (int i = 0; i < D; ++i) {
        int ong = ng;
        if (ng > 5*59049) {
            ng = 0;
        }
        int j = s;
        s = ng;
        for (;j < ong; ++j) {
            double nr;
            if (gaps[j].inner) {
                nr = gaps[j].soddy();
                gaps[ng++].set(nr,gaps[j].r1,gaps[j].r2,true);
                gaps[ng++].set(nr,gaps[j].r3,gaps[j].r2,true);
                gaps[ng++].set(nr,gaps[j].r1,gaps[j].r3,true);
            }
            else {
                nr = gaps[j].rsoddy();
                gaps[ng++].set(nr,gaps[j].r2,gaps[j].r3,true);
                gaps[ng++].set(gaps[j].r1,nr,gaps[j].r2,false);
                gaps[ng++].set(gaps[j].r1,nr,gaps[j].r3,false);
            }
            tot += area(nr);
        }
        printf("%d Total: %.10f\n", i+1, 1.-(tot/area(lr)));
    }
    return 0;
}

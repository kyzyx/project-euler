#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double c = pow(2, 30.403243784);

double f(double x){
    double a = floor(c/pow(2.0, x*x));
    return 1e-9*a;
}

int main(){
    double a = -1, b;
    for(int i=0; i<10000000; i++){
        b = f(a);
        //printf("%.10f\n", a+b);
        a = b;
    }
    b = f(a);
    printf("%.10f\n", a+b);
    cin.get();
    return 0;
}

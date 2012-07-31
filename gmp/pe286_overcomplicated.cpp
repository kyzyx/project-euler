/* Recursive formula from http://en.wikipedia.org/wiki/Poisson_binomial_distribution */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <gmp.h>
#include <gmpxx.h>

#define K 20
#define N 50
//#define K 2
//#define N 2

using namespace std;

typedef mpq_class Fraction;

Fraction TARGET(1,50);
Fraction EPSILON(1,1e11);

Fraction pow(Fraction a, int b) {
    Fraction ret = 1;
    for(int i = 0; i < b; i++) ret *= a;
    return ret;
}


Fraction calcProb(Fraction q) {
    //cout << "Calculating with " << q << endl;
    // Calculate T(i)
    // Calculate p(0)
    Fraction probs[K+1];
    probs[0] = 1;
    for(int i = 0; i < N; i++) probs[0] *= i+1;
    for(int i = 0; i < N; i++) probs[0] /= q;

    //cout << "\t0: " << probs[0] << endl;
    for(int k = 1; k <= K; k++) {
        probs[k] = 0;
        Fraction cc = 0;
        Fraction yy, ttmp, curr;

        for(int i = 1; i <= k; i++) {
            // Calculate T
            Fraction t = 0;
            for(int j = 1; j <= N; j++) {
                t += pow((q - j)/j, i);
            }
            //cout << probs[k-i]*t << endl;
            if (i&1) probs[k] += probs[k-i]*t;
            else     probs[k] -= probs[k-i]*t;
        }
        probs[k] /= k;
        //cout << "\t" << k << ": " << probs[k] << endl;
    }
    return probs[K];
}

Fraction bsearch(Fraction lo, Fraction hi) {
    Fraction mid = lo/2 + hi/2;
    if (hi - lo < EPSILON) return mid;
    Fraction p = calcProb(mid);

    //cout << mid << " " << p << endl;
    if (p > TARGET) return bsearch(mid, hi);
    else if (p < TARGET) return bsearch(lo, mid);
    else return mid;
}

int main() {
	Fraction n = bsearch(50, 55);
	printf("%.11f\n", n.get_d());
	//cin.get();
    return 0;
}

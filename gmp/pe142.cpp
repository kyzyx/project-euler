/* 27s, but easily improvable, just too lazy - I was already done when I realized it would be faster to find pythagorean triples
(b,e,c) and (b,f,d) and go from there (found en route to last condition with y and z)
Too lazy to pull out pythagorean triple code and redo it but its probably way faster
*/
#include <iostream>
#include <queue>
#include <gmp.h>
#include <gmpxx.h>
#define N 100000

using namespace std;
//typedef unsigned long BigInt;
typedef mpz_class BigInt;

class ssq{
    public: BigInt a,b,sum;
            ssq(BigInt aa, BigInt bb){
                a = aa;
                b = bb;
                sum = a*a + b*b;
            }
};

bool operator<(ssq a, ssq b){
    return a.sum > b.sum;
}

typedef priority_queue<ssq> pq;

ssq& makessq(BigInt a, BigInt b){
    ssq* ret = new ssq(a,b);
    return *ret;
}

int main(){
    pq sumsquares;
    for(BigInt i = 1; i<N; i++){
        sumsquares.push(makessq(i,1));
    }
    ssq tmp(0,0);
    ssq last(0,0);
    BigInt x,y,z, tst1, tst2;
    while(!sumsquares.empty()){
        tmp = sumsquares.top();
        if(tmp.sum == last.sum && tmp.a != last.b && tmp.sum%2 == 0){
             //cout << tmp.a << "^2 + " << tmp.b << "^2 = " << last.a << "^2 + " << last.b << "^2 = " << tmp.sum << endl;
            x = tmp.sum/2;
            y = (tmp.a*tmp.a - tmp.b*tmp.b);
            z = last.a*last.a - last.b*last.b;
            if(y%2==0 && z%2 == 0){
                y /=2;
                z /=2;
                tst1 = y+z;
                tst2 = y-z;
                if(mpz_perfect_square_p(tst2.get_mpz_t()) && mpz_perfect_square_p(tst1.get_mpz_t()))  cout << x << " " << y << " " << z << endl;
            }
             //cin.get();
        }
        sumsquares.pop();
        if(tmp.b < N && tmp.a >= tmp.b) sumsquares.push(makessq(tmp.a, tmp.b+1));
        last.a = tmp.a;
        last.b = tmp.b;
        last.sum = tmp.sum;

    }

    return 0;
}

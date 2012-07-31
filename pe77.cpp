#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

class poly{
    private: int deg;
             unsigned long* coef;

             long power(long x, long n){
                    int r = 1;
                    for(int i=0; i<n; i++){
                        r *= x;
                    }
                    return r;
             }
    public:
        //Constructors
        poly(int n){
            deg = n;
            coef = new unsigned long[deg];
            for(int i=0; i<deg; i++) coef[i] = 0;
        }
        poly(int n, long* c){
            deg = n;
            coef = new unsigned long[deg];
            for(int i=0; i<deg; i++) coef[i] = c[deg-i-1];
            if(coef[deg-1] == 0) --deg;
        }

        //Assignment
        poly& operator=(const poly& p){
            if(this == &p) return *this;
            deg = p.deg;
            for(int i=0; i<deg; i++) coef[i] = p.coef[i];

            return *this;
        }
        poly& operator+=(const poly& p){
            if(this == &p){
                 for(int i=0; i<deg; i++) coef[i] = 2*coef[i];
                 return *this;
            }
            unsigned long* newarr;
            if(p.deg > deg){
                 newarr = new unsigned long[p.deg];
                 for(int i=0; i<deg; i++){
                    newarr[i] = coef[i];
                 }
                 for(int i=deg; i<p.deg; i++) {
                    newarr[i] = p.coef[i];
                 }
                 coef = newarr;
            }

            for(int i=0; i<deg; i++) coef[i] += p.coef[i];
            deg = p.deg;
            return *this;
        }

        poly& operator*=(const poly& p){
            unsigned long* newarr;
            int newdeg = deg + p.deg - 1;
            //
            if(newdeg > 1000) newdeg = 1000;
            newarr = new unsigned long[newdeg];
            for(int i=0; i<newdeg; i++) newarr[i] = 0;

            for(int i=0; i<deg; i++){
                for(int j=0; j<p.deg; j++){
                    //
                    if(i+j >=1000) continue;
                    newarr[i+j] += ((coef[i]%1000000)*(p.coef[j]%1000000))%1000000;
                }
            }
            coef = newarr;
            deg = newdeg;
            return *this;
        }

        //Operations
        const poly operator+(const poly& addend){
            return poly(*this) += addend;
        }
        const poly operator*(const poly& addend){
            return poly(*this) *= addend;
        }
        //Evaluation
        long eval(int x){
            long res = 0;
            for(int i=0; i<deg; i++){
                res += power(x, i)*coef[i];
            }
            return res;
        }

        //Output
        long getCoef(int n){
            return coef[n];
        }
        void dump(){
            for(int i=deg-1; i>0; i--){
                if(coef[i] != 0){
                     if(coef[i] != 1) cout << coef[i];
                     cout << "x";
                     if(i>1) cout << "^" << i;
                }
                if(coef[i-1] > 0) cout << " + ";
                else if(coef[i-1] < 0) cout << " - ";
            }
            if(coef[0] != 0) cout << coef[0];
        }
        /*string toString(){

        }*/

};
int main(){
    long* c;
    int z = 100;
    long tmp[1] = {1};
    initialize();

    poly a(1,tmp);

    for(int i=0; primes[i] < z; i++){
        c = new long[z+1];
        for(int j=0; j<=z; j++){
            if(j%primes[i] == 0) c[z-j] = 1;
            else c[z-j] = 0;
        }
        poly work(z+1, c);
        a *= work;
    }

    long maxi = 0;
    int mi = 0;
    fori(100) {
		if (a.getCoef(i) > maxi) {
			maxi = a.getCoef(i);
			mi = i;
		}
		cout << i << " " << a.getCoef(i) << endl;
	}
	cout << "Max at " << mi << ": " << maxi << endl;
    cin.get();
    return 0;
}

#include <iostream>
#include <fstream>
//#include "util.h"

using namespace std;

class poly{
    private: int deg;
             long* coef;
             
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
            coef = new long[deg];
            for(int i=0; i<deg; i++) coef[i] = 0;
        }
        poly(int n, long* c){
            deg = n;
            coef = new long[deg];
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
            long* newarr;
            if(p.deg > deg){
                 newarr = new long[p.deg];
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
            long* newarr;
            int newdeg = deg + p.deg - 1;
            //
            if(newdeg > 200) newdeg = 200;
            newarr = new long[newdeg];
            for(int i=0; i<newdeg; i++) newarr[i] = 0;
            
            for(int i=0; i<deg; i++){
                for(int j=0; j<p.deg; j++){
                    //
                    if(i+j >=200) continue;
                    newarr[i+j] += coef[i]*p.coef[j];
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
    long tmp[1] = {1};
    poly a(1,tmp);
    int z = 100;
    for(int i=1; i<z; i++){
        c = new long[z+1];
        for(int j=0; j<z+1; j++){
            if(j%i == 0) c[z-j] =1;
            else c[z-j] = 0;    
        }
        poly work(z+1, c);
        a *= work;
    }
    cout << a.getCoef(z) << endl;
    cin.get();
    return 0;   
}

#include <iostream>
#include <cmath>
#include <gmp.h>
#include <gmpxx.h>
#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)

using namespace std;
typedef mpz_class BigInt;

int main(){
    double a = sqrt(3);
    mpz_t tmp;
    mpz_init(tmp);
    BigInt tri,pent,hex;
    
    for(unsigned long i=800; i<500000; i++){
        for(unsigned long j=i/a; j<i; j++){
            for(unsigned long k=i/2; k<i; k++){
                if(i < 100000){
                    if(j*(3*j-1)/2 > (i*(i+1))/2) break;
                    if(k*(2*k - 1) > (i*(i+1))/2) break;
                    if((i*(i+1))/2 == j*(3*j-1)/2 && j*(3*j-1)/2 == k*(2*k - 1)){
                        cout << "Found " << i << endl;// break;
                    }
                }
                else{
                    tri = i;
                    tri = (tri*(tri+1))/2;
                    pent = j;
                    pent = pent*(3*pent-1)/2;
                    hex = k;
                    hex = hex*(2*hex - 1);
                    if(hex>tri) break;
                    if(pent>tri) break;
                    if(tri == pent && pent == hex){
                        tri = i;
                        tri = (tri*(tri+1))/2;
                        cout << "Found " << tri << endl;// break;
                    }
                }
            }
        }
        if(i%1000 == 0) cout << i << endl;
    }
    cout << "done";
    
    
    cin.get();
    return 0;   
}

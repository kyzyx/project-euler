#include <iostream>
#include <cstdlib>
#include <algorithm>
#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)
#include <gmp.h>
#include <gmpxx.h>
#define UL 10000
#define NMAX 1000000000

typedef mpz_class BigInt;
using namespace std;



unsigned long sumdigit(BigInt n){
    unsigned long t = 0;
    BigInt d;
    while(n>0){
        d = n%10;
        t += d.get_ui();
        n/=10;
    }
    return t;
}

const int maxi = 200;
const int maxj = 20;

BigInt pows[maxi][maxj];
bool works[maxi][maxj];
BigInt sds[100];
int z = 0;

int main(){
    int ns = 0;
    BigInt t;
    for(int i=2; i<maxi; i++){
        t = 1;
        for(int j=2; j<maxj; j++){
            pows[i][j] = t;
            if(sumdigit(t) == i){
                works[i][j] = true;
                sds[z++] = t;
                ns++;
            }
            else{
                works[i][j] = false;
            }
            t *= i;
        }
    }
    
    sort(sds, sds+z);
    fori(z) cout << i << ": " << sds[i] << endl;
    
    cout << ns << endl;
    
    return 0;
}

#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define M 47

using namespace std;

typedef mpz_class Bigint;

Bigint mod = 14348907;
Bigint p10[M];

// nws[i][j][0] is number of ways to sum to i with j digits and no leading 0s
// nws[i][j][1] is number of ways to sum to i with j digits and leading 0s
Bigint nws[9*M/2+1][M/2+1][2];   
Bigint sums[9*M/2+1][M/2+1][2];

Bigint T(int n) {
    if (n == 1) return 45;
    Bigint ret = 0;
    Bigint tns = 0;
    
    Bigint lastdigs = 0;
    Bigint firstdigs = 0;
    for(int i = 1; i <= 9*(n/2); ++i) {
        ret += (sums[i][n/2][0] + sums[i][n/2][1])*nws[i][n/2][0];
        lastdigs += (sums[i][n/2][0] + sums[i][n/2][1])*nws[i][n/2][0];
        ret %= mod;
        ret += sums[i][n/2][0]*(nws[i][n/2][0]+nws[i][n/2][1])*p10[n-n/2];
        firstdigs += sums[i][n/2][0]*(nws[i][n/2][0]+nws[i][n/2][1])*p10[n-n/2];
        ret %= mod;
        
        tns += (nws[i][n/2][0] + nws[i][n/2][1])*nws[i][n/2][0];
        
        //cout << i << "(" << sums[i][n/2][0] <<  " " << sums[i][n/2][1] << ")" << ": " << (sums[i][n/2][0] + sums[i][n/2][1])*nws[i][n/2][0] << " " << sums[i][n/2][0]*(nws[i][n/2][0]+nws[i][n/2][1])*p10[n-n/2] << endl;
    }
    //cout << n << " " << lastdigs << " " << firstdigs << " ";
    if (n&1) ret = ret*10 + p10[n/2]*45*tns;
    return ret;
}

int main() {
    p10[0] = 1;
    for(int i = 1; i < M; ++i) {
        p10[i] = p10[i-1]*10 % mod;
    }
    
    for(int i = 0; i <= 9*M/2; ++i) {
        for(int j = 0; j <= M/2; ++j) {
            nws[i][j][0] = nws[i][j][1] = sums[i][j][0] = sums[i][j][1] = 0;
        }
    }
    //for(int i = 1; i <= M/2; ++i) nws[0][i][1] = 1;
    for(int i = 1; i < 10; ++i) {
        nws[i][1][0] = 1;
        sums[i][1][0] = i;
    }
    nws[0][1][1] = 1;
    
    for(int i = 1; i < M/2; ++i) {
        for(int k = 0; k <= 9*i; ++k) {
            nws[k][i+1][1] += nws[k][i][1] + nws[k][i][0];
            sums[k][i+1][1] = (sums[k][i+1][1] + sums[k][i][1] + sums[k][i][0]) % mod;
            for(int j = 1; j < 10; ++j) {
                nws[k+j][i+1][0] += nws[k][i][0] + nws[k][i][1];
                sums[k+j][i+1][0] += sums[k][i][1] + sums[k][i][0];
                sums[k+j][i+1][0] += j*p10[i]*(nws[k][i][0] + nws[k][i][1]);
                sums[k+j][i+1][0] %= mod;
            }
        }
    }    
    Bigint s = 0;
    Bigint tmp;
    for(int i = 1; i <= M; ++i) {
        tmp = T(i);
        //cout << T(i) << endl;
        s += tmp;
        if (s>mod) s %= mod;
    }
    
    cout << s%mod << endl;
    return 0;
}

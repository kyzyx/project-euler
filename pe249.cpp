// 6s
#include <iostream>
#include <vector>
#define M 5000
#define S 1548137


using namespace std;

long long mod = 10000000000000000LL;
bool isprime[S];
long long nw[S];
int up[S];
long long pending[S];
int np = 0;
int nsp = 0;
int primes[150000];
int sprimes[1000];

int main() {
    long long sum = 0;
    for(int i = 0; i < S; ++i) {
        isprime[i] = true;
        nw[i] = 0;
        up[i] = -1;
        pending[i] = 0;
    }
    for(int i = 2; i < S; ++i) {
        if (isprime[i]) {
            if (i<M) sprimes[nsp++] = i;
            primes[np++] = i;
            for(int j = 2*i; j < S; j +=i) isprime[j] = false;
        }
    }
    cout << "Done prep" << endl;
    nw[0] = 1;
    
    int mm = 0;
    int j;
    for(int i = 0; i < nsp; ++i) {
        for(j = mm; j >=0; --j) {
            if (nw[j] > 0) {
                if ((nw[j+sprimes[i]] += nw[j]) >= mod) 
                    nw[j+sprimes[i]] -= mod;
            }
        }
        mm += sprimes[i];
    }
    
    for(int i = 0; i < np; ++i) {
        sum += nw[primes[i]];
        if (sum >= mod) sum -= mod;
    }
    
    cout << sum << endl;
    
    cin.get();
    return 0;
}

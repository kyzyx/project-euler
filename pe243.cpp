#include <iostream>
#include <fstream>
#define Fori(m,n) for(int i=m; i<n; i++)
#define MAX 10000000

using namespace std;

bool isprime[MAX];
unsigned int primes[MAX/10];
int np = 0;


void initialize() {
// generate primes

	for(int i=0; i<MAX; i++) {
		isprime[i] = true;
	}
	for(int i=2; i<MAX; i++){
		if(isprime[i]){
			for(int j=2*i; j<MAX; j+=i){
				isprime[j] = false;
			}
			primes[np++] = i;
		}
	}
}

int main(){
    initialize();
    double lim = 15499./94744;
    //double lim = 0.4;
    cout << lim << endl;
    double num = 1;
    double n = 1;
    double k;
    for(int i = 0; i < np; i++) {
        num *= primes[i]-1;
        n *= primes[i];
        k = n;
                
        if ((k*num)/(n*(k-1)) < lim) {
            num /= primes[i]-1;
            n /= primes[i];
            double k = n;
            int j = 2;
            for(; (k*j*num)/(n*(k*j-1)) > lim; j++);
            unsigned int ans = 1;
            for(int j = 0; j < i; j++) {
                ans *= primes[j];
            }
            ans *= j;
            cout << ans << endl;
            break;
        }
    }
    
    cin.get();
    return 0;
}

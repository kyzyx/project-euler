#include <iostream>
#define N 1000000

using namespace std;

int primes[N];
int sqrt[N];
int nump = 0;

unsigned long numsquareddivs(int n){
	unsigned long ret = 1;
	int numcurrdivs = 0;
	
	for(int i=0; primes[i] <= n && n > 1; i++){
        //cout << primes[i] << " ";
        numcurrdivs = 0;
        while(n % primes[i] == 0){
            //cout << primes[i] << " ";
            n /= primes[i];
            numcurrdivs++;
        }
        ret *= numcurrdivs*2 + 1;
        //if(numcurrdivs > 0) cout << primes[i] << "^" << numcurrdivs << " ";
    }
	//cout << endl;
    return (ret + ret%2)/2;
}

void init(){
    bool isprime[N];
    for(int i=0; i<N; i++) isprime[i] = true;
    for(unsigned long i=2; i<N; i++){
        if(isprime[i]){
            for(unsigned long j=2*i; j<N; j+=i) isprime[j] =false;
            primes[nump++] = i;
        }
    }
    
    for(unsigned long i=0; i<1000; i++){
        for(unsigned long j=i*i; j<(i+1)*(i+1) && j<N; j++){
            sqrt[j] = i;
        }
    }
}

int main(){
    init();
    //cout << numsquareddivs(55440) << endl;
    unsigned long n;
    for(unsigned long i=2; i<N; i++){
        //cout << i << ": ";
        n = numsquareddivs(i);
        if(n > 1000) {
            cout << "***" << i << ":" << n << endl;
            cin.get();
            //break;
        }
        //cout << i << ":" << n << endl;
    }

    cin.get();
    return 0;
}

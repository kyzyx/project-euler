#include <iostream>
#include <fstream>
#define MAX 4000000
#define fori(n) for(int i=0; i < n; i++)

using namespace std;
bool isprime[MAX];
int primes[MAX/8];
int np = 0;
void initialize() {
    fori(MAX) isprime[i] = true;
    for(int i=2; i < MAX; i++) {
        if(isprime[i]) {
            primes[np++] = i;
            for(int j = 2*i; j < MAX; j+=i) isprime[j] = false;
        }
    }
}

int npf(int n){
    if(isprime[n]) return 1;
    int ret = 0;
    for(int i=0; i<np && primes[i] < n/2+1; i++){
        if(n%primes[i] == 0) ret++;
    }
    return ret;
}

int main(){
    initialize();
    
    fori(MAX){
        if(npf(i) == 4 && npf(i+1) == 4 && npf(i+2) == 4 && npf(i+3) == 4){
            cout << i << endl;
            break;
        }
        if(i%100000 == 0) cout << i << endl;
    }
    
    cin.get();
    return 0;   
}

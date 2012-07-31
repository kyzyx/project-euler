#include <iostream>
#include <fstream>
#define Fori(m,n) for(int i=m; i<n; i++)
#define N 1000000

using namespace std;

int totient[N+1];
int pfs[N+1];
bool isprime[N+1];

void fillpfs(){
    Fori(0,N+1) pfs[i] = 0;
    Fori(2,N+1){
        if(isprime[i]){
            for(int j=0; j<N+1; j += i){
                pfs[j]++;
            }
            if(i <= 3170 && i*i < N+1)  pfs[i*i] = 0;
        }
    }
    Fori(2,N+1){
        if(pfs[i] == 0){
            for(int j=0; j<N+1; j+=i){
                pfs[j] = 0;
            }
        }
    }
}

void filltot(){
    Fori(0,N+1) totient[i] = i-1;
    Fori(2,N+1){
        if(pfs[i] == 0) continue;
        else if(pfs[i]%2){
            for(int j=0; j<N+1; j+=i){
                totient[j] -= j/i-1;
            }
        }
        else{
            for(int j=0; j<N+1; j+= i){
                totient[j] += j/i-1;
            }
        }
    }
}

int main(){
    for(int i = 0; i < N+1; ++i) isprime[i] = true;
    for(int i = 2; i < N+1; ++i) {
        if (isprime[i]) {
            for(int j = 2*i; j < N+1; j += i) isprime[j] = false;
        }
    }
    fillpfs();
    cout << "Done filling primefactors" << endl;
    filltot();
    cout << "Done Generating totients" << endl;
    
    //PE72
    unsigned long long sum = 0;
    Fori(2,N+1){
         sum += totient[i];
    }
    cout << sum << endl;
    
    cin.get();
    return 0;
}

#include <iostream>
#include <cmath>
#define N 100000000
#define fori(n) for(int i=0; i<n; i++)

int log10(unsigned long n){
    int i;
    for(i=0;n>=1;i++){
        n/=10;
    }
    return i;
}
bool isPal(unsigned long n){
    int digs[10];
    int l10 = log10(n);
    fori(l10/2){
        digs[i] = n%10; 
        n/=10;
    }    
    if(l10%2 == 1) n/=10;
    fori(l10/2){
        if(n%10 != digs[l10/2 - i - 1]) return false;
        n/=10;
    }
    return true;
}

bool ns[N];

using namespace std;
int main(){
    int lim = sqrt(N);
    unsigned long tot = 0;
    unsigned long sum = 0;
    
    fori(N) ns[i] = false;
    for(unsigned long i=1;i<lim;i++){
        sum = i*i;
        for(unsigned long j=i+1;j<lim;j++){
            sum += j*j;
            if(sum >= N) break;
            if(isPal(sum)){
                 cout << i << " " << j << "=" << sum << endl;       
                 ns[sum] = true;
                 //tot += sum;
                 /*if(tot > 1000000000){
                    nb++;
                    tot -= 1000000000;
                 }*/
            }
        }
    }
    fori(N){
        if(ns[i]) tot += i;
    }
    //cout << nb << "000000000 + ";
    cout << tot;
    cin.get();
    return 0;   
}

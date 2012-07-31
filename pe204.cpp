#include <iostream>
#define fori(n) for(int i=0; i<n; i++)
#define N 1000000000
#define H 100

using namespace std;

char pfs[N+1];

int main(){
    fori(N+1) pfs[i] = 0;
    for(unsigned long i = 2; i<N+1; i++){
        if(pfs[i] == 0){
            if(i>H){
                for(unsigned long j=i; j<N+1; j += i){
                    pfs[j] = -127;
                }
            }
            else{
                for(unsigned long j=i*2; j<N+1; j += i){
                    pfs[j]++;
                }
            }
        }
        if(i%10000 == 0 && i<2000000 || i%2000000 == 0) cout << i << endl;
    }

    unsigned long num2 = 0;
    fori(N){
        if(pfs[i] < 0) num2++;
    }
    cout << num2 << "->" << N-num2 << endl;
    cin.get();
    return 0;
}

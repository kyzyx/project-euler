#include <iostream>
#define fori(n) for(int i=0; i<n; i++)
#define N 100000000

using namespace std;

int pfs[N+1];

int main(){
    fori(N+1) pfs[i] = 0;
    for(unsigned long i = 2; i<N+1; i++){
        if(pfs[i] == 0){
            for(unsigned long j=i*2; j<N+1; j += i){
                if(j<i) break;
                pfs[j]++;
            }
            if(i<10000) pfs[i*i] = -1;
        }
        else if(pfs[i] == -1){
            for(unsigned long j=i*2; j<N+1; j+= i){
                pfs[j] = 3;
            }
        }
        if(i%100000 == 0 && i<2000000 || i%4000000 == 2000000) cout << i << endl;
    }

    unsigned long num2 = 0;
    unsigned long num1 = 0;
    fori(N){
        if(pfs[i] == 2) num2++;
        else if(pfs[i] == -1) num1++;
//        cout << i << ":" << pfs[i] << endl;
    }
    cout << num2 << " " << num1 << " = " << num2+num1 << endl;
    cin.get();
    return 0;
}

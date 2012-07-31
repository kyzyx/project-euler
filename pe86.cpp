#include <iostream>
#define fori(n) for(int i=0; i<n; i++)
#define min(a,b) a<b?a:b

using namespace std;

bool isSquare[900000000];


bool issq(unsigned long n){
    if(n<900000000) return isSquare[n];
    else{
        cout << "too big" << endl;
        return false;
    }
}

int main(){
    fori(900000000) isSquare[i] = false;
    for(unsigned long i=1; i<30000; i++) isSquare[i*i] = true;
    cout << "done squares" << endl;
    
    int M = 98;
    int tot = 0;
    unsigned long tmp[3];
    unsigned long t;
    for(unsigned long i=1; i<=M; i++){
        for(unsigned long j=i; j<=M; j++){
            for(unsigned long k=j; k<=M; k++){
                tmp[1] = (i+j)*(i+j)+k*k;
                tmp[0] = (i+k)*(i+k)+j*j;
                tmp[2] = (k+j)*(k+j)+i*i;
                t = (min(min(tmp[0], tmp[1]), min(tmp[1], tmp[2])));
                //if(i == 3 && j == 5 && k == 6) cout << (min(min(tmp[0], tmp[1]), min(tmp[1], tmp[2]))) << endl;
                if(isSquare[t]) tot++;
                /*if(isSquare[(i+j)*(i+j)+k*k]) tot++;
                else if(isSquare[(i+k)*(i+k)+j*j]) tot++;
                else if(isSquare[(k+j)*(k+j)+i*i]) tot++;*/
            }
        }
    }
    int k,z;
    for(z=0; z<30000; z++){
        k = M+z;
        for(unsigned long i=1; i<=M+z; i++){
            for(unsigned long j=i; j<=M+z; j++){
                tmp[1] = (i+j)*(i+j)+k*k;
                tmp[0] = (i+k)*(i+k)+j*j;
                tmp[2] = (k+j)*(k+j)+i*i;
                t = (min(min(tmp[0], tmp[1]), min(tmp[1], tmp[2])));
                //if(i == 3 && j == 5 && k == 6) cout << (min(min(tmp[0], tmp[1]), min(tmp[1], tmp[2]))) << endl;
                if(isSquare[t]) tot++;
            }
        }    
        cout << k << ":" << tot << endl;
        if(tot>1000000) break;
    }
    cout << k << " " << tot << endl;
    cin.get();
    return 0;
}

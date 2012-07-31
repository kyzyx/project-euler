#include<iostream>

using namespace std;

int nums[13];

bool works(int nn, int n) {
    int k = 0;
    for(int j = 0; j < 2*n; j++) {
        if (nn&1) {
            k++;
        }
        else { 
            k--;
            if (k < 0) k = 0;
        }
        nn >>= 1;
    }
    return k;
}

void calcnums(int n) {
    nums[n] = 0;
    for(int i = 0; i < 1 << (2*n); i++) {
        if (__builtin_popcount(i) != n) continue;
        if (works(i,n) && works(~i,n)) nums[n]++;
    }
    nums[n] /= 2;
}

int main() {
    int N = 12;
    int num = 0;
    
    int Ncr[N+1];
    Ncr[0] = 1;
    for(int i = 1; i < N+1; i++) {
        Ncr[i] = Ncr[i-1]*(N-i+1)/i;
        cout << Ncr[i] << " ";
    }
    cout << endl;
    
    for(int i = 2; i <= N/2; i++) {
        calcnums(i);
    }
    
    for(int i = 4; i <= N; i+=2) {
        num += Ncr[i]*nums[i/2];
    }
    
    cout << num << endl;
    cin.get();
    return 0;
}

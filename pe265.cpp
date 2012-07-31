#include <iostream>
#define fori(n) for(int i=0; i<n; i++)
#define N 5

using namespace std;

int pow2(int n){
    int ret = 1;
    fori(n) ret *= 2;
    return ret;
}

unsigned long L = pow2(N);

void printBinary(unsigned int n) {
	unsigned int i;
	if(n<256) i = 1 << L - 1;
	else i = 1<<(sizeof(n) * 8 - 1);

	while (i > 0) {
		if (n & i)
		      cout << "1";
		else
			 cout << "0";
		i >>= 1;
	}
}

bool cycle(unsigned long n){
    bool in[L];
    fori(L) in[i] = false;
    unsigned long x = n;
    unsigned char bit = x&1;
    //printBinary(pow2(L)-1); cout << endl;
    for(int i=0; i<L; i++){
        //cout << (int)(x&(L-1)) << " " << (int)bit << endl;
        /*if(n==78617147) {
            printBinary(x&(pow2(L)-1)); 
            cout << " " << (int)(x&(L-1)) << endl; 
        }*/
        if(in[x&(L-1)])
             return false;
        in[x&(L-1)] = true;
        x >>= 1;
        x |= (bit<<(L-1));
        bit = x&1;
    }    
    
    fori(L) if(!in[i]) return false;
    return true;
}

int main(){
    unsigned long tot = 0;
    unsigned long bn = 0;
    for(unsigned long n=30000000; n<pow2(L-N); n++){
        if(cycle(n)){
             //cout << n << " is a loop" << endl;
             tot += n;
             if(tot > 1000000000){
                     tot -= 1000000000;
                    bn++;
            }
        }
        if(n%10000000 == 0) cout << n << endl;
    }  
    cout << bn << "000000000" << tot << endl;
    cin.get();
    return 0;
}

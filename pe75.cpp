#include <iostream>
#define fori(n) for(int i=0; i<n; i++)
#define N 1500

using namespace std;
int primes[N];
int z=0;

void init(){
	bool isPrime[N];
	fori(N) isPrime[i] = true;
	for(int i=2; i<N; i++){
		if(isPrime[i]==false) continue;
		primes[z++] = i;
		for(int j=i*2; j<N; j+=i) isPrime[j] = false;
	}
}

bool coprime(int m, int n){
	fori(z){
		if(primes[i] > n) break;
		if(n % primes[i] == 0 && m % primes[i] == 0) return false;
	}
	return true;
}

int main(){
	char numW[1500000];
	init();
	fori(1500000) numW[i] = 0;
	unsigned long t;
	//m even
	for(int m=2; m<N; m+=2){
		for(int n=1; n<m; n+=2){
			if(!coprime(m,n)) continue;
			//cout << m*m - n*n << " " << 2*m*n << " " << m*m + n*n << endl;
			t=2*m*m + 2*m*n;
			for(int k=1; k*t<1500000; k++){ 
                 ++numW[t*k]; 
            }
		}
	}
	cout << "half" <<endl;
	//m odd
	for(int m=3; m<N; m+=2){
		for(int n=2; n<m; n+=2){
			if(!coprime(m,n)) continue;
			//cout << m*m - n*n << " " << 2*m*n << " " << m*m + n*n << endl;
			t=2*m*m + 2*m*n;
			for(int k=1; k*t<1500000; k++){ 
                 ++numW[t*k]; 
            }
		}
	}

	int num = 0;
	fori(1500000){
		if(numW[i]==1) ++num;
	}

	cout << num << endl;

	cin.get();
	return 0;
}

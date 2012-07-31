#include <iostream>
#include <fstream>
#define fori(n) for(int i=0; i<n; i++)
#define forj(n) for(int j=0; j<n; j++)
#define N 1000000

using namespace std;

bool isprime[N];

void init(){
	for(int i=0 ;i<N; i++){
		isprime[i] = true;
	}
	for(int i=2; i<N;i++){
		if(isprime[i]){
			for(int j=2*i; j<N; j+=i) isprime[j] = false;
		}
	}
}

int main(){
	int n=0;
	init();
	for(int i=1; i<1200; i++){
		if(3*i*i+3*i+1>N) break;
		if(isprime[3*i*i + 3*i + 1]) n++;
	}
	cout <<n<< endl;
	//cin.get();
	return 0;
}

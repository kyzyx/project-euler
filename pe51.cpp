#include <iostream>
#include <fstream>
#define fori(n) for(int i=0; i<n; i++)
#define forj(n) for(int j=0; j<n; j++)
#define N 1000000

using namespace std;

int numPrimes = 0;
int primes[N/3];
bool checked[N];
bool isprime[N];

void genPrime(){
	fori(N) {
		isprime[i] = true;
	}
	for(int i=2; i<N; i++){
		if(isprime[i]){
			primes[numPrimes++] = i;
			for(int j=i*2; j<N; j+= i){
				isprime[j] = false;
			}
		}
	}
}

int pow10(int n){
	int r=1;
	fori(n) r *= 10;
	return r;
}

int powlog10(int n){
	if(n < 10) return 10;
	if(n < 100) return 100;
	if(n < 1000) return 1000;
	if(n < 10000) return 10000;
	if(n < 100000) return 100000;
	if(n < 1000000) return 1000000;
}

int tos(char* mask, int len, int sub){
	int ret = 0;
	fori(len){
		ret *= 10;
		if(mask[i] == '*') ret += sub;
		else ret += mask[i] - '0';
	}
	return ret;
}

int countMatches(char* mask, int len){
	int nm = 0;
	fori(10){
		if(i==0 && mask[0] == '*') continue;
		if(isprime[tos(mask, len, i)]){
			checked[tos(mask, len, i)] = true;
			nm++;
		}
	}
	return nm;
}

void ndigit(int i, int nd){
	int a,b;
	int wilda, wildb;
	char match[8];
	int k;
	for(int j=i+1; primes[j] < pow10(nd); j++){
			//if(checked[primes[j]]) continue;
			wilda = -1;
			wildb = -1;
			a = primes[i];
			b = primes[j];
			for(k=0; a>0; k++){
				if(a%10 != b%10){
					if(a%10 == wilda && b%10 == wildb){
						match[nd-k-1] = '*';
					}
					else if(wilda == -1){
						wilda = a%10;
						wildb = b%10;
						match[nd-k-1] = '*';
					}
					else break;
				}
				else {
					match[nd-k-1] = a%10 + '0';
				}
				a/=10; b/=10;
			}
			for(int x=0;x<nd;x++) if(match[x] == wilda + '0' || match[x] == wildb + '0') k=x;
			if(k==nd){
				match[k] = '\0'; 
				if(countMatches(match,nd) > 6){
					if(countMatches(match,nd) == 8){
                         cout << "*****";
                         cout << countMatches(match,nd) << ": " << match << "->" << primes[i] << " " << primes[j] << endl;
                         return;
                    }
					cout << countMatches(match,nd) << ": " << match << "->" << primes[i] << " " << primes[j] << endl;
				}
			}
		}

}


int main(){
	genPrime();
	cout << "Done generating primes" << endl;
	
	for(int i=0; i<numPrimes; i++){
		if(primes[i] < 10000) continue;
		//forj(N)checked[i] = false;
		if(primes[i] < 100000){
			ndigit(i,5);
		}
		else if(primes[i] < 1000000){
			ndigit(i,6);
		}
		else if(primes[i] < 10000000){
			ndigit(i,7);
		}
	}

	cin.get();
	return 0;
}

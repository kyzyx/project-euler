#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <string>
#define NUMPRIMES 14

using namespace std;
typedef mpz_class BigInt;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43};

BigInt best = 1;
BigInt goal = 4000000;


BigInt numfacs(string s){
	BigInt ret = 1;
	for(int i=0;i<13; i++){
		ret *= (s[i]-'0')*2+1;
		//cout << ret << endl;
	}
	return (ret+1)/2;
}

BigInt vals(string s){
	BigInt ret = 1;
	for(int i=0; i<13; i++){
		for(int j=0; j<s[i]-'0'; j++){
			ret *= primes[i];
		}
	}
	return ret;
}


void dump(string s) {
	for(int i = 0; i < s.size(); i++) cout << (int)(s[i]-'0') << " ";
}

string nextas(string s) {
	string ret = s;
	for(int i = 0; i < 13; i++) {
		ret[i] = ret[i] + 1;
		/*dump(ret);
		cout << endl;*/
		if (vals(ret) > best) {
			for(int j = 0; j <= i; j++) {
				ret[j] = ret[i+1]+1;
			}
			/*cout << "carry ";
			dump(ret);
			cout << endl;*/
		}
		else return ret;
	}
	return ret;
}



string next(string s) {
	string ret = nextas(s);
	while(numfacs(ret) < goal) {
		ret = nextas(ret);
	}
	return ret;
}


int main(){
	for(int i = 0; i < NUMPRIMES; i++) {
		best *= primes[i];
	}
	string s = next("1000000000000");
	while (s != "1111111111111") {
		BigInt tmp = vals(s);
		if (tmp < best) {
			best = tmp;
			dump(s);
			cout << ":" << best << endl;
		}
		s = next(s);

	}

	cout << "Best is " << best << endl;
}

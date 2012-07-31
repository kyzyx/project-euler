#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <gmp.h>
#include <gmpxx.h>
#define M 10

using namespace std;
typedef mpz_class BigInt;

int order[5][3] ={{0,1,2},{3,2,4},{5,4,6},{7,6,8},{9,8,1}};

int magic(int r[M]){
	int t[5];
	t[0] = r[0] + r[1] + r[2];
	for(int i=1; i<5; i++){
		t[i] = r[order[i][0]] + r[order[i][1]] + r[order[i][2]];
		if(t[i] != t[i-1]) return 0;
	}
    return t[0];
}

int indMin(int r[M]){
	int outer[5] = {r[0], r[3], r[5], r[7], r[9]};
	sort(outer, outer+5);
	if(outer[0] == r[0]) return 0;
	else if(outer[0] == r[3]) return 1;
	else if(outer[0] == r[5]) return 2;
	else if(outer[0] == r[7]) return 3;
	else return 4;
}

BigInt solset(int r[M]){
    BigInt ret = 0;
    int start = indMin(r);
	for(int i=start; i<5+start; i++){
		for(int j=0; j<3; j++){
			if(r[order[i%5][j]] == 10) ret *= 10;
			ret += r[order[i%5][j]];
			ret *= 10;
		}
	}
	ret /=10;
	return ret;
}

int main(){
    int r[M];
    for(int i=0; i<M; i++) r[i] = i+1;

	ofstream out("tmp.txt");

    int t = 0;
	BigInt max = 0;
	BigInt curr;
    BigInt e7("10000000000000000");
    do{
        if(magic(r)){
             curr = solset(r);
             cout << curr << endl;
             if(curr < e7 && curr > max) max = curr;
             //cin.get();
             ++t;
        }
    }while(next_permutation(r,r+M));
    cout << "Total = " << t << " Max = " << max << endl;
	out << max;
    cin.get();
    return 0;
}

#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define D 1000

using namespace std;
typedef mpz_class BigInt;

BigInt t = 0;

long next(){
	t = 615949*t+797807;
	t %= 1048576;
	return t.get_si()-524288;
}

int main(){
    long* grid[D];
	long* best[D];
    for(int i=0; i<D; i++){
		grid[i] = new long[i+1];
		best[i] = new long[i+1];
		grid[i][0] = next();
		//cout << grid[i][0] << " ";
		for(int j=1; j<=i; j++){
			grid[i][j] = grid[i][j-1] + next();
			//cout << grid[i][j] << " ";
		}
		//cout << endl;
	}
/*
	long grid[D][D] = {{15,0,0,0,0,0},
				       {-14,-7,0,0,0,0},
					   {20,-13,-5,0,0,0},
					   {-3,8,23,-26,0,0},
					   {1,-4,-5,-18,5,0},
					   {-16,31,2,9,28,3}};
	long* best[D];
	for(int i=0; i<D; i++){
		best[i] = new long[i+1];
		cout << grid[i][0] << " ";
		for(int j=1; j<=i; j++){
			grid[i][j] += grid[i][j-1];
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
cin.get();*/
	long total;
	long globalmin = 999;
	for(int i=0; i<D; i++){
		for(int j=0; j<=i; j++){
		//	cout << i << "," << j << ":";
			best[i][j] = grid[i][j];
			if(j!=0) best[i][j] -= grid[i][j-1];
			total = best[i][j];
			for(int k=1; k<D-i-j; k++){
				total += grid[i+k][j+k];
				if(j!=0) total -= grid[i+k][j-1];
				if(total < best[i][j]) best[i][j] = total;
		//		cout << total << " ";
			}
			//cout << best[i][j] << " ";
			if(best[i][j] < globalmin) globalmin = best[i][j];
			//cout << endl;
		}
		//cout << endl;
	}


	cout << globalmin << endl;
    return 0;
}
#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define D 2000

using namespace std;
typedef mpz_class BigInt;

int last[56];
int k = 0;


int next(){
	last[k] = last[(k+56-24)%56] + last[(k+1)%56]+1000000;
	last[k] = last[k]%1000000 - 500000;
	k = (k+1)%56;
	return last[k];
}


int main(){
	BigInt tmp;
	for(int i=1; i<56; i++){
		tmp = i;
		tmp = (100003 - 200003*tmp + 300007*(tmp*tmp*tmp)) % 1000000 -500000;
		last[i] = tmp.get_si();
	}
	int* grid[D];		//Needs dynamic allocation to allocate from heap
	for(int i=0; i<D; i++){
		grid[i] = new int[D];
		for(int j=0; j<D; j++){
			//cout << i << " " << j << " " << next() << endl;
			grid[i][j] = next();
		}
	}
	cout << "a" << endl;
	int globalmax = 0;
	int workmax[D];
	int currmax;
	cout << "a" << endl;
	for(int i=0; i<D; i++){
		//Cols
		workmax[0] = grid[i][0];
		currmax = workmax[0];
		for(int j=1; j<D; j++){
			workmax[j] = max(grid[i][j], workmax[j-1]+grid[i][j]);
			currmax = max(workmax[j], currmax);
		}
		if(currmax > globalmax){
			currmax = workmax[D-1];
			cout << "Row max " << globalmax << " at " << i << endl;
		}

		//Rows
		workmax[0] = grid[0][i];
		currmax = workmax[0];
		for(int j=1; j<D; j++){
			workmax[j] = max(grid[j][i], workmax[j-1]+grid[j][i]);
			currmax = max(workmax[j], currmax);

		}
		if(currmax > globalmax) {
			globalmax = currmax;
			cout << "Col max " << globalmax << " at " << i << endl;
		}
		//Diagonals
		workmax[0] = grid[i][0];
		currmax = workmax[0];
		for(int j=1; j<D-i; j++){
			workmax[j] = max(grid[j+i][j], workmax[j-1]+grid[j+i][j]);
			currmax = max(workmax[j], currmax);
		}

		if(currmax > globalmax){
			globalmax = currmax;
			cout << "Diagonal max " << globalmax << endl;
		}
		workmax[0] = grid[0][i];
		currmax = workmax[0];
		for(int j=1; j<D-i; j++){
			workmax[j] = max(grid[j][j+i], workmax[j-1]+grid[j][j+i]);
			currmax = max(workmax[j], currmax);
		}
		if(currmax > globalmax){
			globalmax = currmax;
			cout << "Diagonal max " << globalmax << endl;
		}

		//Antidiagonals
		workmax[0] = grid[i][D-1];
		currmax = workmax[0];
		for(int j=1; j<D-i; j++){
			workmax[j] = max(grid[j][D-i-j-1], workmax[j-1]+grid[j][D-i-j-1]);
		}
		if(currmax > globalmax) {
			globalmax = currmax;
			cout << "Antidiagonal max " << globalmax << endl;
		}
		workmax[0] = grid[0][i];
		currmax = workmax[0];
		for(int j=1; j<D-i; j++){
			workmax[j] = max(grid[D-i-j-1][j], workmax[j-1]+grid[D-i-j-1][j]);
		}
		if(currmax > globalmax) {
			globalmax = currmax;
			cout << "Antidiagonal max " << globalmax << endl;
		}
	}

	cout << globalmax << endl;

	return 0;
}
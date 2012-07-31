#include <fstream>
#include "sudoku.h"

char sample[9][9];

int main(){
	ifstream in("su.txt");
	int n = 50;
	int t = 0;
	int tmp;
	for(int z=0;z<n;z++){
		fori(9){
			forj(9){
				in >> sample[i][j];
				//cout << sample[i][j];
			}
			//cout << endl;
			in.get();
		}
		cout << z+1 << endl;
	    tmp = solveSudoku(sample);
        //cout << tmp << " ";
        //if(z%4==3) cout << endl;	
	    t += tmp;	
	}
	
    cout << t << endl;
	
    cin.get();
	return 0;
}

#include "sudoku.h"
#define DEBUG 1

int check(char sc[9][9]){
    fori(9){
		forj(9){
            if(sc[i][j] == '0') continue;
			for(int k=0; k<9; k++){
				if(k!=i && sc[k][j] == sc[i][j]){
                     if(DEBUG) cout << i << " " << j << ", " << k << " " << j << endl;
                     return -1;
                }
				if(k!=j && sc[i][k] == sc[i][j]){
                     if(DEBUG) cout << i << " " << j << ", " << i << " " << k << endl;
                     return -1;
                }
			}
		}
	}
	
	bool in[9];
	for(int r=0; r<9; r+=3){
		for(int c=0; c<9; c+=3){
            fori(9) in[i] = false;
			fori(3){
				forj(3){
                    if(sc[i+r][j+c] == '0') continue;
					if(in[sc[i+r][j+c] - '1'] == false){
                        in[sc[i+r][j+c] - '1'] = true;
                    }
                    else{
                         if(DEBUG) cout << "box" << r << " " << c << endl;
                         return -1;
                    }
				}
			}
		}
	}
	return 1;
}

int guess(char sc[9][9], char doku[9][9][9], int minNs){
     if(check(sc) == -1) return 0;
     //make a guess
     int ns = 0;
     int in[9];
     fori(9){
        forj(9){
            ns = 0;
            if(sc[i][j] != '0') continue;
            for(int k=0; k<9; k++){
                if(doku[i][j][k] == 1) in[ns++] = k;
            }
            if(ns == minNs){
                for(int k=0; k<ns; k++){
                    sc[i][j] = in[k]+'1';
                    if(check(sc) == -1) return 0;
                    int vtmp = solveSudoku(sc);
                    if(vtmp != 0) return vtmp;
                }
                return 0;
            }
        }
     }
}

int solveSudoku(char origsudoku[9][9]){	
    //Copy, preserving original
    char sudoku[9][9];
    fori(9){
        forj(9){
            sudoku[i][j] = origsudoku[i][j];
        }
    }
    
    //Populate possibility table
	char doku[9][9][9];
	fori(9){
		forj(9){
			for(int k=0; k<9; k++){
				if(sudoku[i][j] != '0'){
					if(sudoku[i][j] == '1'+k) doku[i][j][k] = 1;
					else doku[i][j][k] = 0;
				}
				else doku[i][j][k] = 1;
			}
		}
	}
    
    //Find all
    int tmp;
	while(true){
        tmp = fill(sudoku, doku);
        if(tmp == 0) break;
        if(tmp == -1) return 0;
    }
    if(check(sudoku) == -1) return 0;
    //copy sudoku
    int minNs = 10; 
    int cNs;
	char sc[9][9];
	fori(9){
        forj(9){
            sc[i][j] = sudoku[i][j];
            if(sudoku[i][j] != '0') continue;
            cNs = 0;
            for(int k=0; k<9; k++) 
                if(doku[i][j][k]) cNs++;
            if(cNs < minNs) minNs = cNs;
        }
    }
	
	if(done(sc)){
        if(DEBUG && check(sc) == 1){
            cout << "---------" << endl;
            fori(9){
                forj(9){
                    cout << sc[i][j];
                }
                cout << endl;
            }
            cout << "--------" << endl;
        }
        return val(sc);
    }
	else{
        return guess(sc, doku, minNs);
    }
}

//---------------------------\\

bool done(char sudoku[9][9]){
    fori(9){
        forj(9){
            if(sudoku[i][j] == '0') return false;
        }
    }
    return true;
}

int val(char sudoku[9][9]){
    return (sudoku[0][0]-'0')*100 + (sudoku[0][1]-'0')*10 + (sudoku[0][2]-'0');
}

int fill(char sudoku[9][9], char doku[9][9][9]){
    //Fill in rows and columns
	fori(9){
		forj(9){
			for(int k=0; k<9; k++){
				if(k!=i && sudoku[k][j] != '0'){
					doku[i][j][sudoku[k][j]-'1'] = 0;
				}
				if(k!=j && sudoku[i][k] != '0'){
					doku[i][j][sudoku[i][k]-'1'] = 0;
				}
			}
		}
	}
	//Fill in boxes
	bool in[9];
	for(int r=0; r<9; r+=3){
		for(int c=0; c<9; c+=3){
			fori(9) in[i] = false;
			fori(3){
				forj(3){
					if(sudoku[i+r][j+c] != '0'){
						in[sudoku[i+r][j+c] - '1'] = true;
					}
				}
			}
			fori(3){
				forj(3){
					if(sudoku[i+r][j+c] != '0') continue;
					for(int k=0; k<9; k++){
						if(in[k]) doku[i+r][j+c][k] = 0;
					}
				}
			}
		}
	}
	
	int change = 0;
	
	char onlyone = -1;
	fori(9){
		forj(9){
            if(sudoku[i][j] != '0') continue;
            onlyone = -1;
			for(int k=0; k<9; k++){
				if(doku[i][j][k] == 1){
					if(onlyone == -1) onlyone = k+1;
					else{
                        onlyone = 0;
                        break;
                    }
				}
			}
			if(onlyone > 0){
                 sudoku[i][j] = '0' + onlyone;
                 change = 1;
            }
			if(onlyone == -1){
                 return -1;
            }
		}
	}

	return change;
}

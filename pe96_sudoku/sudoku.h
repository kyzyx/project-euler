#include <iostream>
#define fori(n) for(int i=0; i<n; i++)
#define forj(n) for(int j=0; j<n; j++)

using namespace std;


int fill(char sudoku[9][9], char doku[9][9][9]);

int guess(char sc[9][9], char doku[9][9][9], int minNs);

bool done(char sudoku[9][9]);

int val(char sudoku[9][9]);

int solveSudoku(char origsudoku[9][9]);




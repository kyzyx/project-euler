#include <iostream>
#include <fstream>
#include <cstdlib>

#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)
#define fork(N) for(int k=0; k<N; k++)
#define min(a,b) a<b?a:b
using namespace std;

typedef queue<int> qi;


int main(){
    int mat[81][81];
    unsigned long sum[81][81];
    int done[81][81];
    //qi x, y,s; 
    ifstream fin("matrix.txt");
    int n = 80;
    fori(n){
        forj(n){
            fin >> mat[i][j];
            fin.get();
            sum[i][j] = 9999999;
            done[i][j] = 0;
        }
    }


    done[0][0] = 1;
    sum[0][0] = mat[0][0];
    bool change = true;
    fork(n*n){
        if(!change) break;
        change = false;
        fori(n){
            forj(n){
                if(done[i][j] == k+1){
                    if(sum[i][j+1] > mat[i][j+1] + sum[i][j]){
                        sum[i][j+1] = mat[i][j+1] + sum[i][j];
                        done[i][j+1] = k+2;
                        change = true;
                    }
                    if(j>0 && sum[i][j-1] > mat[i][j-1] + sum[i][j]){
                        sum[i][j-1] = mat[i][j-1] + sum[i][j];
                        done[i][j-1] = k+2;
                        change = true;
                    }
                    if(sum[i+1][j] > mat[i+1][j] + sum[i][j]){
                         sum[i+1][j] =  mat[i+1][j] + sum[i][j];
                         done[i+1][j] = k+2;                        
                         change = true;
                         
                    }
                    if(i>0 && sum[i-1][j] > mat[i-1][j] + sum[i][j]){
                         sum[i-1][j] =  mat[i-1][j] + sum[i][j];
                         done[i-1][j] = k+2;                        
                         change = true;
                    }
                }
                //cout << sum[i][j] << " ";
            }
            //cout << endl;
        }
        //cout << "---------" << endl;
        //cin.get();
    }
    cout << sum[n-1][n-1];
    
    cin.get();
    return 0;   
}

#include <iostream>
#include <fstream>
#include <string>
#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)
#define abs(n) n>0?n:-n

using namespace std;

int dist[52][52];

bool abc(int a, int b, int c){
    if(c > a && c > b) return a+b == c;
    else if(a>b && a>c) return b+c == a;
    else if(b>a && b>c) return a+c == b;
    return false;
}


int main(){
    int n = 51;
    
    int numIn = 0;
    
    fori(n){
        forj(n){
            dist[i][j] = i*i + j*j;
        }
    }        
    int tmp;
    fori(n){
        forj(n){
            if(i == 0 && j == 0) continue;
            for(int a = i; a<n; a++){
                for(int b = 0; b<n; b++){
                    if(b == j) continue;
                    if(a == 0 && b == 0) continue;
                    if(a!=0 && i!=0 && double(b)/a == double(j)/i) continue;      
                    
                    if(b-j>0) tmp = b-j;
                    else tmp = j-b;
                              
                    if(a == 0 && j == 0 || i == 0 && b == 0){
                         ++numIn;
                        continue;
                    }
                                         
                    if(abc(dist[a][b],dist[i][j],dist[a-i][tmp])){
                         //cout << "Works" << endl;
                         ++numIn;
                    }
                }
            }
        }
    }
    
    cout << numIn;
    
    cin.get();
    return 0;
}

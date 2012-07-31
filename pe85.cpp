#include <iostream>
#include <fstream>

#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)
#define max(a,b) a>b?a:b
#define abs(a) a>0?a:-a

using namespace std;

int numRects(int x, int y){
    int n = 0;
    //Foreach starting coord
    fori(x){
        forj(y){
            n += (x-i)*(y-j);
        }
    }
    return n;
}

int main(){ 
    int cd = 2000000;
    int tmp;
    int c[2];
    for(int i=2; i<150; i++){
        for(int j=i; j<150; j++){
            tmp = numRects(i,j);
            //cout << tmp << endl;
            if(tmp-2000000 < 100 && tmp-2000000 > -100) cout << tmp << " with " <<i << "x" << j << endl;
        }
    }
    //cout << cd << " with " << c[0] << "x" << c[1] << endl;
    cin.get();
    return 0;
}   

#include <iostream>
#include <fstream>
#include <cmath>
#define fori(N) for(int i=0; i<N; i++)
#define forj(N) for(int j=0; j<N; j++)

using namespace std;

int main(){
    ifstream in("base_exp.txt");
    double max = 0;
    int maxi, a, b;
    
    fori(1000){
        in >> a;
        in.get();
        in >> b;
        in.get();
        if(log(a)*b > max){
             max = log(a)*b;
             maxi = i+1;
             //cout << i+1 << ":"<< a << "^" << b << "= exp " << log(a)*b << endl;
        }
        //
        //cin.get();
    }
    cout <<maxi << endl;
    cin.get();
    return 0;
}

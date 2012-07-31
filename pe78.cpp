/* Used Euler's Recurrence Relation as in http://mathworld.wolfram.com/PartitionFunctionP.html
*/
#include <iostream>
#define MAX 60000

using namespace std;

int part[MAX];

int p(int n){
    if(n>=0) return part[n];
    else return 0;
}

int main(){
    for(int i=0; i<MAX; i++) part[i] = 0;
    part[0] = 1;
    part[1] = 1;
    part[2] = 2;
    
    int plus, minus;
    
    for(int i=3; i<MAX; i++){
        minus = 0; plus = 0;
        for(int k=1; k<=i; k++){
            if(i - (3*k*k-k)/2 < 0) break;
            if(k%2){
                 plus += p(i - (3*k*k-k)/2) + p(i - (3*k*k+k)/2);
                 if(plus > 1000000) plus %= 1000000;
            }
            else{
                 minus += p(i - (3*k*k-k)/2) + p(i - (3*k*k+k)/2);
                 if(minus > 1000000) minus %= 1000000;
            }
            part[i] = (plus-minus+1000000)%1000000;
        }
        if(part[i] == 0) {
            cout << i << endl;
            break;
        }
        if(i%1000 == 0) cout << i << ":" << part[i] << endl;
    }
    
    cin.get();
    return 0;   
}

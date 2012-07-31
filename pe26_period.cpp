#include <iostream>
#define fori(N) for(int i=0; i<N; i++)

using namespace std;

int lenPer(int n){
    int rem[n];
    fori(n) rem[i] = 0;
    bool done = false;
    
    int subtractFrom = 1;
    
    int remainder;
    int j;
    for(j=0; !done; j++){
        subtractFrom *= 10;
        while(subtractFrom < n){
            subtractFrom *= 10;
            j++;
        }
        remainder = subtractFrom-(subtractFrom/n)*n;
        //cout << subtractFrom << "-" << (subtractFrom/n)*n << "=" << remainder << endl;
        if(remainder == 0) break;
        if(rem[remainder]){
             //cout << "happened at " << rem[remainder];
             done = true;
        }
        else rem[remainder] = j+1;
        subtractFrom = remainder;
    }
    if(remainder == 0) return 0;
    else return (j-rem[remainder]);
}


int main(){
    int max = 0;
    int mi = 0;
    for(int i=2; i<1000; i++){
        if(lenPer(i) > max){
             max = lenPer(i);
             mi = i;
        }
    }
    cout << mi << ":" << max << endl;
    cin.get();
    return 0;
}

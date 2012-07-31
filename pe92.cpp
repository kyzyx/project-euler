#include <iostream>
#define MAX 10000000
#define fori(n) for(int i = 0; i < n; i++)

using namespace std;

int i89[MAX];

int dodigit(int n){
    int t = 0;
    int d;
    while(n>0){
        d = n%10;
        //do something
        t += d*d;
        //end
        n/=10;
    }
    return t;
}

int is89(int n){
        if(n == 89) return 1;
        if(n == 1) return 0;
        if (i89[n] != -1) return i89[n];
        i89[n] = is89(dodigit(n));
        return i89[n];
}

int main(){
    fori(MAX) i89[i] = -1;
    int n=0;
    for(int i=2; i<MAX; i++) if(is89(i) == 1) n++;
    cout << n << endl;
    
    cin.get();
    return 0;   
}

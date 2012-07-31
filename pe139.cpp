#include <iostream>
#define fori(n) for(int i=0; i<n; i++)
#define N 7080 //sqrt(5e7)
#define MAX 100000000

using namespace std;

int euclid(int m, int n){
    if(n == 0) return m;
    if(m>n) return euclid(n,m-n);
    else return euclid(m,n-m);
}

bool coprime(int m, int n){
	return euclid(m,n) == 1;
}

bool tiles(unsigned long a, unsigned long b, unsigned long c){
    if(a>b){
        if(c%(a-b) == 0) return true;
        else return false;
    }
    else{
        if(c%(b-a) == 0) return true;
        return false;
    }
}

int main(){
    unsigned long a, b, c,p;
    unsigned long t = 0;
	//m even
	for(int m=2; m<N; m+=2){
		for(int n=1; n<m; n+=2){
			if(!coprime(m,n)) continue;
		    a = m*m - n*n;
		    b = 2*m*n;
		    c = m*m + n*n;
		    if(tiles(a,b,c)){
                // cout << a << " " << b << " " << c << endl;
                p = a+b+c;
                for(int i=1; p*i < MAX; i++, t++);
            }
        }
	}
	cout << "half" <<endl;
	//m odd
	for(int m=3; m<N; m+=2){
		for(int n=2; n<m; n+=2){
			if(!coprime(m,n)) continue;
            a = m*m - n*n;
		    b = 2*m*n;
		    c = m*m + n*n;
		    if(tiles(a,b,c)){
                // cout << a << " " << b << " " << c << endl;
                p = a+b+c;
                for(int i=1; p*i < MAX; i++, t++);
            }
		}
	}

    cout << t << endl;

	cin.get();
	return 0;
}

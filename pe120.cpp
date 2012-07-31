#include <iostream>
#include <fstream>
#define fori(n) for(int i=0; i<n; i++)
#define forj(n) for(int j=0; j<n; j++)
#define N 1000

using namespace std;

struct recur{
	int k;
	int p;
};

int ap1[N*N+1];
int am1[N*N+1];

//Returns period
recur genpowmod(int* arr, int a, int n){
	int i=0;
	recur ret;
	ret.p = 0;
	a %= n; 
	arr[0] = 1;
	for(i=0; i<N*N+1; i++){
		arr[i+1] = (arr[i]*a)%n;
		forj(i){
			if(arr[j] == arr[i]){
				ret.p = i-j;
				break;
			}	
		}
		if(ret.p!=0) break;
	}
	ret.k=i-ret.p;
	return ret;
}

int maxr(int z){
	recur pp1 = genpowmod(ap1,z+1,z*z);
	recur pm1 = genpowmod(am1,z-1,z*z);
	
	//cout << pp1.p << " " << pp1.k << endl;
	//cout << pm1.p << " " << pm1.k << endl;
	
	int period = 0;
	for(int i=pp1.k; period==0 && i<N*N+1; i+=pp1.p){
		for(int j=pm1.k; period==0 && j<=i; j+=pm1.p){
			if(j==i) period = j;
		}
	}
	
	int tmp, max = 0;
	fori(period){
		//cout << ap1[(i-pp1.k)%pp1.p] << " " << am1[(i-pm1.k)%pm1.p] << endl;
		tmp = (ap1[(i-pp1.k)%pp1.p]+am1[(i-pm1.k)%pm1.p])%(z*z);
		if(tmp > max) max = tmp;
		if(max == z*z-1) break;
	}
	return max;
}

int main(){
	unsigned long total=0;
	//recur r=genpowmod(ap1,4,9);
	//fori(r.p+r.k)cout <<ap1[i]<<endl;
	for(int z=3; z<=N; z++){
		total += maxr(z); 
		//if(z<=7) cout << maxr(z) << endl;
		if(z%100==0) cout << z << endl;
	}
	
	cout << endl << total << endl;
	//cin.get();
	return 0;
}

#include <iostream>
#define fori(n) for(int i=0; i<n; i++)
using namespace std;

int main(){
	int numways[171][3];
	int checkout[171];
	fori(171){
		numways[i][0] = 0;
		numways[i][1] = 0;
		numways[i][2] = 0;
		checkout[i] = 0;
	}

	for(int i=1; i<=20; i++){
		numways[i][0]++;
		numways[2*i][0]++;
		numways[3*i][0]++;
	
	}
	numways[25][0]++;
	numways[50][0]++;
	for(int i=0; i<=60; i++){
		numways[2*i][1] += (numways[i][0]*(numways[i][0]+1))/2;
		for(int j=i+1; j<=60; j++){
			numways[i+j][1] += numways[i][0] * numways[j][0];
		}
	}
		
	for(int i=0; i<121; i++){
		numways[i][2] = numways[i][0] + numways[i][1];
	}

	//Checkout w/ double
	for(int i=2; i<=40; i+=2){
		checkout[i]++;
		for(int j=0; j<121; j++){
			checkout[i+j] += numways[j][2];
		}
	}
	int i = 50;
	checkout[i]++;
	for(int j=0; j<121; j++){
		checkout[i+j] += numways[j][2];
	}
	//count
	int tot = 0, tot100 = 0;
	for(int i=0; i<171; i++){
		tot += checkout[i];
		if(i<100) tot100 += checkout[i]; 
	}
	cout<< tot << ";" << tot100 << endl;
	/*
	for(int i=0; i<15; i++){
		cout << i << ": " << numways[i][0] << " " << numways[i][1] << endl;
	}
	int a = 0;	
	cin >> a;
	while(a!=-1){
		cout << checkout[a] << endl;
		cin >> a;
	}
*/

	return 0;
}

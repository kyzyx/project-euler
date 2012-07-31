#include <iostream>
#define fori(n) for(int i=0; i<n; i++)

using namespace std;
unsigned long squares[65000];

int issquare(unsigned long n, int h=65000, int l=0){
	if(l>h || (l==h && n!=squares[l])) return 0;
	int mid = (h+l)/2;
	if(n < squares[mid]){
		if(mid==h) return 0;
		return issquare(n,mid,l);
	}
	else if(n > squares[mid]){
		if(mid ==l) return 0;
		return issquare(n,h,mid);
	}
	else return mid;
}

int main(){
	for(unsigned long i=0; i<65000; i++){
		squares[i] = i*i;
		//if(i<100)cout<< squares[i]<<" ";
	}
	unsigned long t = 0;
	unsigned long n,tmp;
	for(unsigned long i=1; i<65000; i++){
		if(issquare(3*squares[i]+1)){
			tmp = issquare(3*squares[i]+1);
			n=2*i - tmp;
			if(n>0){
				cout << "a-" << i << " " << n << ":" << squares[i] - n*n << " " << 2*i*n << "  " << squares[i] + n*n << endl;
				t += 2*squares[i] + 2*n*n + 4*i*n;
			}
			//cout << "3*"<<i<<"^2+1" << endl;
		}
		if(issquare(3*squares[i]-1)){
			tmp = issquare(3*squares[i]-1);
			n=2*i - tmp;
			if(n>0){
				cout << "a+" << i << " " << n << ":" << squares[i] - n*n << " " << 2*i*n << "  " << squares[i] + n*n << endl;
				t += 2*squares[i] + 2*n*n + 4*i*n;
			}//cout << "3*"<<i<<"^2+1" << endl;
		}
		//if(i%2 == 0){
			if(squares[i]%3 == 1 && issquare((squares[i] - 1)/3)){
				n = issquare((squares[i] -1)/3);
				if(4*squares[i] < 1000000000) {
                     t += 4*squares[i];
                    cout << "b-" << i << " " << n << ":" << squares[i] - n*n << " " << 2*i*n << "  " << squares[i] + n*n << endl;
                }
				//cout <<i<<"^2-1 / 3" << endl;
			}
			if(squares[i]%3 == 2 && issquare((squares[i] + 1)/3)){
				n = issquare((squares[i] + 1)/3);
				if(4*squares[i] < 1000000000){
                    cout << "b+" << i << " " << n << ":" << squares[i] - n*n << " " << 2*i*n << "  " << squares[i] + n*n << endl;
				    t += 4*squares[i];
                }
				///cout <<i<<"^2-1 / 3" << endl;
			}
		//}
	}
	 cout << t << endl;
	 
	 cin.get();
	return 0;
}

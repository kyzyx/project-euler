/* took ~ 2:20
Correct solution: Use Pell Equation & convergents.
*/
#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define M 12
#define LIM 10000000
#define fori(n) for(int i=0; i<n; i++)

using namespace std;
typedef mpz_class BigInt;
BigInt squares[LIM];

unsigned long issquare(BigInt n, int h=LIM, int l=0){
	if(n > squares[LIM-1]){
		if(mpz_perfect_square_p(n.get_mpz_t())){
			BigInt tmp1, tmp2;
			mpz_sqrtrem(tmp1.get_mpz_t(), tmp2.get_mpz_t(),n.get_mpz_t());
			if(tmp2 == 0) return tmp1.get_ui();
			else return 0;
		}
		else return 0;
	}
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
	for(BigInt i=0; i<LIM; i++){
		squares[i.get_ui()] = i*i;
		//if(i<100)cout<< squares[i]<<" ";
	}

	cout << "ready" << endl;
	BigInt t = 0;
	int ns = 0;
	BigInt m,tmp;
	for(unsigned long i=1; ns<M && i<LIM; i++){
		if(issquare(5*squares[i]+1)){
			tmp = issquare(5*squares[i]+1);
			m=2*i + tmp;
			cout << "a-" << m << " " << i << ":" << m*m - squares[i] << " " << 2*i*m << "  " << squares[i] + m*m << endl;
			ns++;
			t += squares[i] + m*m;
		}
		if(issquare(5*squares[i]-1)){
			tmp = issquare(5*squares[i]-1);
			m=2*i + tmp;
			cout << "a+" << m << " " << i << ":" << m*m - squares[i] << " " << 2*i*m << "  " << squares[i] + m*m << endl;
			ns++;
			t += squares[i] + m*m;
		}
		/*if(issquare(5*squares[i]+2)){
			tmp = issquare(5*squares[i]+2);
			m=i + tmp;
			if(m%2 == 0){
				m/=2;
				cout << "b-" << m << " " << i << ":" << m*m - squares[i] << " " << 2*i*m << "  " << squares[i] + m*m << endl;
				ns++;
				t += squares[i] + m*m;
				//t += 2*squares[i];
			}
			//cout << "3*"<<i<<"^2+1" << endl;
		}
		if(issquare(5*squares[i]-2)){
			tmp = issquare(5*squares[i]-2);
			m=i + tmp;
			if(m%2 == 0){
				m/=2;
				cout << "b+" << m << " " << i << ":" << m*m - squares[i] << " " << 2*i*m << "  " << squares[i] + m*m << endl;
				ns++;
				t += squares[i] + m*m;
				//t += 2*squares[i] + 2*n*n + 4*i*n;
			}//cout << "3*"<<i<<"^2+1" << endl;
		}*/
	}
	 cout << t << endl;

	 //cin.get();
	return 0;
}

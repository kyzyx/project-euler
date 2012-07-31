#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define N 112

using namespace std;
typedef mpz_class BigInt;

BigInt dp[N][N+1];

void fill(){
	//Reset
	for(int i=0; i<N; i++){
		for(int j=0; j<=N;j++){
			if(j==0) dp[i][j] = 1;
			else dp[i][j] = 0;
		}
	}
	//Set
	for(int i=1; i<N-1; i++){
		for(int j=1; j<=i; j++){
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
}

BigInt nstatic(int places, int digs){

}

int main(){
	fill();
	int ndigs = 100;
	int d = 9;
	cout << dp[ndigs+d][d] << endl;
	cout << dp[ndigs+d+1][d+1] << endl;
	cout << 9*(ndigs+1)<< endl;
	cout << dp[ndigs+d][d] + dp[ndigs+d+1][d+1] - 10*(ndigs) - 2 << endl;
	//9ndigs for duplicated 111, 222 etc. ndigs for 0,00,000; 1 for 0, and 1 for empty number
	return 0;
}

/*BigInt divs(int spots, int ndivs){
    if(dp[spots][ndivs] != -1) return dp[spots][ndivs];
    BigInt tot = 0;
    for(int i=0; i<=spots; i++){
    	tot += divs(spots-i, ndivs-1);
    }
    dp[spots][ndivs] = tot;
    return tot;
}

void fill(){
	//Reset
	for(int i=0; i<101; i++){
	   	for(int j=0; j<11;j++){
	   	    if(i==0 || j==0) dp[i][j] = 1;
	   	    else dp[i][j] = 0;
	   	}
    }
    //Set
	for(int i=1; i<101; i++){
		for(int j=1; j<11; j++){
			for(int k=0; k<=i; k++){
				dp[i][j] += dp[i-k][j-1];
			}
		}
	}
}

int main(){
    fill();
	cout << "  ";
	for(int i=0; i<6; i++) cout << i << "\t";
	cout << endl;
	for(int i=0; i<11; i++){
		cout << i << ":";
		for(int j=0; j<6; j++){
			cout << dp[i][j] << "\t";
		}
		cout << endl;
	}

	cout << dp[6][9] << endl;
	cout << dp[6][10] << endl;

    return 0;
}*/
#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define L 21

using namespace std;
typedef mpz_class BigInt;

BigInt nums[10][10][L];
BigInt tot[L];

int main(){
    for(int i=0; i<10; i++){
        for(int j=0; j<=9-i; j++){
             for(int m=0; m<L; m++){
                nums[i][j][m] = 0;
            }
            if(i+j<=9) nums[i][j][2] = 1;
            //nums[i][j][3] = 10-i-j;
        }
    }

    for(int m=2; m<L; m++){
        tot[m] = 0;
        for(int i=0; i<10; i++){
            for(int j=0; j<=9-i; j++){
                for(int k=0; k<=9-i-j; k++){
                    nums[j][k][m+1] += nums[i][j][m];
                }
            }
        }
    }
    for(int m=2; m<L; m++){
        for(int i=0; i<10; i++){
            for(int j=0; j<=9-i; j++){
                tot[m] += nums[i][j][m];
            }
        }
        cout << m << ":" << tot[m] << endl;
    }

	BigInt ret = tot[L-1];
	for(int i=0; i<10; i++){
		ret -= nums[i][0][L-1];
	}

    cout << ret << endl;

    cin.get();
    return 0;
}

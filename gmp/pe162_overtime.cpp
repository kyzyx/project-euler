/* Time: <3:00
Correct: reduce number of genNum calls
Correct: PIE
*/
#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define L 16

using namespace std;
typedef mpz_class BigInt;

BigInt zero(0);

BigInt pow16[17];
BigInt sum16[17];

BigInt genNum(int nd, int isn, BigInt rel){
    if(nd == L){
        if(isn == 7) return rel;
        else return zero;
    }
    else if(nd == L-2 && isn == 0) return zero;
    if(isn == 7) return sum16[L-nd]*rel;
    else{
        BigInt t = 0;
        t += genNum(nd+1, isn | 1, rel);
        t += genNum(nd+1, isn | 2, rel);
        t += genNum(nd+1, isn | 4, rel);
        t += genNum(nd+1, isn, rel*13);
        return t;
    }
}

int main(){
	pow16[0] = 1;
	sum16[0] = 1;
	for(int i=1; i<17; i++){
		pow16[i] = 16*pow16[i-1] ;
		sum16[i] = sum16[i-1]+pow16[i];
	}
    cout << "2 * " << genNum(1,2,1) << endl;
    //cout << genNum(1,4,1) << endl;
    cout << genNum(1,0,13) << endl;

    //cout << "--------\n" << t << endl;
    cin.get();
    return 0;
}

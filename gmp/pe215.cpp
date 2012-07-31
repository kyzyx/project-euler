#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define C 32
#define R 10

using namespace std;
typedef mpz_class BigInt;

class row{
    public:
        //bool crack[C];
        int* sum;
        string s;
        row(){
            //for(int i=0; i<C; i++) crack[i] = false;
            s = "";
        }
        row(string st){
            sum = new int[st.length()+1];
            sum[0] = 0;
            for(int i=0; i<st.length(); i++) sum[i+1] = sum[i] + st[i] - '0';
            s = st;
        }
};

BigInt dp[R][4000];
row ways[4000];
bool allowed[4000][4000];
int numways = 0;

void generateRow(string s, int sum){
    if(sum == C){
         //cout << s << endl;
         ways[numways++] = row(s);
    }
    else{
        if(sum+3<=C) generateRow(s + '3', sum+3);
        if(sum+2<=C) generateRow(s + '2', sum+2);
    }
}

int main(){
    generateRow("", 0);
    cout << "Done generating " << numways << " rows" << endl;
    int l,k,t;
    for(int i=0; i<numways; i++){
        for(int j=0; j<numways; j++){
            if(i == j) allowed[i][j] = false;
            else{
                allowed[i][j] = true;
                l = 1;
                k = 1;
                while(ways[j].sum[l] != C && ways[i].sum[k] != C){
                    if(ways[i].sum[k] == ways[j].sum[l]){
                        allowed[i][j] = false;
                        break;
                    }
                    else if(ways[i].sum[k] > ways[j].sum[l])++l;
                    else ++k;
                }
            }
            //if(allowed[i][j]) cout << 1;
            //else cout << 0;
        }
        //cout << endl;
        dp[0][i] = 1;
    }
    cout << "Done generating table" << endl;

    BigInt tot = 0;
    for(int i=1; i<R; i++){
        for(int j=0; j<numways; j++){
            dp[i][j] = 0;
            for(int k=0; k<numways; k++){
                if(allowed[j][k]) dp[i][j] += dp[i-1][k];
            }
            if(i == R-1){
                tot += dp[i][j];
            }
        }
    }
    cout << "Total: " << tot << endl;
    cin.get();
    return 0;
}

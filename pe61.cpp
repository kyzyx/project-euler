#include <iostream>
#include <fstream>
#include <string>
#include "util.h"

using namespace std;

int fNum[6][9000];
int c[6];
ofstream out;
int z = 0;
string s[3000];

void chain(string curr, char l[6]){
    if(curr.length() == 14){
         s[z++] = curr;
         out << curr << endl;
         return;
    }
    fori(6){
        if(l[i] == i+'0') continue;
        forj(c[i]+1){
            if(fNum[i][j] == 0) continue;
            if(fNum[i][j]/100 == 10*(curr[curr.length()-2]-'0') + curr[curr.length()-1]-'0'){
                //cout << curr << fNum[i][j]%100 << endl;
                char tmp[6];
                fork(6) tmp[k] = l[k];
                tmp[i] = (char)(i+'0');
                string t = curr+(char)((fNum[i][j]/10) %10 + '0');
                chain(t+(char)(fNum[i][j]%10+'0'),tmp);
            }
        }
    }
}
string tos(int n){
    string ret = "    ";
    fori(4){
        ret[3-i] = (char)(n%10+'0');
        n/=10;
    }
    return ret;
}

int main(){
    fori(6) c[i] = 0;
    bool done[6];
    fori(6) done[i] = false;
    for(int i=10; i<300; i++){
        forj(6){
            if(done[j]) continue;
            if(fignum(j+3,i) < 1000) continue;
            if(fignum(j+3,i) > 9999) done[j] = true;
            else{
                if((fignum(j+3, i)/10)%10 == 0) continue;
                fNum[j][c[j]++] = fignum(j+3,i);
                //cout << j+3 << " " << i << ": " << fignum(j+3, i) << endl;
            }
        }
    }
    
    out.open("tmp.txt");
    char a[6];
    fori(6) a[i] = ' ';
    a[5] = '5';
    string t;
    fori(c[5]+1){
        chain(tos(fNum[5][i]), a);
    }
    fori(z){
        
        if(s[i][0] == s[i][s[i].length()-2] && s[i][1] == s[i][s[i].length()-1]) {
            cout << s[i] << endl;
            break;
        }
    }
    
    
    cin.get();
    return 0;   
}

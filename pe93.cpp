#include <iostream>
#include <string>
#include <stack>

using namespace std;

char op(int o){
    switch(o){
        case 0: return '+';
        case 1: return '-';
        case 2: return '*';
        case 3: return '/';
        default: return ' ';
    }
}
bool isint(double d){
    if(d - (int) d > 0) return false;
    return true;
}
string genstring(char ns[4], int op1, int op2, int op3, int which){
    string ret = "#######";
    ret[0] = ns[0];
    ret[1] = ns[1];
    if(which == 0){ //12-3-4-
        ret[2] = op(op1);
        ret[3] = ns[2];
        ret[4] = op(op2);
        ret[5] = ns[3];
        ret[6] = op(op3);
    }
    else if(which == 1){ //12-34--
        ret[2] = op(op1);
        ret[3] = ns[2];
        ret[4] = ns[3];
        ret[5] = op(op2);
        ret[6] = op(op3);
    }
    else if(which == 2){ //123-4--
        ret[2] = ns[2];
        ret[3] = op(op1);
        ret[4] = ns[3];
        ret[5] = op(op2);
        ret[6] = op(op3);
    }
    else if(which == 3){ //123--4-
        ret[2] = ns[2];
        ret[3] = op(op1);
        ret[4] = op(op2);
        ret[5] = ns[3];
        ret[6] = op(op3);
    }
    else{ //1234---
        ret[2] = ns[2];
        ret[3] = ns[3];
        ret[4] = op(op1);
        ret[5] = op(op2);
        ret[6] = op(op3);
    }
    return ret;
}

int rpn(string s){
    stack<double> r;
    double a, b;
    for(int i=0; i<s.length(); i++){
        if(s[i] > '0' && s[i] <= '9') r.push(s[i] - '0');
        else if(s[i] == '+'){
            a = r.top();
            r.pop();
            b = r.top();
            r.pop();
            r.push(a+b);
        }
        else if(s[i] == '-'){
            a = r.top();
            r.pop();
            b = r.top();
            r.pop();
            r.push(a-b);
        }
        else if(s[i] == '*'){
            a = r.top();
            r.pop();
            b = r.top();
            r.pop();
            r.push(a*b);        
        }
        else if(s[i] == '/'){
            a = r.top();
            r.pop();
            b = r.top();
            r.pop();
            if(b == 0) return 0;
            r.push(a/b);
        }
    }
    a = r.top();
    if(isint(a)) return a;
    else return 0;
    //return r.top();
}

int seqlen(int a, int b, int c, int d){
    int m = 9*9*9*9;
    bool reachable[m];
    for(int i=0;i<m; i++) reachable[i] = false;
    
    char ns[4]; int tmp; string t;
    ns[0] = a+'0'; ns[1] = b+'0'; ns[2] = c+'0'; ns[3] = d+'0';
    while(next_permutation(ns, ns+4)){
        for(int op1 = 0; op1<4; op1++){
            for(int op2 = 0; op2<4; op2++){
                for(int op3=0; op3<4; op3++){
                    for(int w=0; w<5; w++){
                        //cout << '-';
                        t = genstring(ns, op1, op2, op3, w);
                        //cout << t;
                        tmp = rpn(t);
                        //if(tmp != 0) cout << tmp << endl;
                        //cout << ":";
                        if(tmp > 0)  reachable[tmp] = true;
                        //cout << ":";
                    }
                }
            }
        }        
    }
    
    for(int i=1; i<m; i++){
        if(!reachable[i]) return i-1;
    }
}


int main(){
    char ns[4] = {'1','2','3','4'};
    //cout << seqlen(1,2,3,4) << endl;
    
    int max = 0, n;
    for(int i=1; i<10; i++){
        for(int j=i+1; j<10; j++){
            for(int k=j+1; k<10; k++){
                for(int l=k+1; l<10; l++){
                    n = seqlen(i,j,k,l);
                    if(max < n){
                        max = n;
                        cout << i << "," << j << "," << k << "," << l << ": " << max << endl;
                     }                        
                }
            }
        }
    }
    
    cout << max << endl;
    cin.get();
    return 0;
}

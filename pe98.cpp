#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

string words[1786];
unsigned long squares[31623];

bool sameLen(string a, string b){
    return a.length()<b.length();
}

bool issquare(int k, int l, int h){
    if(h <= l) return false;
    int mid = (h+l)/2;
    if(k>squares[mid] && mid!=l) return issquare(k,mid,h);
    else if(k<squares[mid] && mid != h) return issquare(k,l,mid);
    else if(k==squares[mid]) return true;
    else return false;
}

int log10(unsigned long i){
    if(i<10) return 1;
    if(i<100) return 2;
    if(i<1000) return 3;
    if(i<10000) return 4;
    if(i<100000) return 5;
    if(i<1000000) return 6;
    if(i<10000000) return 7;
    if(i<100000000) return 8;
    else return 9;
}

unsigned long ismatch(string a, string b, unsigned long sq){
    unsigned long s = sq;
    string map = "          ";
    for(int i=a.length()-1; i>=0; i--){
        if(map[s%10] == ' ') map[s%10] = a[i];
        else return 0;
        s /= 10;
    }
    //Check for two digits with same character
    string tmp = map;
    sort(tmp.begin(), tmp.end());
    for(int i=1; i<10; i++) if(tmp[i] != ' ' && tmp[i] == tmp[i-1]) return 0;
    //Generate reverse mapping
    unsigned char reversemap[256]; 
    for(int i=0; i<10; i++) if(map[i] != ' ') reversemap[map[i]] = i;
    //generate integer
    unsigned long square = reversemap[b[0]];
    for(int i=1; i<b.length(); i++){
        square *= 10;
        square += reversemap[b[i]];
    }
    if(log10(square) != a.length()) return 0;
    //cout << "Returning square" << endl;
    if(issquare(square, 0, 31623)){
        //cout << square << " " << sq << endl;
        if(square>sq) return square;
        else return sq;
    }
    else return 0;
}

bool isAnagram(string a, string b){
    if(a.length() != b.length()) return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a.compare(b) == 0) return true;
    else return false;
}

int main(){
    ifstream in("words.txt");
    //ofstream out("anagrams.txt");
    
    for(int i=0; i<1786; i++){
        in >> words[i];
    }
    for(int i=0; i<31623; i++){
        squares[i] = i*i;
    }
    int curr, max = 0;
    sort(words, words+1786, sameLen);
    for(int i=0; i<1786; i++){
        for(int j=i+1; j<1786 && words[j].length() == words[i].length(); j++){
            if(isAnagram(words[i], words[j])){
                //cout << words[i] << " " << words[j] << endl;
                if(words[i].length() == 2) continue;
                for(int n=0; n<31623 && log10(squares[n]) <= words[i].length(); n++){
                    if(log10(squares[n]) < words[i].length()) continue;
                    curr = ismatch(words[i], words[j], squares[n]);
                    if(curr == 0) curr = ismatch(words[j], words[i], squares[n]);
                    if(curr != 0 && curr > max){
                         max = curr;
                         //cout << words[i] << " " << words[j] << " " << curr << endl;
                    }
                }
            }
        } 
    } 
    cout << max << endl;
    
    cin.get();
    return 0;
}

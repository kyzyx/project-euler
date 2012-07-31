#include <iostream>
#include <fstream>

using namespace std;

string romanNumerals = "IVXLCDM";
int values[] = {1,5,10,50,100,500,1000};

int valRoman(string n){
    int ind = 8;
    int tmp;
    int total = 0;
    for(int i=0; i<n.length(); i++){
        tmp = romanNumerals.find_first_of(n[i]);    
        if(tmp > ind){
            total -= 2*values[ind];
        }
        ind = tmp;
        total += values[tmp];
    }
    return total;
}

string toRoman(int n){
    int remain = n;
    string ret = "";
    
    //1000s
    for(int i=0; i<remain/1000; i++){
        ret += 'M';
    }    
    
    //100s
    remain %= 1000;
    if(remain/100 == 9){
         ret += "CM";
         remain -= 900;
    }
    else if(remain/100 >= 5){
         ret += 'D';
         remain -= 500;
    }
    else if(remain/100 == 4){
         ret += "CD";
         remain -= 400;
    }
    for(int i=0; i<remain/100; i++) ret += 'C';
    
    //Tens
    remain %= 100;
    if(remain/10 == 9){
         ret += "XC";
         remain -= 90;
    }
    else if(remain/10 >= 5){
         ret += 'L';
         remain -= 50;
    }
    else if(remain/10 == 4){
         ret += "XL";
         remain -= 40;
    }
    for(int i=0; i<remain/10; i++) ret += 'X';
    
    //Ones
    remain %= 10;
    if(remain == 9){
         ret += "IX";
         remain -= 9;
    }
    else if(remain >= 5){
         ret += 'V';
         remain -= 5;
    }
    else if(remain == 4){
         ret += "IV";
         remain -= 4;
    }
    for(int i=0; i<remain; i++) ret += 'I';
    
    if(remain > 3) return "Shit";
    else return ret;
}

int main(){
    ifstream in("roman.txt");
    string rn, tmp;
    int n;
    unsigned long saved = 0;
    
    cout << valRoman("MMMV") << endl;
    
    for(int i=0; i<1000; i++){
        in >> rn;
        
        //rn = "IIIIIIIIII";
        n = valRoman(rn);
        
        tmp = toRoman(n);
        //if(tmp.compare(rn) != 0) cout << i << ":" << rn << "\t" << tmp << endl;
        saved += rn.length()-tmp.length();
    }
    
    cout << saved << endl;
    
    cin.get();
    return 0;
}

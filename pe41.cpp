#include <iostream>
#include <fstream>

#include "util.h"

using namespace std;

int main(){
    ifstream in("prime7m8m.txt");
    int curr;
    while(!in.eof()){
        in >> curr;
        if(isPD(curr)) cout << curr <<endl;
    }
    cin.get();
    return 0;   
}

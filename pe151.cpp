#include <iostream>
#include <cstdio>
#define MAX 1048576

using namespace std;


double states[MAX];

void printstate(int n) {
    for(int i = 0; i < 4; i++) {
      cout << (n&15) << " ";
      n >>= 4;
    }
    cout << endl;
}

string tab = "";

double calcstate(int s) {
//cout << tab << s << endl;
if (s == 1) {
//cout << tab << 1 << endl;
return 0;
}
//tab += '\t';
  if (states[s] < 0) {
    states[s] = 0;
    // calculate total sheets
    int tot = 0;
    int tmp = s;
    for(int i = 0; i < 4; i++) {
      tot += tmp&15;
      tmp >>= 4;
    }

    tmp = s;
    int add = 0;
    for(int i = 0; i < 4; i++) {
      if (i != 0) add += 1<<((i-1)*4);

      if(tmp&15) {
        double tmpd = tmp&15;
        if (tot != 1) tmpd /= tot;
        // Calculate the next state
        int nextstate = s - (1<<(i*4)) + add;

        // Update current state
        double tmp3 = calcstate(nextstate);
        //cout << tmpd << "*" << tmp3 << "=" << tmpd*tmp3 << endl;
        states[s] += tmpd * tmp3; //calcstate(nextstate); 
        if (tot == 1) {
          states[s] += 1;
        }
      }
      tmp >>= 4;
      if (tmp == 0) break;
    }
  }
  //tab.resize(tab.size()-1);
  //cout << tab << "(" << states[s] << ")"  << endl;
  return states[s];
}

int main() {
  for(int i = 0; i < MAX; i++) states[i] = -1;
  states[1] = 1;
  int start = 0;
  int sstate[] = {1, 1, 1, 1};
  for(int i = 0; i < 4; i++) {
    start <<= 4;
    start |= sstate[i];
  }
  printstate(start);

  double s = calcstate(start);
  printf("%.7f\n", s);
/*
  for(int i = 0; i <= start; i++) {
    if (states[i] < 0) continue;
    printstate(i);
    cout << ": " << states[i] << endl;
  }*/
  return 0;
}

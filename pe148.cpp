#include <iostream>
#include <vector>
#define N 7
#define MAX 1000000000

using namespace std;

long long tri(long long n) {
    return (n*n + n)/2;
}

int main() {
    vector<long long> sizes;
    vector<long long> nums;
    int tn = tri(N);
    sizes.push_back(N);
    nums.push_back(tn);
    //cout << nums[0] << "/" << sizes[0] << endl;
    for(int i = 0; sizes[i] < MAX; i++) {
        sizes.push_back(N*sizes[i]);
        nums.push_back(tn*nums[i]);
        //cout << nums[i+1] << "/" << sizes[i+1] << endl;
    }


    long long currsize = MAX;
    long long currnum = 0;
    int cmax = sizes.size()-1;
    vector<long long> triangles;
    while(currsize > N) {
        for(; cmax >= 0; cmax--) {
            if (sizes[cmax] < currsize) {
                //cout << sizes[cmax] << endl;
                triangles.push_back(cmax);
                currsize -= sizes[cmax];
                break;
            }
        }
    }
    //cout << currsize << endl;
    triangles.push_back(currsize);

    long long multiplier = 1;
    int inarow = 1;
    for(int i = 0; i < triangles.size()-1; i++) {
        int inarow = 1;
        for(;i < triangles.size() - 1 && triangles[i] == triangles[i+1]; ++i) {
            inarow++;
        }
        //cout << nums[triangles[i]] << "*" << tri(inarow)*multiplier << endl;
        currnum += tri(inarow)*nums[triangles[i]]*multiplier;
        multiplier *= inarow+1;
    }
    currnum += multiplier*tri(triangles[triangles.size()-1]);
    //cout << tri(triangles[triangles.size()-1]) << "*" << multiplier << endl;

    cout << currnum << endl;
    cin.get();
    return 0;
}

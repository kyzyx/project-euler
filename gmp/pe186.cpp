#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#define MAX 80000000

using namespace std;
typedef mpz_class BigInt;

class unionfind{
    public:
        int len;
        unsigned long* root;
        unsigned long* numChildren;
        unsigned long presidentRoot;

        unionfind(int length){
            len = length;
            root = new unsigned long[len];
            numChildren = new unsigned long[len];
            for(int i=0; i<len; i++){
                root[i] = i;
                numChildren[i] = 1;
            }
            presidentRoot = 524287;
        }

        bool insert(int a, int b){
            int ra = a, rb = b;
            int tmp;
            while(root[ra] != ra){
                 tmp = root[ra];
                 root[ra] = root[tmp];
                 ra = tmp;
            }
            while(root[rb] != rb){
                tmp = root[rb];
                root[rb] = root[tmp];
                rb = tmp;
            }
            if(ra == rb) return false;
            if(numChildren[ra] > numChildren[rb]){
                if(presidentRoot == rb) presidentRoot = ra;
                root[rb] = ra;
                numChildren[ra] += numChildren[rb];
            }
            else{
                if(presidentRoot == ra) presidentRoot = rb;
                root[ra] = rb;
                numChildren[rb] += numChildren[ra];
            }
            if(numChildren[presidentRoot] >= 990000) return true;
            return false;
        }

		int ncrp(){
			return numChildren[presidentRoot];
		}

        void dump(){
            cout << "i:";
            for(int i=0; i<len; i++){
                cout << i << " ";
            }
            cout << endl << "r:";
            for(int i=0; i<len; i++){
                cout << root[i] << " ";
            }
            cout << endl << "n:";
            for(int i=0; i<len; i++){
                cout << numChildren[i] << " ";
            }
            cout << endl;
        }
};

class fibGen{
    private:
        int last[56];
        int k;
    public:
		fibGen(){
			k = 0;
			BigInt tmp;
			for(BigInt i=1; i<56; i++){
				tmp = 100003 - 200003*i + 300007*((i*i*i) % 1000000);
				tmp %= 1000000;
				last[i.get_ui()] = tmp.get_ui();
			}
		}

		int next(){
			last[k] = last[(k+56-24)%56] + last[(k+1)%56];
			last[k] %= 1000000;
			k = (k+1)%56;
			return last[k];
		}
};

int main(){
    fibGen generator;
    unionfind g(1000000);
    int a,b;

    for(unsigned long i=1; i<MAX; i++){
		a = generator.next();
		b = generator.next();
		if(a == b) {
			i--;
			continue;
		}
		if(g.insert(a,b)){
			cout << i << ":"<< g.ncrp() <<   endl;
			break;
		}
	}

    cin.get();
    return 0;
}

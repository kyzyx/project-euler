#include <iostream>
#include <fstream>

using namespace std;

class point{
    public:
        int x;
        int y;
        point(){
            x = 0;
            y = 0;
        }
        point(int xx, int yy){
            x = xx;
            y = yy;
        }
        point& operator-=(const point& p){
            if(this == &p){
                 x = 0; y = 0;
                 return *this;
            }
            x -= p.x; y -= p.y;
            return *this;
        }
        
        const point operator-(const point& p){
            return point(*this) -= p;
        }
        
        void dump(){
            cout << x << "," << y;
        }
};

int cross(point a, point b){
    return a.x*b.y-a.y*b.x;
}

//returns whether oa and ob are on the same side as oc
//if cross products are in same direction
bool sameside(point o, point a, point b, point c){
    int m1 = cross(c-o,b-o), m2 = cross(c-o,a-o);
    if(m1 > 0 && m2 > 0 || m1 < 0 && m2 < 0) return true;
    else return false;
}

bool containsOrigin(point a, point b, point c){
    point o(0,0);
    return(sameside(c,o,b,a) && sameside(b,o,a,c) && sameside(a,o,c,b));
}

int main(){
    ifstream in("triangles.txt");
    point p[3];
    int tot = 0;

    for(int i=0; i<1000; i++){
        //cout << i << endl;
        for(int j=0; j<3; j++){
            in >> p[j].x;
            in.get();
            in >> p[j].y;
            in.get();
            //p[j].dump();
           //cout << " ";
        }
        
        if(containsOrigin(p[0], p[1], p[2])){
             tot++;
            //cout << "*****";
        }
        //cin.get();
        //cout << endl;
    }
    cout << tot << endl;
    
    cin.get();
    return 0;
}

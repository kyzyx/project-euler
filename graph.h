#include <iostream>
#define V 40

using namespace std;

class edgenode{
    public:
        int y;
        int weight;
        edgenode* next;
};


class graph{
    public:
        graph(){
            nvertices = 0;
            nedges = 0;
            //
            totalweight = 0;
            for(int i=0; i<=V; i++){
                edges[i] = NULL;
            }
        }
        
        void insertedge(int x, int y, int w, bool done=false){
            edgenode* tmp = new edgenode;
            tmp->weight = w;
            tmp->y = y;
            tmp->next = edges[x];
            
            edges[x] = tmp;
            if(!done) insertedge(y,x,w,true);
            else{
                 nedges++;
                 totalweight += w;
            }
        }
        
        void fromMatrix(int mat[V][V], int nv){
            nvertices = nv;
            for(int i=0; i<nv; i++){
                for(int j=0; j<i; j++){
                    if(mat[i][j] != 0) insertedge(i,j,mat[i][j]);
                }
            }
        }
                
    edgenode* edges[V+1];
    int nvertices;
    int nedges;
    //
    int totalweight;
};

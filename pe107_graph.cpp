#include "graph.h"
#include <fstream>


int main(){
    ifstream in("Inputs/network_.txt");
    //ifstream in("nettest.txt");
    int matrix[V][V];
    
    int tmp;
    
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            in >> matrix[i][j];
        }
    }
    cout << "Done reading matrix" << endl;
    graph g;
    g.fromMatrix(matrix, V);
    
    //Start Prim's Algorithm
    bool intree[V+1];
    int distance[V+1];
    int parent[V+1];
    for(int i=0; i< g.nvertices; i++){
        intree[i] = false;
        distance[i] = 999999999;
        parent[i] = -1;
    }
    
    distance[0] = 0;
    int v = 0;
    int total = 0;
    int w, weight;
    edgenode* p;
    while(!intree[v]){
        intree[v] = true;
        p = g.edges[v];
        while(p!=NULL){
            w = p->y;
            weight = p->weight;
            if(distance[w] > weight && intree[w] == false){
                distance[w] = weight;
                parent[w] = v;
                //cout << "Connecting " << w << " and " << v << " with weight " << weight << endl;
            }
            p = p->next;
        }
        
        v = 0;
        int dist = 999999999;
        for(int i=0; i<g.nvertices; i++){
            if(!intree[i] && dist>distance[i]){
                dist = distance[i];
                v = i;
            }
        }
    }
    
    //Reconstruct tree
    for(int i=1; i<g.nvertices; i++){
        //cout << parent[i] << endl;
        total += matrix[parent[i]][i];
    }
    
    cout << g.totalweight << " - " << total << " = " << g.totalweight - total << endl;
    
    cin.get();
    return 0;
}

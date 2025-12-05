#include <iostream>
using namespace std;
vector<int> bellman(int V, vector<vector<int>> &edges, int src){
    vector<int> distance(V, 1e9);
    distance[src] = 0;
    for(int i =0;i<V-1;i++){
        for(auto iterator: edges){
            int u = iterator[0];
            int v = iterator[1];
            int wt = iterator[2];
            if(distance[u]!=1e9&&distance[v]>distance[u]+wt){
                distance[v] = distance[u]+wt;
            }
        }
    }
    //nth relaxation to check for -ve cycle
    for(auto iterator: edges){
        int u = iterator[0];
        int v = iterator[1];
        int wt = iterator[2];
        if(distance[u]!=1e9&&distance[v]>distance[u]+wt){
            return {-1};
        }
    }
    return distance;
}
int main(){
    return 0;
}
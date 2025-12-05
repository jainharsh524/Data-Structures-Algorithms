#include <iostream>
using namespace std;
bool isCycle_DFS(int node, vector<int> adj_lst[], vector<int> &visited, vector<int> &path){
    path[node] = 1;
    visited[node] = 1;
    for(auto iterator: adj_lst[node]){
        if(!visited[iterator]){
            if(isCycle_DFS(iterator, adj_lst, visited, path)) return true;
        }
        else if(path[iterator]) return true;
    }
    path[node] = 0;
    return false;
}
bool isCycle(int V, vector<int> adj_lst[]){
    vector<int> visited(V, 0);
    vector<int> path(V, 0);
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            if(isCycle_DFS(i, adj_lst, visited, path)) return true;
        }
    }
    return false;
}
int main(){

    return 0;
}
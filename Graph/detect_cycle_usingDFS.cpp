#include <iostream>
using namespace std;
bool dfs(int src, int parent, vector <int> adj_lst[], vector<int> &visited){
    visited[src] = 1;
    for(auto neighbours: adj_lst[src]){
        if(!visited[neighbours]){
            if(dfs(neighbours, src, adj_lst, visited)) return true;
        }
        else if(neighbours!=parent &&visited[neighbours]){
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj_lst[]){
    vector<int> visited(V, 0);
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            if(dfs(i, -1, adj_lst, visited)) return true;
        }
    }
    return false;
}
int main(){
    int v, e;
    cin >> v >> e;
    vector<int> adj_lst[v];
    
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj_lst[a].push_back(b);
        adj_lst[b].push_back(a); // undirected graph
    }

    if (isCycle(v, adj_lst)) cout << "Cycle exists\n";
    else cout << "No cycle\n";
    return 0;
}
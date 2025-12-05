#include <iostream>
using namespace std;
bool detection(int src, vector<int> adj_lst[], vector <int> &visited){
    visited[src] = 1;
    queue <pair<int, int>> q;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto neighbour: adj_lst[node]){
            if(!visited[neighbour]){
                visited[neighbour] = 1;
                q.push({neighbour, node});
            }
            else if(parent!= neighbour){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj_lst[]){
    vector <int> visited(V, 0);
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            if(detection(i, adj_lst, visited)) return true;
        }
    }
    return false;
}
int main(){
    int V, E;
    cin >> V >> E;
    vector<int> adj_lst[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj_lst[u].push_back(v);
        adj_lst[v].push_back(u); // undirected graph
    }

    if (isCycle(V, adj_lst)) cout << "Cycle exists\n";
    else cout << "No cycle\n";

    return 0;
}
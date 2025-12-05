#include <iostream>
using namespace std;
const int N = 1e5;
vector<int> adj[N];
vector<int> tin, low, visited;
int timer;
void dfs(int u, int parent, vector<pair<int, int>> &bridges){
    visited[u] = 1;
    tin[u] = low[u] = timer++;
    for(int v : adj[u]){
        if(v==parent) continue;
        if(!visited[v]){
            dfs(v, u, bridges);
            low[u] = min(low[u], low[v]);
            if(low[v]>tin[u]){
                bridges.push_back({u, v});
            }
        }
        else {
            // Back edge
            low[u] = min(low[u], tin[v]);
        }
    }
}
vector<pair<int, int>> findBridges(int n){
    timer = 0;
    tin.assign(n, -1);
    low.assign(n, -1);
    visited.assign(n, 0);
    vector<pair<int,int>> bridges;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, bridges);
        }
    }
    return bridges;
}
int main(){
     return 0;
}
#include <iostream>
using namespace std;

int main(){
    // cout<<"Hello World"<<endl;
    int n, m;
    cin>>n>>m;
    int adj_mat[n+1][n+1];
    //undirected graph 
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj_mat[u][v] = 1;
        adj_mat[v][u] = 1;
    }
    //Adjacency list method for undirected graph
    int n1, m1;
    cin>>n1>>m1;
    vector <int> adj[n+1]; //Array of vectors
    for(int i = 0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
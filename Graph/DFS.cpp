#include <iostream>
using namespace std;

void recHelper(int vertex, vector <int> adj_lst[], vector<int> &visited, vector<int> &ls){
    visited[vertex] = 1;
    ls.push_back(vertex);
    for(auto iterator: adj_lst[vertex]){
        if(!visited[iterator]){
            recHelper(iterator, adj_lst, visited, ls);
        }
    }
}
vector<int> DFSOfGraph(int V, vector<int> adj_lst[]){
    vector <int> visited (V, 0);
    int start = 0;
    vector<int> ls;

    recHelper(start, adj_lst, visited, ls);
    return ls;
}
int main(){
    int v, e;
    cin>>v>>e;
    vector <int> adj_lst[v];
    for(int i = 0;i<e;i++){
        int a, b;
        cin>>a>>b;
        adj_lst[a].push_back(b);
        adj_lst[b].push_back(a);
    }

    vector<int> dfs = DFSOfGraph(v, adj_lst);
    for (auto node : dfs) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
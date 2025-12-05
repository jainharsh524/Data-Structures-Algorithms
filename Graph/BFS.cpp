#include <iostream>
using namespace std;

vector <int> BFSOfGraph(int V, vector<int> adj_lst[]){
    vector<int> visited(V, 0);  // initialize visited with 0
    vector<int> bfs;
    queue<int> q;

    visited[0] = 1;  // start from node 0 (change to 1 if 1-based indexing)
    q.push(0);
    while(!q.empty()){
        int val = q.front();
        q.pop();
        bfs.push_back(val);

        for(auto iterator: adj_lst[val]){
            if(!visited[iterator]){
                visited[iterator] = 1;
                q.push(iterator);
            }
        }
    }
    return bfs;
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

    // for(int i = 0;i<e;i++){
    //     for(auto iterator: adj_lst[i]){
    //         cout<<iterator<<" ";
    //     }
    //     cout<<endl;
    // }

    vector <int> bfs = BFSOfGraph(v, adj_lst);
    for(auto iterator: bfs){
        cout<<iterator<<" ";
    }
    return 0;
}
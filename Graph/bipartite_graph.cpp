#include <iostream>
using namespace std;
bool isbipartite_usingBFS(int V, vector<int> adj_lst[]){
    queue <int> q;
    q.push(0);
    vector<int> clr(V, -1);
    clr[0] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto iterator: adj_lst[node]){
            if(clr[iterator]==-1){
                clr[iterator] = !clr[node];
                q.push(iterator);
            }
            else if(clr[iterator]==clr[node]){
                return false;
            }
        }
    }
    return true;
}

bool isbipartite_usingDFS(int node, int color, vector<int> &clr, vector<int> adj_lst[]){
    clr[node] = color;
    for(auto iterator: adj_lst[node]){
        if(clr[iterator]==-1){
            if(!isbipartite_usingDFS(iterator, !color, clr, adj_lst)) return false;
        }
        else if(clr[iterator]==clr[node]){
            return false;
        }
    }
    return true;
}

bool isbipartite(int V, vector<int> adj_lst[]){
    vector<int> clr(V, -1);
    for(int i = 0;i<V;i++){
        if(clr[i]==-1){
            if(!isbipartite_usingDFS(i, 0, clr, adj_lst)) return false;
        }
    }
    return true;
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
    return 0;
}
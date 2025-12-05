#include <iostream>
using namespace std;
vector<int> topo_sort(int V, vector<int> adj_lst[]){
    vector <int> indegree(V, 0);
    for(int i =0;i<V;i++){
        for(auto iterator: adj_lst[i]){
            indegree[iterator]++;
        }
    }
    vector<int> topo;
    queue <int> q;
    for(int i = 0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto iterator: adj_lst[node]){
            indegree[iterator]--;
            if(indegree[iterator]==0) q.push(iterator);
        }
    }
    return topo;
}
int main(){
    return 0;
}
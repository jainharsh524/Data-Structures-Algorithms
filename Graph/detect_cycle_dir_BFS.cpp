#include <iostream>
using namespace std;
bool isCycle(int V, vector<int> adj_lst[]){
    vector<int> indegree(V, 0);
    for(int i = 0;i<V;i++){
    for(auto iterator: adj_lst[i]){
        indegree[iterator]++;
    }
    }
    queue<int> q;
    vector<int> topo;
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
    if(topo.size()!=V) return true;
    return false;
}
int main(){

}
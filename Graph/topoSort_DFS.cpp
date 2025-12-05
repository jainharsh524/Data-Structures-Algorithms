#include <iostream>
using namespace std;
void dfs(int node, vector<int> adj_lst[], vector<int> &visited, stack<int> &st){
    visited[node] = 1;
    for(auto iterator: adj_lst[node]){
        if(!visited[iterator]) dfs(iterator, adj_lst, visited, st);
    }
    st.push(node);
}
vector<int> topo_sort(int V, vector<int> adj_lst[]){
    vector<int> visited(V, 0);
    stack<int> st;
    for(int i = 0;i<V;i++){
        if(!visited[i]) {
            dfs(i, adj_lst, visited, st);
        }
    }
    vector<int> ans(V);
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    return 0;
}
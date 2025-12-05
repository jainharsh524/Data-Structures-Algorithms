#include <iostream>
using namespace std;
vector<int> topo_sort(int V, vector<int> adj_lst[]){
    vector<int> indegree(V, 0);
    for(int i = 0;i<V;i++){
        for(auto iterator: adj_lst[i]){
            indegree[iterator]++;
        }
    }
    queue<int> q;
    for(int i =0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> topo(V);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto iterator: adj_lst[node]){
            indegree[iterator]--;
            if(indegree[iterator]==0){
                q.push(iterator);
            }
        }
    }
    return topo;
}
string findOrder(string dict[], int N, int K){
    vector <int> adj_lst[K];
    for(int i = 0;i<N-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int j = 0;
        while(j<s1.length()&&j<s2.length()){
            if(s1[j]!=s2[j]){
                adj_lst[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
            else j++;
        }
    }
    vector<int> sorted = topo_sort(K, adj_lst);
    string ans = "";
    for(auto iterator: sorted){
        ans = ans+char('a'+iterator);
    }
    return ans;
}
int main(){
    return 0;
}
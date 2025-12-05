#include <iostream>
using namespace std;
vector<int> shortest_path(vector<vector<int>> &edges, int N, int M, int src){
    vector<int> adj_lst[N];
    for(auto iterator: edges){
        adj_lst[iterator[0]].push_back(iterator[1]);
        adj_lst[iterator[1]].push_back(iterator[0]);
    }
    vector<int> distance(N, INT_MAX);
    distance[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto iterator: adj_lst[node]){
            if(distance[iterator]>distance[node]+1){
                distance[iterator] = distance[node]+1;
                q.push(iterator);
            }
        }
    }
    return distance;
}
int main(){
    return 0;
}
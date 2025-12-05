// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// void bfs(int v, vector<int> adj_lst[], vector<int> &visited, int src, vector<int> &bfs){
//     visited[src] = 1;
//     queue<int> q;
//     q.push(src);
//     while(!q.empty()){
//         int node = q.front();
//         bfs.push_back(node);
//         q.pop();
//         for(auto iterator: adj_lst[node]){
//             if(!visited[iterator]) {
//                 visited[iterator] = 1;
//                 q.push(iterator);
//             }
//         }
//     }
// }
// void dfs(int src, vector<int> adj_lst[], vector<int> &visited, vector<int>& dfsVector){
//     visited[src] = 1;
//     dfsVector.push_back(src);
//     for(auto iterator: adj_lst[src]){
//         if(!visited[iterator]) dfs(iterator, adj_lst, visited, dfsVector);
//     }
// }
// vector<int> wrapper1(int V, vector<int> adj_lst[]){
//     vector<int> visited(V, 0);
//     vector<int> bfsVector;
//     for(int i = 0;i<V;i++){
//         if(!visited[i]) bfs(V, adj_lst, visited, i, bfsVector);
//     }
//     return bfsVector;
// }
// vector<int> wrapper2(int V, vector<int> adj_lst[]){
//     vector<int> visited(V, 0);
//     vector<int> dfsVector;
//     for(int i = 0;i<V;i++){
//         if(!visited[i]) dfs(i, adj_lst, visited, dfsVector);
//     }
//     return dfsVector;
// }

bool isCycleUsingBFSForUndir(int src, vector<int> adj_lst[], vector<int> &visited){
    queue<pair<int, int>> q;
    visited[src] = 1;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto iterator: adj_lst[node]){
            if(!visited[iterator]){
                visited[iterator] = 1;
                q.push({iterator, parent});
            }
            else if(iterator!=parent){
                return true;
            }
        }
    }
    return false;
}
bool isCycleUsingDFSForUndir(int src, int parent, vector<int> adj_lst[], vector<int> &visited){
    visited[src] = 1;
    for(auto iter: adj_lst[src]){
        if(!visited[iter]){
            if(isCycleUsingDFSForUndir(iter, src, adj_lst, visited)) return true;
        }
        else if(iter!=parent){
            return true;
        }
    }
    return false;
}
bool isCycleUsingBFSFordir(int V, vector<int> adj_lst[]){
    queue<int> q;
    vector<int> indegree(V, 0);
    vector<int> topo;
    for(int i  = 0;i<V;i++){
        for(auto iter: adj_lst[i]){
            indegree[iter]++;
        }
    }
    for(int i = 0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto iter: adj_lst[node]){
            indegree[iter]--;
            if(indegree[iter]==0){
                q.push(iter);
            }
        }
    }
    return topo.size()!=V;
}
bool isCycleUsingDFSFordir(int V, int src, vector<int> adj_lst[], vector<int> &visited, vector<int> &path){
    visited[src] = 1;
    path[src] = 1;
    for(auto iter: adj_lst[src]){
        if(!visited[iter]){
            if(isCycleUsingDFSFordir(V, iter, adj_lst, visited, path)) return true;
        }
        else if(path[iter]) return true;
    }
    path[src] = 0;
    return false;
}

void topoUsingDFS(int src, vector<int> adj_lst[], vector<int> &visited, stack<int> &st){
    visited[src] = 1;
    for(auto iter: adj_lst[src]){
        if(!visited[iter]){
            topoUsingDFS(iter, adj_lst, visited, st);
        }
    }
    st.push(src);
}
vector<int> dijkstra(int V, int src, vector<pair<int, int>> adj_lst[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto iter: adj_lst[node]){
            if(dist[iter.first]>distance+iter.second){
                dist[iter.first]=distance+iter.second;
                pq.push({dist[iter.first], iter.first});
            }
        }
    }
    return dist;
}
vector<int> bellman(int V, int src, vector<pair<int, int>> adj_lst[]) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (auto iter : adj_lst[u]) {
                int v = iter.first;
                int wt = iter.second;
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    // Check for negative cycle (1 extra relaxation)
    for (int u = 0; u < V; u++) {
        for (auto iter : adj_lst[u]) {
            int v = iter.first;
            int wt = iter.second;
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                cout << "Negative cycle detected\n";
                return {-1};
            }
        }
    }

    return dist;
}

void floyd(vector<vector<int>> &adj_mat){
    int s = adj_mat.size();
    for(int k= 0;k<s;k++){
        for(int i = 0;i<s;i++){
            for(int j= 0;j<s;j++){
                adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k]+adj_mat[k][j]);
            }
        }
    }
}
void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>>&mat){
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    visited[row][col] = 1;
    for(int i = 0;i<4;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow<visited.size()&&nrow>=0&&ncol<visited[0].size()&&ncol>=0){
            if(!visited[nrow][ncol]&&mat[nrow][ncol]=='O'){
                dfs(nrow, ncol, visited, mat);
            }
        }
    }
}
void conversionExceptBoundary(vector<vector<char>> &mat){
    vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));
    //boundary
    //1st row
    for(int i = 0;i<mat[0].size();i++){
       if(mat[0][i] == 'O' && !visited[0][i]) dfs(0, i, visited, mat);
    }
    //last row
    for(int i = 0;i<mat[0].size();i++){
        if(mat[mat.size()-1][i] == 'O' && !visited[mat.size()-1][i]) dfs(mat.size()-1, i, visited, mat);
    }
    //1st col
    for(int i = 0;i<mat.size();i++){
        if(mat[i][0] == 'O' && !visited[i][0]) dfs(i, 0, visited, mat);
    }
    //last col
    for(int i = 0;i<mat.size();i++){
        if(mat[i][mat[0].size()-1] == 'O' && !visited[i][mat[0].size()-1]) dfs(i, mat[0].size()-1, visited, mat);
    }

    //for rest
    for(int i = 0;i<mat.size();i++){
        for(int j = 0;j<mat[0].size();j++){
            if(!visited[i][j]&&mat[i][j]=='O'){
                mat[i][j] = 'X';
            }
        }
    }
}

int main() {
    int V, E;
    cin>>V>>E;
    vector<int> adj_lst[V];
    // storing an undirected graph
    for(int i = 0;i<E;i++){
        int u, v;
        cin>>u>>v;
        adj_lst[u].push_back(v);
        adj_lst[v].push_back(u);
    }
    
    // Write C++ code here
    cout << "Input taken";

    return 0;
}
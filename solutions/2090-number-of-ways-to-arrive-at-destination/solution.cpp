class Solution {
public:
int MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj_lst(n);
        for(auto ele: roads){
            int u = ele[0];
            int v = ele[1];
            int wt = ele[2];
            adj_lst[u].push_back({v, wt});
            adj_lst[v].push_back({u, wt});
        }
        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> pq;
        pq.push({0, 0});
        vector<long long> distance(n,LLONG_MAX); distance[0] = 0;
        vector<long long> ways(n,0); ways[0] = 1;
        while(!pq.empty()){
            auto ele = pq.top(); pq.pop();
            long long dist = ele.first;
            int node = ele.second;
            if(dist > distance[node]) continue;
            for(auto nei: adj_lst[node]){
                int neigh = nei.first;
                int wt = nei.second;
                if(distance[neigh] > dist + wt){
                    distance[neigh] = dist + wt;
                    ways[neigh] = ways[node];
                    pq.push({distance[neigh], neigh});
                }
                else if(distance[neigh] == dist + wt){
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};

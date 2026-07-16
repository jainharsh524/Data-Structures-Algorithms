class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e9);
        vector<vector<pair<int,int>>> adj_lst(n + 1);
        for(auto &f : times){
            adj_lst[f[0]].push_back({f[1], f[2]});
        }
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            auto [timer, node] = pq.top();
            pq.pop();
            if(timer > dist[node]) continue;
            for(auto &nei : adj_lst[node]){
                int neigh = nei.first;
                int wt = nei.second;
                if(dist[neigh] > timer + wt){
                    dist[neigh] = timer + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        int maxi = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};

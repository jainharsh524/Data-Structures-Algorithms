class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj_lst(n);
        for(auto &f : flights){
            adj_lst[f[0]].push_back({f[1], f[2]});
        }
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;
        // {cost, node, stops}
        pq.push({0, src, 0});
        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        dist[src][0] = 0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int cost = cur[0];
            int node = cur[1];
            int stops = cur[2];
            if(node == dst) return cost;
            if(stops == k + 1) continue;
            for(auto &nei : adj_lst[node]){
                int next = nei.first;
                int wt = nei.second;
                if(cost + wt < dist[next][stops + 1]){
                    dist[next][stops + 1] = cost + wt;
                    pq.push({cost + wt, next, stops + 1});
                }
            }
        }
        return -1;
    }
};

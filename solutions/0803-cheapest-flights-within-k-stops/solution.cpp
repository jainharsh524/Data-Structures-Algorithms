class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj_lst(n);
        for(auto ele : flights){
            adj_lst[ele[0]].push_back({ele[1], ele[2]});
        }
        // {{cost, node}, remaining flights}
        queue<pair<pair<int, int>, int>> q;
        vector<int> distance(n, INT_MAX);
        int stops = k + 1;
        q.push({{0, src}, stops});
        distance[src] = 0;
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int dist = ele.first.first;
            int node = ele.first.second;
            int STN = ele.second;
            if(STN == 0) continue;
            if(STN > 0){
                for(auto nei : adj_lst[node]){
                    if(distance[nei.first] > dist + nei.second){
                        distance[nei.first] = dist + nei.second;
                        q.push({{distance[nei.first], nei.first}, STN - 1});
                    }
                }
            }
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
        // priority_queue<
        //     pair<int, pair<int, int>>,
        //     vector<pair<int, pair<int, int>>>,
        //     greater<pair<int, pair<int, int>>>
        // > pq;
        // int stops = k + 1;
        // pq.push({0, {src, stops}});
        // vector<vector<int>> distance(n, vector<int>(k + 2, INT_MAX));
        // distance[src][stops] = 0;
        // while(!pq.empty()){
        //     auto ele = pq.top();
        //     pq.pop();
        //     int dist = ele.first;
        //     int node = ele.second.first;
        //     int STN = ele.second.second;
        //     if(node == dst) return dist;
        //     if(STN == 0) continue;
        //     if(dist > distance[node][STN]) continue;
        //     for(auto nei : adj_lst[node]){
        //         int nextNode = nei.first;
        //         int weight = nei.second;
        //         int newDist = dist + weight;
        //         int remainingStops = STN - 1;
        //         if(distance[nextNode][remainingStops] > newDist){
        //             distance[nextNode][remainingStops] = newDist;
        //             pq.push({ newDist, {nextNode, remainingStops}});
        //         }
        //     }
        // }
        // return -1;
    }
};

class Solution {
public:
    long long caltime(vector<vector<int>> &adj_lst, int node, vector<int>& basetime, vector<long long>& duration) {
        if(duration[node] != -1)
            return duration[node];
        if(adj_lst[node].size() == 0) {
            duration[node] = basetime[node];
        }
        else {
            long long maxdur = 0;
            long long mindur = LLONG_MAX;
            for(int i : adj_lst[node]) {
                long long dur;
                if(duration[i] == -1)
                    dur = caltime(adj_lst, i, basetime, duration);
                else
                    dur = duration[i];
                maxdur = max(dur, maxdur);
                mindur = min(dur, mindur);
            }
            long long val = basetime[node] + (maxdur - mindur);
            duration[node] = val + maxdur;
        }
        return duration[node];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj_lst(n);
        for(auto ele : edges) {
            adj_lst[ele[0]].push_back(ele[1]);
        }
        vector<long long> duration(n, -1);
        return caltime(adj_lst, 0, baseTime, duration);
    }
};

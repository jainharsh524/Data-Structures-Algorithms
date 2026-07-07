class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(char c : tasks) mp[c]++;
        priority_queue<pair<int,char>> pq;
        for(auto x : mp) pq.push({x.second, x.first});
        queue<pair<pair<char,int>,int>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()) {
            time++;
            while(!q.empty() && q.front().second <= time) {
                auto cur = q.front();
                q.pop();
                pq.push({cur.first.second, cur.first.first});
            }
            if(!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                int freq = cur.first;
                char val = cur.second;
                if(freq > 1)
                    q.push({{val, freq-1}, time+n+1});
            }
        }
        return time;
    }
};

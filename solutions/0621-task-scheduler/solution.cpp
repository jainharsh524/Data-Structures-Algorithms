class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(char ch: tasks) mp[ch]++; 
        priority_queue<int> pq;
        for(auto ele: mp) pq.push(ele.second);
        queue<pair<int, int>> q;
        int timer = 0;
        while(!q.empty() || !pq.empty()){
            if(!pq.empty()) { 
                int freq = pq.top(); freq--;
                if(freq != 0) q.push({freq, timer+n+1});
                pq.pop();
            }
            timer++;
            while(!q.empty() && timer >= q.front().second){
                int newfreq = q.front().first;
                q.pop();
                pq.push(newfreq);
            }
        }
        return timer;
    }
};

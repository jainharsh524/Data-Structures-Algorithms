class Solution {
public:
    int minimumPushes(string word) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        for(char ch: word) mp[ch]++;
        for(auto &it: mp){
            pq.push({it.second, it.first});
        }
        int ans = 0;
        int i = 1;
        int cnt = 0;
        while(!pq.empty()){
            int freq = pq.top().first;
            pq.pop();
            ans += i*freq;
            cnt++;
            if(cnt==8){
                cnt = 0;
                i++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for(char &ch: s){
            mp[ch]++;
        }
        for(auto &iter: mp){
            pq.push({iter.second, iter.first});
        }
        string res = "";
        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            res.append(freq, ch);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string& word : words) {
            mp[word]++;
        }
        vector<pair<string, int>> vec;
        for (auto& p : mp) {
            vec.push_back({p.first, p.second});
        }
        sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(vec[i].first);
        }
        return res;
    }
};

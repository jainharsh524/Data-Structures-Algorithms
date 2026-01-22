class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(int i = 0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(mp.find(s)==mp.end()) mp.insert({s, {strs[i]}});
            else {
                mp[s].push_back(strs[i]);
            }
        }
        for (auto &it : mp) {
            vector<string> grp = it.second;
            res.push_back(grp);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        int req = words.size();
        unordered_map<string, int> mp;
        for(string word : words) mp[word]++;
        vector<int> res;
        for(int offset = 0; offset < len; offset++) {
            int l = offset, cnt = 0;
            unordered_map<string, int> curr;
            for(int r = offset; r + len <= s.size(); r += len) {
                string temp = s.substr(r, len);
                if(mp.find(temp) == mp.end()) {
                    curr.clear();
                    cnt = 0;
                    l = r + len;
                    continue;
                }
                curr[temp]++;
                cnt++;
                while(curr[temp] > mp[temp]) {
                    string left = s.substr(l, len);
                    curr[left]--;
                    cnt--;
                    l += len;
                }
                if(cnt == req) {
                    res.push_back(l);
                    string left = s.substr(l, len);
                    curr[left]--;
                    cnt--;
                    l += len;
                }
            }
        }
        return res;
    }
};

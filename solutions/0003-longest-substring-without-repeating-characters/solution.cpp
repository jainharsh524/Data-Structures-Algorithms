class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> mp;
        int len = 0;
        int maxlen = 0;
        int LU = 0;
        for(int i = 0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                LU = max(LU, mp[s[i]]+1);
            }
            mp[s[i]] = i;
            maxlen = max(i-LU+1, maxlen);
        }
        return maxlen;
    }
};

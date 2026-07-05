class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int maxlen = 0;
        int r = 0;
        for(r = 0;r<s.size();r++){
            if(mp.find(s[r])==mp.end()) mp[s[r]] = r;
            else{
                l =max(l, mp[s[r]]+1);
                mp[s[r]] = r;
            }
            maxlen = max(maxlen, r-l+1);
        }
        // maxlen = max(maxlen, r-l);
        return maxlen;
    }
};

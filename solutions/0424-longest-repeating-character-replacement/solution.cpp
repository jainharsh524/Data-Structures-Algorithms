class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0;
        int maxlen = 0;
        int maxf = 0;
        for(int r = 0;r<s.size();r++){
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);
            if((r-l+1)>(k+maxf)){
                mp[s[l]]--;
                l++;
            }
            else{
                maxlen = max(maxlen, r-l+1);
            }
        }
        return maxlen;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int maxf = 0;
        for(;r<s.size();r++){
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);
            if(r-l-maxf+1<=k) maxlen = max(maxlen, r-l+1); 
            while(r-l-maxf+1>k){
                mp[s[l]]--;
                l++;
            } 
        }
        return maxlen;
    }
};

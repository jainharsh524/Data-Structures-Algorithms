class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> mp;
        int l = 0;
        int maxfreq = 0;
        int maxlen = 0;
        for(int i = 0;i<s.size();i++){
            mp[s[i]]++;
            maxfreq = max(mp[s[i]], maxfreq);
            while(i - l - maxfreq + 1 > k){
                mp[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, i-l+1);
        }
        return maxlen;
    }
};

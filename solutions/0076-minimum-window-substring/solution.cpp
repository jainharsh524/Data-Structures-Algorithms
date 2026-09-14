class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t) return s;
        unordered_map<char, int> mp;
        for(char ch: t) mp[ch]++;
        int required = t.size(), minlen = INT_MAX, l = 0, start = -1;
        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] > 0) required--;
            mp[s[i]]--;
            
            while(required == 0){
                if(minlen > i - l + 1){
                    minlen = min(minlen, i - l + 1);
                    start = l;
                }
                if(mp[s[l]] == 0) required++;
                mp[s[l]]++;
                
                l++;
            }
        }
        return start == -1 ? "" : s.substr(start, minlen);
    }
};

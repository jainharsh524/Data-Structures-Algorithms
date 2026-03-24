class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = p.size();
        vector<int> res;
        unordered_map<char, int> mp;
        for(int i = 0;i<m;i++){
            mp[p[i]]++;
        }
        int l = 0;
        int required = m;
        for(int r = 0;r<s.size();r++){
            if(mp[s[r]]>0) required--;
            mp[s[r]]--;
            if(r-l+1>m){
                mp[s[l]]++;
                l++;
                if(mp[s[l-1]]>0){
                    required++;
                }
            }
            if(required==0){
                res.push_back(l);
            }
        }
        return res;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mps;
        for(int i = 0;i<s.size();i++){
            if(mps.find(s[i])==mps.end()) mps.insert({s[i], t[i]});
            else if(mps[s[i]]!=t[i]) return false;
        }
        unordered_map<char, char> mpt;
        for(int i = 0;i<s.size();i++){
            if(mpt.find(t[i])==mpt.end()) mpt.insert({t[i], s[i]});
            else if(mpt[t[i]]!=s[i]) return false;
        }
        return true;
    }
};

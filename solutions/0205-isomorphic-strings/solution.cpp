class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mps;
        for(int i = 0;i<s.size();i++){
            if(mps.find(s[i])!=mps.end()){
                if(mps[s[i]]!=t[i]) return false;
            }
            else mps[s[i]] = t[i]; 
        }
        unordered_map<char, char> mpt;
        for(int i = 0;i<s.size();i++){
            if(mpt.find(t[i])!=mps.end()){
                if(mpt[t[i]]!=s[i]) return false;
            }
            else mpt[t[i]] = s[i]; 
        }
        return true;
    }
};

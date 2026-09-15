class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string temp;
        vector <string> res;
        for(char ch: s){
            if(ch == ' '){
                res.push_back(temp);
                temp = "";
            }
            else temp.push_back(ch);
        }
        res.push_back(temp);
        if(res.size() != pattern.size()) return false;
        unordered_map<char, string> mp;
        unordered_map<string, char> mp1;
        for(int i = 0; i < res.size(); i++){
            if(mp.find(pattern[i]) == mp.end() && mp1.find(res[i]) == mp1.end()){
                mp[pattern[i]] = res[i];
                mp1[res[i]] = pattern[i];
            }
            else if(mp[pattern[i]] != res[i] || mp1[res[i]] != pattern[i]) return false;
        }
        return true;
    }
};

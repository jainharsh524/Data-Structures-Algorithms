class Solution {
public:
    vector<int> lps(string& s){
        int len = 0;
        int i = 1;
        vector<int> res(s.size(), 0);
        res[len] = 0;
        while(i<s.size()){
            if(s[i]==s[len]){
                len++;
                res[i] = len;
                i++;
            }
            else{
                if(len != 0) len = res[len-1]; 
                else{
                    res[i] = 0;
                    i++;
                }
            }
        }
        return res;
    }
    string longestPrefix(string s) {
        vector<int> res = lps(s);
        // for(int i: res)cout<<i<<" ";
        return s.substr(0, res[s.size()-1]);
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        unordered_map<int, vector<char>> mp;
        int r = 1, inc = 1;
        for(char ch : s){
            mp[r].push_back(ch);
            if(inc) r++;
            else r--;
            if(r == numRows) inc = 0;
            else if(r == 1) inc = 1;
        }
        string res;
        for(int i = 1; i <= numRows; i++){
            for(char ch: mp[i]) res.push_back(ch);
        }
        return res;
    }
};

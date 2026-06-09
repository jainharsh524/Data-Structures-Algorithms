class Solution {
public:
    vector<int> dp;
    bool solve(string& s,vector<string>& wordDict,int index){
        if(index == s.size()) return true;
        if(dp[index] != -1) return dp[index];
        for(string& word : wordDict){
            int len = word.size();
            if(index + len <= s.size() &&
               s.substr(index, len) == word){
                if(solve(s, wordDict, index + len)) return dp[index] = true;
            }
        }
        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size(), -1);
        return solve(s, wordDict, 0);
    }
};

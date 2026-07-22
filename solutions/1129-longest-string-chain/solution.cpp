class Solution {
public:
    bool check(string &a, string &b){
        if(b.size() != a.size() + 1) return false;
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i == a.size();
    }
    int calstr(vector<string>& words, int index, int last, vector<vector<int>>& dp){
        if(index>=words.size()){
            return 0;
        }
        if(dp[index][last+1]!=-1) return dp[index][last+1];
        if(last==-1||check(words[last], words[index])){
            return dp[index][last+1] = max(1+calstr(words, index+1, index, dp), calstr(words, index+1, last, dp));
        }
        else {
            return dp[index][last+1] = calstr(words, index+1, last, dp);
        }
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return calstr(words, 0, -1, dp);
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                mini+=1;
                maxi+=1;
            }
            else if(s[i]==')'){
                mini-=1;
                maxi-=1;
            }
            else if(s[i]=='*'){
                mini-=1;
                maxi+=1;
            }
            if(mini<0) mini =0;
            if(maxi<0) return false;
        }
        return mini<=0&&maxi>=0;
    }
};

// class Solution {
// public:
//     bool check(string &s, int index, int count, vector<vector<int>>& dp) {
//         if(count < 0) return false;
//         if(index == s.size()) return count == 0;
//         if(dp[index][count] != -1)
//             return dp[index][count];
//         if(s[index] == '(')
//             return dp[index][count] = check(s, index + 1, count + 1, dp);
//         if(s[index] == ')')
//             return dp[index][count] = check(s, index + 1, count - 1, dp);
//         return dp[index][count] =
//             check(s, index + 1, count + 1, dp) ||
//             check(s, index + 1, count - 1, dp) ||
//             check(s, index + 1, count, dp);
//     }
//     bool checkValidString(string s) {
//         vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
//         return check(s, 0, 0, dp);
//     }
// };

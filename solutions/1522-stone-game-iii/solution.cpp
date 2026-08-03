class Solution {
public:
    int solve(vector<int>& stoneValue, int i, vector<int>& dp) {
        int n = stoneValue.size();
        if (i >= n) return 0;
        if (dp[i] != INT_MIN) return dp[i];
        int take = 0;
        int ans = INT_MIN;
        for (int k = 0; k < 3 && i + k < n; k++) {
            take += stoneValue[i + k];
            ans = max(ans, take - solve(stoneValue, i + k + 1, dp));
        }
        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        int score = solve(stoneValue, 0, dp);
        if (score > 0) return "Alice";
        if (score < 0) return "Bob";
        return "Tie";
    }
};
// class Solution {
// public:
//     int predict(vector<int>& stoneValue, int l, bool flag,
//                 vector<vector<int>>& dp) {
//         if (l >= stoneValue.size())
//             return 0;
//         int left1 = 0;
//         int left2 = 0;
//         int left3 = 0;
//         if (dp[l][flag] != 0)
//             return dp[l][flag];
//         if (flag) {
//             left1 = stoneValue[l] + predict(stoneValue, l + 1, 1 - flag, dp);
//             if (l + 1 < stoneValue.size())
//                 left2 = stoneValue[l] + stoneValue[l + 1] +
//                         predict(stoneValue, l + 2, 1 - flag, dp);
//             if (l + 2 < stoneValue.size())
//                 left3 = stoneValue[l] + stoneValue[l + 1] + stoneValue[l + 2] +
//                         predict(stoneValue, l + 3, 1 - flag, dp);
//             return dp[l][flag] = max(left1, max(left2, left3));
//         } else {
//             left1 = -stoneValue[l] + predict(stoneValue, l + 1, 1 - flag, dp);
//             if (l + 1 < stoneValue.size())
//                 left2 = -stoneValue[l] - stoneValue[l + 1] +
//                         predict(stoneValue, l + 2, 1 - flag, dp);
//             if (l + 2 < stoneValue.size())
//                 left3 = -stoneValue[l] - stoneValue[l + 1] - stoneValue[l + 2] +
//                         predict(stoneValue, l + 3, 1 - flag, dp);
//             return dp[l][flag] = min(left1, min(left2, left3));
//         }
//     }
//     string stoneGameIII(vector<int>& stoneValue) {
//         vector<vector<int>> dp(stoneValue.size() + 1, vector<int>(2, 0));
//         int score = predict(stoneValue, 0, true, dp);
//         // cout<<score<<endl;
//         if (score > 0)
//             return "Alice";
//         else if (score < 0)
//             return "Bob";
//         else
//             return "Tie";
//     }
// };


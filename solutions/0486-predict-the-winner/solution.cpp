class Solution {
public:
    int predict(vector<int>& nums, int l, int r, bool flag, vector<vector<vector<int>>>& dp){
        if(l>r) return 0;
        int left = 0;
        int right = 0;
        if(dp[l][r][flag]!=0) return dp[l][r][flag];
        if(flag){
            left = nums[l]+predict(nums, l+1, r, 1-flag, dp);
            right = nums[r]+predict(nums, l, r-1, 1-flag, dp);
            return dp[l][r][flag] = max(left, right);
        }
        else{
            left = -nums[l]+predict(nums, l+1, r, 1-flag, dp);
            right = -nums[r]+predict(nums, l, r-1, 1-flag, dp);
            return dp[l][r][flag] = min(left, right);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size(), vector<int>(2, 0)));
        int score = predict(nums, 0, nums.size()-1, true, dp);
        // cout<<score<<endl;
        return score>=0;
    }
};

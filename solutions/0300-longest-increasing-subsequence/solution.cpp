class Solution {
public:
    int calen(vector<int>& nums, int index, int last, vector<vector<int>>& dp){
        if(index==nums.size()) return 0;
        if(dp[index][last + 1] != -1) return dp[index][last + 1];
        if(last==-1||nums[index]>nums[last]){
            return dp[index][last + 1] = max(1+calen(nums, index+1, index, dp), calen(nums, index+1, last, dp));
        }
        else return dp[index][last + 1] = calen(nums, index+1, last, dp);
    } 
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return calen(nums, 0, -1, dp);
    }
};

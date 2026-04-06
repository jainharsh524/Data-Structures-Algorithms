class Solution {
public:
    int count(vector<int>& nums, int index, int last, vector<vector<int>>& dp){
        if(index>=nums.size()) return 0;
        if(dp[index][last+1]!=-1) return dp[index][last+1];
        else{
            int take = 0;
            int skip = 0;
            if((last == -1)||(nums[index]>nums[last])){
                take = 1 + count(nums, index+1, index, dp);
            }
            skip = count(nums, index+1, last, dp);
            return dp[index][last+1] = max(take, skip);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return count(nums, 0, -1, dp);
    }
};

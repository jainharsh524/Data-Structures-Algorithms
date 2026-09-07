class Solution {
public:
    int minCost(int n, vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        nums.push_back(n);
        int m = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(m, vector<int>(m,0));
        for(int i=m-2;i>=1;i--){
            for(int j=i;j<=m-2;j++){
                dp[i][j] = INT_MAX;
                for(int k=i;k<=j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+(nums[j+1]-nums[i-1]));
                }
            }
        }
        return dp[1][m-2];
    }
};

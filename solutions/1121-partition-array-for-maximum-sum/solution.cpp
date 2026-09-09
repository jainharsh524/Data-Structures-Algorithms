class Solution {
public:
    int cal(vector<int>& arr, int index, int k, vector<int>& dp){
        if(index >= arr.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int maxsum = 0;
        int maxele = 0;
        for(int i = 0; i < k && index + i < arr.size(); i++){
            maxele = max(maxele, arr[index + i]);
            int ni = min(int(arr.size()), index + i + 1);
            int sum = maxele * (ni - index) + cal(arr, ni, k, dp);
            maxsum = max(maxsum, sum);
        }
        return dp[index] = maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() + 1, -1);
        return cal(arr, 0, k, dp);
    }
};

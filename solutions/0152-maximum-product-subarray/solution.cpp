class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int result = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            // If x is negative, swap max and min
            if(x < 0) {
                swap(maxEnd, minEnd);
            }

            maxEnd = max(x, maxEnd * x);
            minEnd = min(x, minEnd * x);

            result = max(result, maxEnd);
        }

        return result;
    }
};

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         if(nums.size()==1) return nums[0];
//         vector<int> pre(nums.size(), 1);
//         vector<int> dp(nums.size(), 0);
//         dp[0] = nums[0];
//         int maxres = 0;
//         int mult = 1;
//         for(int i = 0;i<nums.size();i++){
//             if(nums[i]!=0) mult = mult*nums[i];
//             else mult = 0;
//             pre[i] = mult;
//             // if(maxres<mult) maxres = mult;
//             if(mult == 0) mult = 1;
//             if(i>0&&dp[i-1]>0&&nums[i]>0){
//                 dp[i] = max(pre[i], dp[i-1]*nums[i]);
//             }
//             else if(i>0&&dp[i-1]>0&&nums[i]<0){
//                 dp[i] = max(pre[i], max(dp[i-1]*nums[i], nums[i-1]*nums[i]));
//             }
//             else if (i>0&&dp[i-1]<=0&&nums[i]<0){
//                 dp[i] = max(pre[i], max(dp[i-1]*nums[i], nums[i]));
//             }
//             else if (i>0&&dp[i-1]<0&&nums[i]>0){
//                 dp[i] = max(pre[i], max(nums[i], nums[i-1]*nums[i]));
//             }
//         }
//         // for(int i = nums.size()-1;i>=0i--){

//         // }
//         int max = 0;
//         for(int i = 0;i<dp.size();i++){
//             cout<<dp[i]<<" ";
//             if(dp[i]>max) max = dp[i];
//         }
//         return max;
//     }
// };

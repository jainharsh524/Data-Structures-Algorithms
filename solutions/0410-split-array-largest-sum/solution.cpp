class Solution {
public:
    int split(vector<int>& nums, int maxSum){
        int sA = 1;
        int sum = 0;
        for(int ele: nums){
            if(sum+ele<=maxSum) sum+=ele;
            else{
                sA++;
                sum = ele;
            }
        }
        return sA;
    }
    int splitArray(vector<int>& nums, int k) {
        int mini = *max_element(nums.begin(), nums.end());
        int sum = 0;
        for(int ele : nums)
            sum += ele;
        int maxi = sum;
        while(mini<=maxi){
            int mid = mini+(maxi-mini)/2;
            int val = split(nums, mid);
            if(val>k){
                mini = mid+1;
            }
            else maxi = mid-1;
        }
        return mini;
    }
};

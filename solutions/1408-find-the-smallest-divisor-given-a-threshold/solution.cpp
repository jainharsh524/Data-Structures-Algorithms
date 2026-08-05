class Solution {
public:
    int calthre(vector<int>& nums, int divi){
        int sum = 0;
        for(int ele: nums){
            sum = sum+(ele+divi-1)/divi;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mini = 1;
        for(int ele: nums) mini = min(ele, mini);
        int maxi = nums[0];
        for(int ele: nums) maxi = max(ele, maxi);
        int ans = maxi;
        while(mini <= maxi){
            int mid = mini+(maxi-mini)/2;
            int thre = calthre(nums, mid);
            // cout<<mid<<" "<<thre<<endl;
            if(thre>threshold){
                mini = mid+1;
            }
            else{
                ans = min(ans, mid);
                maxi = mid-1;
            }
        }
        return ans;
    }
};

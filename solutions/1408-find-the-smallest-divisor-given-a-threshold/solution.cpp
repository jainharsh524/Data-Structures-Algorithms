class Solution {
public:
    int divsum(vector<int>& nums, int curr){
        int sum = 0;
        for(int ele: nums){
            sum = sum+(ele/curr);
            if(ele%curr!=0) sum++;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = 1;
        int mindiv = -1;
        while(mini<=maxi){
            int mid = mini+(maxi-mini)/2;
            int sum = divsum(nums, mid);
            if(sum<=threshold){
                maxi = mid-1;
                mindiv = mid;
            }
            else mini = mid+1;
        }
        return mindiv;
    }
};

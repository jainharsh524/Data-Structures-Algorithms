class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele = nums[0];
        for(int i = 0;i<nums.size();i++){
            if(ele==nums[i]){
                count++;
            }
            else count--;
            if(count<0){
                ele = nums[i];
                count = 1;
            }
        }
        return ele;
    }
};

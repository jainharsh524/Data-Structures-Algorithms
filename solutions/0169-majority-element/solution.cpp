class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sum = 0;
        int ele = nums[0];
        for(int i =0;i<nums.size();i++){
            if(nums[i]==ele){
                sum++;
            }
            else sum--;
            if(sum == 0){
                ele = nums[i];
                cout<<ele;
                sum = 1;
            }
        }
        return ele;
    }
};

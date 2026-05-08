class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int evenptr = 0;
        int oddptr = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0){
                res[evenptr] = nums[i];
                evenptr+=2;
            }
            else{
                res[oddptr] = nums[i];
                oddptr+=2;
            }
        }
        return res;
    }
};

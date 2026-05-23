class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0) count++;
        }
        int k = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0){
                if(i<(nums.size()-count)) k++;
            }
        }
        return k;
    }
};

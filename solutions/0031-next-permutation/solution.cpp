class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-1;
        int l = n-1;
        while(l>=0){
            if(nums[l+1]>nums[l]){
                int end = n;
                while(end>l){
                    if(nums[end]>nums[l]) break;
                    else end--;
                }
                swap(nums[l], nums[end]);
                cout<<l<<" "<<end;
                reverse(nums.begin()+l+1, nums.end());
                break;
            }
            l--;
        }
        if(l==-1)reverse(nums.begin(), nums.end());
    }
};

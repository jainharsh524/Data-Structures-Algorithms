class Solution {
public:
    vector<int> search(vector<int>& nums, int targetIndex){
        int ptr1 = targetIndex;
        int ptr2 = targetIndex;
        while(ptr1>=0&&ptr2<nums.size()){
            if(nums[ptr1]!=nums[targetIndex]&&nums[ptr2]!=nums[targetIndex]) break;
            if(nums[ptr1]==nums[targetIndex]){
                ptr1--;
            }
            if(nums[ptr2]==nums[targetIndex]){
                ptr2++;
            }
        }
        while(ptr2<nums.size()){
            if(nums[ptr2]!=nums[targetIndex]) break;
            if(nums[ptr2]==nums[targetIndex]){
                ptr2++;
            }
        }
        while(ptr1>=0){
            if(nums[ptr1]!=nums[targetIndex]) break;
            if(nums[ptr1]==nums[targetIndex]){
                ptr1--;
            }
        }
        return {ptr1+1, ptr2-1};
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        vector<int> res(2);
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m]==target){
                cout<<m<<" ";
                return search(nums, m);
            }
            else if(nums[m]<target) l = m+1;
            else h = m-1;
        }
        return {-1, -1};
    }
};

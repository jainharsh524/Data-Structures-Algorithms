class Solution {
public:
    void swap(vector<int>& nums, int index1, int index2){
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    void div(vector<int>& nums, int start, int end){
        if(end-start+1<=1) return;
        else if(end-start+1==2){
            if(nums[end]<nums[start]){
                swap(nums, start, end);
            }
            return;
        }
        else{
            int mid = start+(end-start)/2;
            div(nums, start, mid);
            div(nums, mid+1, end);
            int ptr1 = start, ptr2 = mid+1;
            vector<int> temp;
            while(ptr1<=mid&&ptr2<=end){
                if(nums[ptr1]<=nums[ptr2]){
                    temp.push_back(nums[ptr1]); ptr1++;
                }
                else{
                    temp.push_back(nums[ptr2]);
                    ptr2++;
                }
            }
            while(ptr1<=mid){
                temp.push_back(nums[ptr1]); ptr1++;
            }
            while(ptr2<=mid){
                temp.push_back(nums[ptr2]); ptr2++;
            }
            ptr1 = start;
            for(int i = 0;i<temp.size();i++){
                nums[ptr1] = temp[i];ptr1++;
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        div(nums, 0, nums.size()-1);
        return nums;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int cand1 = 0;
        int cand2 = 0;
        for(int i = 0;i<nums.size();i++){
            if(count1==0&&nums[i]!=cand2){ //curr number should not be equal to cand2;
                cand1 = nums[i];
                count1 = 1;
            }
            else if(count2==0&&nums[i]!=cand1){ //curr number should not be equal to cand1;
                cand2 = nums[i];
                count2 = 1;
            }
            else if(nums[i]==cand1) count1++;
            else if(nums[i]==cand2) count2++;
            else{
                count1--; count2--;
            }
        }
        vector<int> res;
        count1 = 0;
        count2 = 0;
        cout<<cand1<<" "<<cand2<<endl;
        int thre = nums.size()/3;
        for(int ele: nums){
            if(ele==cand1) count1++;
            else if(ele==cand2) count2++;
        }
        if(count1>thre) res.push_back(cand1);
        if(count2>thre) res.push_back(cand2);
        return res;
    }
};

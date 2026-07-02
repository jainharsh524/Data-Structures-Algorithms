class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int lm = 0;
        int rm = 0;
        int start = 0;
        int end = height.size()-1;
        while(start<end){
            lm = max(lm, height[start]);
            rm = max(rm, height[end]);
            if(lm<rm){
                total+=lm-height[start];
                start++;
            }
            else{
                total+=rm-height[end];
                end--;
            }
        }
        return total;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int h = (m*n)-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            int ele = matrix[mid/n][mid%n];
            if(ele==target) return true;
            else if(ele>target) h = mid-1;
            else l = mid+1;
        }
        return false;
    }
};

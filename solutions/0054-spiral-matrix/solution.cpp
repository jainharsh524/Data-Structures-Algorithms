class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int top = 0;
        int bottom = matrix.size()-1;
        int right = matrix[0].size()-1;
        int left = 0;
        while((top<=bottom)&&(left<=right)){
            //left to right
            for(int j = left;j<=right;j++) res.push_back(matrix[top][j]);
            top++;
            //top to bottom
            for(int i = top;i<=bottom;i++) res.push_back(matrix[i][right]);
            right--;
            //right to left
            if(top<=bottom){
                for(int j = right;j>=left;j--) res.push_back(matrix[bottom][j]);
                bottom--;
            }
            //bottom to top
            if(left<=right){
                for(int i = bottom;i>=top;i--) res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};

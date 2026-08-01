class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(int i = 0;i<matrix.size();i++){
            int l = 0;int r = matrix.size()-1;
            while(l<r){
                swap(matrix[i][l], matrix[i][r]);
                l++;
                r--;
            }
        }
    }
};

class Solution {
public:
    void swap(vector<vector<int>>& matrix, int r1, int r2, int c1, int c2){
        int temp = matrix[r1][c1];
        matrix[r1][c1] = matrix[r2][c2];
        matrix[r2][c2] = temp;
    }
    void transpose(vector<vector<int>>& matrix){
        for(int i = 0;i<matrix.size();i++){
            for(int j = i+1;j<matrix[0].size();j++){
                swap(matrix, i, j, j, i);
            }
        }
    }
    void revHo(vector<vector<int>>& matrix){
        for(int i = 0;i<matrix.size();i++){
            int j1 = 0;
            int j2 = matrix.size()-1;
            while(j1<j2){
                swap(matrix, i, i, j1, j2);
                j1++;j2--;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        revHo(matrix);
    }
};

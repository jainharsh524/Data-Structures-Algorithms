class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = 0;
        int m = matrix[0].size()-1;
        int ele = matrix[n][m];
        while(target!=ele&&m>=0&&n<matrix.size()){
            ele = matrix[n][m];
            // cout<<ele<<" "<<n<<" "<<m<<endl;
            if(ele>target) m--;
            else if(ele<target)n++;
        }
        return ele==target;
    }
};

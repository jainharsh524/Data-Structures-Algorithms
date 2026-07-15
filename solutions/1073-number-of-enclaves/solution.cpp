class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c){
        grid[r][c] = 2;
        vector<int> drow = {0, 1, 0, -1};
        vector<int> dcol = {-1, 0, 1, 0};
        for(int i = 0;i<4;i++){
            int nr = r+drow[i];
            int nc = c+dcol[i];
            if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()){
                if(grid[nr][nc]==1){
                    dfs(grid, nr, nc);
                }
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(i==0||j==0||i==grid.size()-1||j==grid[0].size()-1){
                    if(grid[i][j]==1) dfs(grid, i, j);
                }
            }
        }

        int count = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};

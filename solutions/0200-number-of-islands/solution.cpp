class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r<0||r>=grid.size()||c<0||c>=grid[0].size()) return;
        else if(grid[r][c]=='0') return;
        else if(grid[r][c]=='1') {
            grid[r][c]='2';
            vector<int> drow = {1, 0, -1, 0};
            vector<int> dcol = {0, 1, 0, -1};
            for(int i = 0;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                dfs(grid, nr, nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

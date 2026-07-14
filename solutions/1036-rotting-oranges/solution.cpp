class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2) q.push({{i, j}, 0});
            }
        }
        int maxTimer = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int timer = q.front().second;
            q.pop();
            maxTimer = max(timer, maxTimer);
            vector<int> drow = {0, -1, 0, 1};
            vector<int> dcol = {1, 0, -1, 0};
            for(int i = 0;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&grid[nr][nc]==1){
                    grid[nr][nc] = 2;
                    q.push({{nr, nc}, timer+1});
                }
            }
        }
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return maxTimer;
    }
};

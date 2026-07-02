class Solution {
public:
    vector<vector<int>> best;

    bool dfs(vector<vector<int>>& grid, int health, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
            return false;
        if(health < 1)
            return false;
        if(best[r][c] >= health)
            return false;
        best[r][c] = health;
        if(r == grid.size()-1 && c == grid[0].size()-1)
            return true;
        int drow[4] = {0,-1,0,1};
        int dcol[4] = {-1,0,1,0};
        for(int i = 0; i < 4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if(nr >= 0 && nr < grid.size() &&
               nc >= 0 && nc < grid[0].size()){
                int newHealth = health;
                if(grid[nr][nc] == 1)
                    newHealth--;
                if(dfs(grid, newHealth, nr, nc))
                    return true;
            }
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        best.assign(m, vector<int>(n, -1));

        if(grid[0][0] == 1)
            health--;

        return dfs(grid, health, 0, 0);
    }
};

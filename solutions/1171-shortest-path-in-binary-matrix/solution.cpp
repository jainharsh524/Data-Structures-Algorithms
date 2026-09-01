class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        vector<int> drow = {0, 1, 0, -1, -1, -1, 1, 1};
        vector<int> dcol = {1, 0, -1, 0, 1, -1, 1, -1};
        queue<pair<pair<int, int>, int>> q; //r, c, dist;
        q.push({{0, 0}, 1});
        grid[0][0] = 2;
        while(!q.empty()){
            auto ele = q.front();
            int r = ele.first.first;
            int c = ele.first.second;
            int dist = ele.second;
            if(r == (n - 1) && c == (n - 1)) return dist;
            q.pop();
            for(int i = 0;i<8;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr >= 0 && nc >= 0 && 
                nr < n && nc < n 
                && grid[nr][nc] == 0){
                    grid[nr][nc] = 2;
                    q.push({{nr, nc}, dist+1});
                }
            }
        }
        return -1;
    }
};

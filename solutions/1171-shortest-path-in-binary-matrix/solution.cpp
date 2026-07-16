class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        if(grid[0][0]==0) q.push({1, {0, 0}});
        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            int dist = q.front().first;
            cout<<r<<" "<<c<<endl;
            q.pop();
            if(r==grid.size()-1&&c==grid[0].size()-1) return dist;
            vector<int> drow = {-1, 0, 1, 0, 1, -1, 1, -1};
            vector<int> dcol = {0, 1, 0, -1, 1, -1, -1, 1};
            for(int i = 0;i<8;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()){
                    if(grid[nr][nc]==0){
                        grid[nr][nc] = 2;
                        q.push({dist+1, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};

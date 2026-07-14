class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int clr = image[sr][sc];
        if(clr == color) return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vector<int> drow = {0, -1, 0, 1};
            vector<int> dcol = {1, 0, -1, 0};
            for(int i = 0;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                if(nr>=0&&nc>=0&&nr<image.size()&&nc<image[0].size()&&image[nr][nc]==clr){
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};

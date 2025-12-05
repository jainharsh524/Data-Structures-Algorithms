#include <iostream>
using namespace std;
int canBeRotten(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    queue <pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==2){
                visited[i][j] = 2;
                q.push({{i,j},0});
            }
        }
    }
    int max_lvl = 0;
    int dir_row[] = {-1, 0, 1, 0};
    int dir_col[] = {0, 1, 0, -1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int lvl = q.front().second;
        max_lvl = max(lvl, max_lvl);
        q.pop();
        for(int i = 0;i<4;i++){
            int nr = r+dir_row[i];
            int nc = c+dir_col[i];
            if(nr>=0&&nc>=0&&nr<n&&nc<m && grid[nr][nc]==1 && visited[nr][nc] != 2){
                visited[nr][nc] = 2;
                q.push({{nr, nc}, lvl+1});
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(visited[i][j]!=2&&grid[i][j]==1){
                return -1;
            }
        }
    }
    return max_lvl;

}
int main(){
    int n, m;
    cin >> n >> m; // grid dimensions
    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << canBeRotten(grid) << endl;
    return 0;
}
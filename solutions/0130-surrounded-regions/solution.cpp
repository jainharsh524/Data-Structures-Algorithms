class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r<0||r>=board.size()||c<0||c>=board[0].size()) return;
        else if(board[r][c]=='X') return;
        else if(board[r][c]=='O') {
            board[r][c]='2';
            vector<int> drow = {1, 0, -1, 0};
            vector<int> dcol = {0, 1, 0, -1};
            for(int i = 0;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                dfs(board, nr, nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0;i<board.size();i++){
            for(int j= 0;j<board[0].size();j++){
                if(i==0||i==board.size()-1||j==0||j==board[0].size()-1){
                    if(board[i][j]=='O'){
                        dfs(board, i, j);
                    }
                }
            }
        }
        for(int i = 0;i<board.size();i++){
            for(int j= 0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                if(board[i][j]=='2'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};

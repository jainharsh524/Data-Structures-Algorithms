class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> drow = {0, 1, 0, -1, 1, -1, 1, -1};
        vector<int> dcol = {1, 0, -1, 0, 1, 1, -1, -1};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int nr = i + drow[k];
                    int nc = j + dcol[k];
                    if(nr >= 0 && nc >= 0 &&
                       nr < board.size() && nc < board[0].size()){
                        if(board[nr][nc] == 1 || board[nr][nc] == 2) cnt++;
                    }
                }
                if(board[i][j] == 1){
                    if(cnt < 2 || cnt > 3) board[i][j] = 2;
                }
                else{
                    if(cnt == 3) board[i][j] = 3;
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 2) board[i][j] = 0;
                else if(board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};

class Solution {
public:
    bool isValidRow(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            vector<int> mp(10, 0);
            for(int j = 0; j < 9; j++){
                if(isdigit(board[i][j])){
                    if(!mp[board[i][j] - '0']) mp[board[i][j] - '0'] = 1;
                    else return false;
                }
            }
        }
        return true;
    }
    bool isValidCol(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            vector<int> mp(10, 0);
            for(int j = 0; j < 9; j++){
                if(isdigit(board[j][i])){
                    if(!mp[board[j][i] - '0']) mp[board[j][i] - '0'] = 1;
                    else return false;
                }
            }
        }
        return true;
    }
    bool isValidBox(vector<vector<char>>& board){
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j< 9; j+=3){
                vector<int> mp(10, 0);
                for(int a = i; a < i+3; a++){
                    for(int b = j; b < j+3; b++){
                        if(isdigit(board[a][b])){
                            if(!mp[board[a][b] - '0']) mp[board[a][b] - '0'] = 1;
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidRow(board) && isValidCol(board) && isValidBox(board);
    }
};

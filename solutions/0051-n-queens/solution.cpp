class Solution {
public:
    bool isSafe(vector<string>& res, int r, int c){
        int i = r;int j =c;
        while(i>=0&&j>=0){
            if(res[i][j]!='Q'){
                i--;j--;
            }
            else return false;
        }
        i = r;j =c;
        while(i<res.size()&&j<res.size()){
            if(res[i][j]!='Q'){
                i++;j++;
            }
            else return false;
        }
        i = r;j =c;
        while(i>=0&&j<res.size()){
            if(res[i][j]!='Q'){
                i--;j++;
            }
            else return false;
        }
        i = r;j =c;
        while(i<res.size()&&j>=0){
            if(res[i][j]!='Q'){
                i++;j--;
            }
            else return false;
        }
        i = r;j = c;
        while(i>=0){
            if(res[i][j]!='Q'){
                i--;
            }
            else return false;
        }
        i = r;j = c;
        while(j>=0){
            if(res[i][j]!='Q'){
                j--;
            }
            else return false;
        }
        i = r;j = c;
        while(i<res.size()){
            if(res[i][j]!='Q'){
                i++;
            }
            else return false;
        }
        i = r;j = c;
        while(j<res.size()){
            if(res[i][j]!='Q'){
                j++;
            }
            else return false;
        }
        return true;
    }
    void solve(int r, int c, vector<vector<string>>& final, vector<string> res){
        if(isSafe(res, r, c)) res[r][c] = 'Q';
        else return;
        if((r==res.size()-1)){
            final.push_back(res);
            return;
        }
        for(int i = 0;i<res.size();i++){
            solve(r+1, i,final, res);
        }
        res[r][c] = '.';
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        for(int i = 0;i<n;i++){
            vector<string> temp(n, string(n, '.'));
            solve(0, i, res, temp);
        }
        return res;
    }
};

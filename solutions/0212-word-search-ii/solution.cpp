struct TrieNode{
    TrieNode* alpha[26];
    bool isEnd;
    string word;
    TrieNode(){
        for(auto &nd: alpha){
            nd = NULL;
        }
        isEnd = false;
    }
};
class Solution {
public:
    void dfs(vector<vector<char>>& board, TrieNode* node,
         int r, int c, vector<string> &res){
        char ch = board[r][c];
        if(ch=='#' || node->alpha[ch-'a']==NULL)
            return;
        node = node->alpha[ch-'a'];
        if(node->isEnd){
            res.push_back(node->word);
            node->isEnd = false;
        }
        board[r][c] = '#';
        int drow[4] = {0,1,0,-1};
        int dcol[4] = {1,0,-1,0};
        for(int i=0;i<4;i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size()) dfs(board,node,nr,nc,res);
        }
        board[r][c] = ch;
    }
    void insert(string word, TrieNode* root){
        TrieNode* curr = root;
        for(int i = 0;i<word.size();i++){
            if(curr->alpha[word[i]-'a']==NULL) curr->alpha[word[i]-'a'] = new TrieNode();
            curr = curr->alpha[word[i]-'a'];
        }
        curr->isEnd = true;
        curr->word = word;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = new TrieNode();
        for(string w: words) insert(w, root);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board, root, i, j, res);
            }
        }
    return res;
    }
};

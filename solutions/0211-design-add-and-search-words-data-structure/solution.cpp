struct trieNode{
    trieNode* alpha[26];
    bool isEnd;
    trieNode(){
        isEnd = false;
        for(int i = 0;i<26;i++){
            alpha[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    trieNode *root;

    WordDictionary() {
        root = new trieNode();
    }
    
    void addWord(string word) {
        trieNode* curr = root;
        for(int i = 0;i<word.size();i++){
            if(curr->alpha[word[i]-'a']==NULL) curr->alpha[word[i]-'a'] = new trieNode();
            curr = curr->alpha[word[i]-'a'];
        }
        curr->isEnd = true;
    }
    
    bool modSearch(trieNode* curr, string &word, int index){
        for(int i = index; i < word.size(); i++){
            if(word[i] == '.'){
                for(int j = 0; j < 26; j++){
                    if(curr->alpha[j]){
                        trieNode* next = curr->alpha[j];
                        if(modSearch(next, word, i+1))
                            return true;
                    }
                }
                return false;
            }
            else if(curr->alpha[word[i]-'a'] == NULL)
                return false;
            curr = curr->alpha[word[i]-'a'];
        }
        return curr->isEnd;
    }
    bool search(string word) {
        trieNode* curr = root;
        for(int i = 0;i<word.size();i++){
            if(word[i] == '.'){
                for(int j = 0;j<26;j++){
                    if(curr->alpha[j]){
                        trieNode* next = curr->alpha[j];
                        if(modSearch(next, word, i+1)) return true;
                    }
                }
                return false;   // FIX
            }
            else if(curr->alpha[word[i]-'a']==NULL) return false;
            else curr = curr->alpha[word[i]-'a'];
        }
        return curr->isEnd;
    }
};

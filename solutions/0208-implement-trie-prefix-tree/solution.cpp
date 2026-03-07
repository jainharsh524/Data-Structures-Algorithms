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
class Trie {
public:
    trieNode* root;
    Trie() {
        root = new trieNode();
    }
    
    void insert(string word) {
        trieNode* curr = root;
        for(int i = 0;i<word.size();i++){
            if(curr->alpha[word[i]-'a']==NULL) curr-> alpha[word[i]-'a'] = new trieNode();
            curr = curr->alpha[word[i]-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        trieNode* curr = root;
        for(int i = 0;i<word.size();i++){
            if(curr->alpha[word[i]-'a']==NULL) return false;
            else{
                curr = curr->alpha[word[i]-'a'];
            }
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        trieNode* curr = root;
        for(int i = 0;i<prefix.size();i++){
            if(curr->alpha[prefix[i]-'a']==NULL) return false;
            else{
                curr = curr->alpha[prefix[i]-'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

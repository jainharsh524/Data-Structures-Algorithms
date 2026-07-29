class Trie {
public:
    struct trieNode{
        trieNode* alpha[26];
        bool isEnd;
        trieNode(){
            for(int i = 0;i<26;i++) alpha[i] = NULL;
            isEnd=false;
        }
    };
    trieNode* root;
    Trie() {
        root = new trieNode();
    }
    
    void insert(string word) {
        trieNode* curr = root;
        for(char ch: word){
            if(!curr->alpha[ch-'a']){
                curr->alpha[ch-'a'] = new trieNode();
            }
            curr = curr->alpha[ch-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        trieNode* curr = root;
        for(char ch: word){
            if(!curr->alpha[ch-'a']) return false;
            curr = curr->alpha[ch-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        trieNode* curr = root;
        for(char ch: prefix){
            if(!curr->alpha[ch-'a']) return false;
            curr = curr->alpha[ch-'a'];
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

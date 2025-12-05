#include <iostream>
using namespace std;
struct trieNode{
    trieNode* alpha[26];
    bool isEnd;
    int count;
    trieNode(){
        isEnd = false;
        for(int i = 0;i<26;i++){
            alpha[i] = NULL;
        }
        count = 0;
    }
};
class trie{
    trieNode *root;
    public:
        trie(){
            root = new trieNode();
        }
        void insertWithCount(const string& val){
            trieNode *curr = root;
            for(char ch: val){
                int index = ch-'a';
                if(curr->alpha[index]==NULL){
                    curr->alpha[index] = new trieNode();
                    curr->count++;
                }
                else{
                    curr->count++;
                }
                curr = curr->alpha[index];
            }
            curr->isEnd = true;
        }
        bool search(const string &val){
            trieNode* curr = root;
            for(char ch: val){
                int index = ch-'a';
                if(curr->alpha[index]==NULL) return false;
                curr = curr->alpha[index];
            }
            return curr->isEnd;
        }
        int countFreq(const string& val) {
            trieNode* curr = root;
            for (char ch : val) {
                int index = ch - 'a';
                if (curr->alpha[index] == NULL) {
                    return 0;
                }
                curr = curr->alpha[index];
            }
            return curr->count;
        }
        void del(const string& val){
            if (!search(val)) return;
            trieNode* curr = root;
            if(search(val)){
                for(char ch: val){
                    int index = ch-'a';
                    curr->alpha[index]->count--;
                    curr = curr->alpha[index];
                }
            }
            curr->isEnd = false;
        }
        bool isComplete(const string &val){
            trieNode* curr = root;
            for(char ch: val){
                int index = ch-'a';
                if (curr->alpha[index] == NULL || !curr->alpha[index]->isEnd)
                    return false;
                curr = curr->alpha[index];
            }
            return true;
        }
};
int main(){
    trie tr;
    string a;
    string b;
    string c;
    string d;
    cin>>a>>b>>c>>d;
    tr.insertWithCount(a);
    tr.insertWithCount(b);
    tr.insertWithCount(c);
    tr.insertWithCount(d);
    // cout<<tr.countFreq("brother")<<endl;
    // cout<<tr.countFreq("bro")<<endl;
    // tr.del("bro");
    // cout<<tr.countFreq("bro");
    cout<<tr.isComplete("bro");
    return 0;
}
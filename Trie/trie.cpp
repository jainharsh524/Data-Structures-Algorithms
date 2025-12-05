#include <iostream>
using namespace std;
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
class trie{
    trieNode* root;
    public:
        trie(){
            root = new trieNode();
        }

        void insert(const string &val){
            trieNode *curr = root;
            for(char ch: val){
                int index = ch-'a';
                if(curr->alpha[index]==NULL){
                    curr->alpha[index] = new trieNode();
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

        bool startsWith(const string& prefix){
            trieNode* curr = root;
            for(char ch: prefix){
                int index = ch-'a';
                if(curr->alpha[index]==NULL){
                    return false;
                }
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
    cin>>a>>b>>c;
    tr.insert(a);
    tr.insert(b);
    tr.insert(c);
    cout<<"Searching"<<tr.search(a)<<"\n";
    cout<<"Searching"<<tr.search("search")<<"\n";
    cout<<"startswith"<<tr.startsWith("seedhe");
    return 0;
}
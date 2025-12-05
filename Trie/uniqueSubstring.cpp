#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* alpha[26];
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            alpha[i] = NULL;
        }
    }
};

class Trie {
    TrieNode* root;

public:
    int count; // count unique nodes created

    Trie() {
        root = new TrieNode();
        count = 0;
    }

    // Insert substring into trie, count new nodes created
    void insert(const string& val) {
        TrieNode* curr = root;
        for (char ch : val) {
            int index = ch - 'a';
            if (curr->alpha[index] == NULL) {
                curr->alpha[index] = new TrieNode();
                count++; // new unique path
            }
            curr = curr->alpha[index];
        }
    }

    // Count unique substrings of string val
    int countUnique(const string& val) {
        for (int i = 0; i < val.length(); i++) {
            string substr = "";
            for (int j = i; j < val.length(); j++) {
                substr += val[j];
                insert(substr);
            }
        }
        return count;
    }
};

int main() {
    Trie tr;
    string s, a;
    cin >> s>>a;
    cout << "Unique substrings: " << tr.countUnique(s) << endl;
    cout <<"Unique substrings: " << tr.countUnique(a) << endl;
    return 0;
}

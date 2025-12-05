#include <iostream>
#include <set>
#include <numeric>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    string word;

    TrieNode() {
        isEnd = false;
        word = "";
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
        curr->word = word;
    }

    void searchRec(TrieNode* node, const string& query, int k,
                   vector<int>& prevRow, set<string>& result) {
        int m = query.size();

        // DP row for this node
        vector<int> currRow(m + 1);
        currRow[0] = prevRow[0] + 1;

        for (int j = 1; j <= m; j++) {
            if (node->word.size() > 0 && node->word.back() == query[j - 1])
                currRow[j] = prevRow[j - 1]; // same char
            else
                currRow[j] = min({prevRow[j - 1], prevRow[j], currRow[j - 1]}) + 1;
        }

        // If this node is a word and within distance k → add result
        if (node->isEnd && currRow[m] <= k) result.insert(node->word);

        // Prune if min in row > k
        if (*min_element(currRow.begin(), currRow.end()) <= k) {
            for (int c = 0; c < 26; c++) {
                if (node->children[c]) {
                    searchRec(node->children[c], query, k, currRow, result);
                }
            }
        }
    }

    vector<string> searchWithEditDistance(const string& query, int k) {
        vector<string> ans;
        set<string> result;

        int m = query.size();
        vector<int> startRow(m + 1);
        iota(startRow.begin(), startRow.end(), 0); // dp[0..m] = [0,1,2,...]

        for (int c = 0; c < 26; c++) {
            if (root->children[c]) {
                searchRec(root->children[c], query, k, startRow, result);
            }
        }

        ans.assign(result.begin(), result.end());
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    Trie trie;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        string query;
        int k;
        cin >> query >> k;

        vector<string> res = trie.searchWithEditDistance(query, k);
        if (res.empty())
            cout << "No suggestions found\n";
        else {
            for (auto& w : res) cout << w << " ";
            cout << "\n";
        }
    }
    return 0;
}

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return {};

        unordered_map<string, vector<string>> patternMap;

        int L = beginWord.size();

        for(string &word : wordList){
            for(int i = 0; i < L; i++){
                string pattern = word;
                pattern[i] = '*';
                patternMap[pattern].push_back(word);
            }
        }

        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> level;

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        while(!q.empty()){
            string curr = q.front(); q.pop();
            int currLevel = level[curr];
            for(int i = 0; i < L; i++){
                string pattern = curr;
                pattern[i] = '*';
                for(string &next : patternMap[pattern]){
                    if(!level.count(next)){
                        level[next] = currLevel + 1;
                        q.push(next);
                        parents[next].push_back(curr);
                    }
                    else if(level[next] == currLevel + 1){
                        parents[next].push_back(curr);
                    }
                }
            }
        }
        vector<vector<string>> res;
        vector<string> temp;
        function<void(string)> dfs = [&](string word){
            temp.push_back(word);
            if(word == beginWord){
                vector<string> path = temp;
                reverse(path.begin(), path.end());
                res.push_back(path);
            }
            else{
                for(string &p : parents[word]){
                    dfs(p);
                }
            }
            temp.pop_back();
        };
        if(level.count(endWord))
            dfs(endWord);
        return res;
    }
};

class Solution {
public:
    bool isEdge(string a, string b){
        int count = 0;
        for(int i = 0;i < a.size();i++){
            if(a[i] != b[i]) count++;
        }
        return count == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        queue<pair<int, int>> q;
        vector<int> visited(wordList.size(), 0);
        for(int i = 0;i < wordList.size();i++){
            if(isEdge(beginWord, wordList[i])){
                q.push({i, 2});
                visited[i] = 1;
            }
        }
        while(!q.empty()){
            int index = q.front().first;
            int dist = q.front().second;
            string curr = wordList[index];
            q.pop();
            if(curr == endWord) return dist;
            for(int i = 0;i < wordList.size();i++){
                if(isEdge(wordList[i], curr) && !visited[i]){
                    q.push({i, dist + 1});
                    visited[i] = 1;
                }
            }
        }
        return 0;
    }
};

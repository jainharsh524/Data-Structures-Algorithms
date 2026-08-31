class Solution {
public:
    bool isEdge(string& a,string& b){
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) count++;
            if(count>1) return false;
        }
        return count==1;
    }
    void dfs(string word,string beginWord,
             unordered_map<string,vector<string>>& parent,
             vector<string>& path,
             vector<vector<string>>& res){
        if(word==beginWord){
            reverse(path.begin(),path.end());
            res.push_back(path);
            reverse(path.begin(),path.end());
            return;
        }
        for(string p:parent[word]){
            path.push_back(p);
            dfs(p,beginWord,parent,path,res);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord,string endWord, vector<string>& wordList){

        unordered_set<string> words(wordList.begin(),wordList.end());
        if(!words.count(endWord)) return {};

        unordered_map<string,vector<string>> parent;
        unordered_set<string> current;
        current.insert(beginWord);
        bool found=false;
        while(!current.empty() && !found){
            for(string word:current) words.erase(word);
            unordered_set<string> next;
            for(string word:current){
                for(string& candidate:wordList){
                    if(words.count(candidate) && isEdge(word,candidate)){
                        next.insert(candidate);
                        parent[candidate].push_back(word);
                        if(candidate==endWord) found=true;
                    }
                }
            }
            current=move(next);
        }
        if(!found) return {};
        vector<vector<string>> res;
        vector<string> path={endWord};
        dfs(endWord,beginWord,parent,path,res);
        return res;
    }
};

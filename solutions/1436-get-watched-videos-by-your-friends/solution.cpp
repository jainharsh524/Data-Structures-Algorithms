#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id,
        int level
    ) {
        int n = friends.size();
        vector<bool> visited(n, false);
        queue<int> q;

        // BFS initialization
        visited[id] = true;
        q.push(id);

        // Traverse exactly 'level' levels
        for (int lvl = 0; lvl < level; ++lvl) {
            int sz = q.size();
            while (sz-- > 0) {
                int u = q.front(); q.pop();
                for (int v : friends[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        // Count video frequencies
        unordered_map<string, int> freq;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const string& vid : watchedVideos[u])
                ++freq[vid];
        }

        // Sort by (frequency ascending, video name)
        set<pair<int, string>> sortedVideos;
        for (auto& [vid, cnt] : freq)
            sortedVideos.insert({cnt, vid});

        // Build result
        vector<string> result;
        for (auto& [cnt, vid] : sortedVideos)
            result.push_back(vid);

        return result;
    }
};


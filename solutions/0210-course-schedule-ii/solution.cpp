class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        // Build graph and indegree array
        for (auto &p : prerequisites) {
            int course = p[0];
            int pre    = p[1];
            adj[pre].push_back(course);
            indeg[course]++;
        }

        queue<int> q;
        // Push all nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int nxt : adj[node]) {
                indeg[nxt]--;
                if (indeg[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        // If we did not process all courses, there is a cycle
        if ((int)topo.size() != numCourses) {
            return {};
        }
        return topo;
    }
};

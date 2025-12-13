class Solution {
public:
    void dfs(vector<int> &visited, int source, vector<vector<int>> &rooms){
        visited[source] = 1;
        for(int i : rooms[source]){
            if(!visited[i]) dfs(visited, i, rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        dfs(visited, 0, rooms);
        for(int i : visited){
            if(i!=1) return false;
        }
        return true;
    }
};

class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet s(n*n);
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j]==0) continue;
                int drow[] = {-1,0,1,0};
                int dcol[] = {0,-1,0,1};
                for(int k=0 ; k<4 ; k++)
                {
                    int adjRow = i+drow[k];
                    int adjCol = j+dcol[k];
                    if(adjRow>=0 && adjCol>=0 && adjRow<n && adjCol<n)
                    {
                        if(grid[adjRow][adjCol]==1)
                        {
                            int nodeNo = i*n+j;
                            int adjNodeNo = adjRow*n+adjCol;
                            s.unionBySize(nodeNo , adjNodeNo);
                        }
                    }
                }
            }
        }
        //step 2
        
        int mx=0;
         for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j]==1) continue;
                int drow[] = {-1,0,1,0};
                int dcol[] = {0,-1,0,1};
                set<int> components;
                for(int k=0 ; k<4 ; k++)
                {
                    int adjRow = i+drow[k];
                    int adjCol = j+dcol[k];
                    if(adjRow>=0 && adjCol>=0 && adjRow<n && adjCol<n)
                    {
                        if(grid[adjRow][adjCol]==1)
                        {
                            components.insert(s.findParent(adjRow*n+adjCol));
                        }
                    }
                }
                int sizeTotal=0;
                for(auto it : components)
                {
                    sizeTotal+=s.size[it];
                }
                mx=max(mx,sizeTotal+1);
            }
        }
        for(int i=0 ; i<n*n; i++)
        {
            mx=max(mx , s.size[s.findParent(i)]);
        }
        return mx;
    }
};

class Solution {
public:
    bool isCycle(int source, vector<int> &visited, vector<vector<int>> &adj_lst, vector<int> &path){
        visited[source] = 1;
        path[source] = 1;
        for(int nei: adj_lst[source]){
            if(!visited[nei]){
                if(isCycle(nei, visited, adj_lst, path)){
                    return true;
                }
            }
            else if(path[nei]){
                return true;
            }
        }
        path[source] = 0;
        return false;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i = 0;i<n;i++){
            if(count(leftChild.begin(), leftChild.end(), i)>0&&count(rightChild.begin(), rightChild.end(), i)>0){
                return false;
            }
        }
        int count1 = 0;
        for(int i = 0;i<n;i++){
            if(count(leftChild.begin(), leftChild.end(), i)==0&&count(rightChild.begin(), rightChild.end(), i)==0){
                count1++;
            }
        }
        if(count1!=1){
            return false;
        }
        vector<vector<int>> adj_lst(n);
        for(int i = 0;i<n;i++){
            if (leftChild[i] != -1)
                adj_lst[i].push_back(leftChild[i]);

            if (rightChild[i] != -1)
                adj_lst[i].push_back(rightChild[i]);

        }
        vector<int> visited(n, 0);
        vector<int> path(n, 0);
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                if(isCycle(i, visited, adj_lst, path)) return false;;
            }
        }
        return true;
    }
};

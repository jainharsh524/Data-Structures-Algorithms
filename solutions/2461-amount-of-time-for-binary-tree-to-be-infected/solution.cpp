/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<int, vector<int>>& adj_lst, TreeNode* parent) {
		if (root == NULL)
			return;
		vector<int> temp;
		if (root->right)
			temp.push_back(root->right->val);
		if (root->left)
			temp.push_back(root->left->val);
		if (parent)
			temp.push_back(parent->val);
		adj_lst[root->val] = temp;
		dfs(root->right, adj_lst, root);
		dfs(root->left, adj_lst, root);
	}
	int amountOfTime(TreeNode* root, int target) {
		// code here
		unordered_map<int, vector<int>> adj_lst;
		dfs(root, adj_lst, NULL);
		// dist, node
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		pq.push({0, target});
		unordered_map<int, int> visited;
		int dist = 0;
		while (!pq.empty()) {
			dist = pq.top().first;
			int node = pq.top().second;
			pq.pop();
			visited[node] = 1;
			for (int ele: adj_lst[node]) {
				if (!visited[ele]) {
					pq.push({dist + 1, ele});
				}
			}
		}
		return dist;
	}
};

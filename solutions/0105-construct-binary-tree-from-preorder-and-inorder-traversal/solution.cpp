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
    int preInd = 0;
    int search(vector<int>& in, int target, int inStart, int inEnd){
        for(int i = inStart; i <= inEnd;i++){
            if(in[i] == target) return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& pre, vector<int>& in, int inStart, int inEnd){
        if(preInd >= pre.size() || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(pre[preInd++]);
        int inInd = search(in, pre[preInd-1], inStart, inEnd);
        root->left = build(pre, in , inStart, inInd - 1);
        root->right = build(pre, in, inInd+1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};

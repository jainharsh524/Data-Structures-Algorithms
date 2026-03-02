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
    int search(vector<int>& inorder, int inStart, int inEnd, int val){
        for(int i = inStart;i<=inEnd;i++){
            if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* treeBuilder(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int &postIndex){
        if(inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postIndex--]);
        if(inStart==inEnd) return root;
        int inIndex = search(inorder, inStart, inEnd, root->val);
        root->right = treeBuilder(inorder, postorder, inIndex+1, inEnd, postIndex);
        root->left = treeBuilder(inorder, postorder, inStart, inIndex-1, postIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size()-1;
        return treeBuilder(inorder, postorder, 0, inorder.size()-1, postIndex);
    }
};

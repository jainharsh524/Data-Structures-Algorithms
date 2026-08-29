class Solution {
public:
    int preIdx = 0;
    int searchIn(int left, int right, vector<int>& inorder, int target){
        for(int i = left; i <= right; i++){
            if(inorder[i] == target)
                return i;
        }
        return -1;
    }
    TreeNode* build(int left, int right,
                    vector<int>& preorder,
                    vector<int>& inorder){
        if(left > right)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        int rootIndex = searchIn(left, right, inorder, root->val);
        root->left = build(left, rootIndex - 1, preorder, inorder);
        root->right = build(rootIndex + 1, right, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, inorder.size() - 1, preorder, inorder);
    }
};

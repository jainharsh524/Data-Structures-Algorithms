class Solution {
public:
    int search(vector<int>& inorder, int start, int end, int target) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target)
                return i;
        }
        return -1;
    }

    TreeNode* treeBuilder(vector<int>& preorder, vector<int>& inorder,
                          int inStart, int inEnd, int &preIndex) {

        if (inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;

        if (inStart == inEnd)
            return root;

        int inIndex = search(inorder, inStart, inEnd, root->val);

        root->left = treeBuilder(preorder, inorder,
                                 inStart, inIndex - 1, preIndex);

        root->right = treeBuilder(preorder, inorder,
                                  inIndex + 1, inEnd, preIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        return treeBuilder(preorder, inorder,
                           0, inorder.size() - 1, preIndex);
    }
};

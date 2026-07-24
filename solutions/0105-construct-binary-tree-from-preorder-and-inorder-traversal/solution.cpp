class Solution{
public:
    TreeNode* treeBuilder(vector<int>& preorder,vector<int>& inorder,int inStart,int inEnd,int& preIndex,unordered_map<int,int>& mp){
        if(inStart>inEnd)return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int inIndex = mp[root->val];
        root->left = treeBuilder(preorder,inorder,inStart,inIndex-1,preIndex,mp);
        root->right = treeBuilder(preorder,inorder,inIndex+1,inEnd,preIndex,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder){
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        int preIndex=0;
        return treeBuilder(preorder,inorder,0,inorder.size()-1,preIndex,mp);
    }
};

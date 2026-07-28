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
    void inord(vector<int>& inorder,TreeNode* root){
        if(root==NULL)return;
        inord(inorder,root->left);
        inorder.push_back(root->val);
        inord(inorder,root->right);
    }
    bool findTarget(TreeNode* root,int k){
        vector<int> inorder;
        inord(inorder,root);
        for(int i=0;i<inorder.size();i++){
            int target=k-inorder[i];
            int l=0,h=inorder.size()-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(inorder[mid]==target){
                    if(mid!=i)return true;
                    break;
                }
                else if(inorder[mid]<target) l=mid+1;
                else h=mid-1;
            }
        }
        return false;
    }
};

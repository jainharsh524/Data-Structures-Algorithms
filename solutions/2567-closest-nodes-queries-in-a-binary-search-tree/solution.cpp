class Solution{
public:
    void inorder(TreeNode* root,vector<int>& arr){
        if(root==NULL)return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    vector<vector<int>> closestNodes(TreeNode* root,vector<int>& queries){
        vector<int> arr;
        inorder(root,arr);
        vector<vector<int>> res;
        for(int q:queries){
            auto it=lower_bound(arr.begin(),arr.end(),q);
            int floor=-1,ceil=-1;
            if(it!=arr.end())ceil=*it;
            if(it!=arr.end()&&*it==q)floor=*it;
            else if(it!=arr.begin())floor=*(it-1);
            res.push_back({floor,ceil});
        }
        return res;
    }
};

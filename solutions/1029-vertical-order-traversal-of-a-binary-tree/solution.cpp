class Solution {
public:
    struct Node{
        TreeNode* nd;
        Node* left;
        Node* right;
        int r;
        int c;

        Node(TreeNode* root,int row,int col){
            nd=root;
            r=row;
            c=col;
            left=nullptr;
            right=nullptr;
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root){
        if(root==nullptr) return {};
        queue<Node*> q;
        Node* rt=new Node(root,0,0);
        q.push(rt);
        int minwid=INT_MAX,maxwid=INT_MIN;
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            minwid=min(minwid,curr->c);
            maxwid=max(maxwid,curr->c);
            if(curr->nd->left){
                curr->left=new Node(curr->nd->left,curr->r+1,curr->c-1);
                q.push(curr->left);
            }
            if(curr->nd->right){
                curr->right=new Node(curr->nd->right,curr->r+1,curr->c+1);
                q.push(curr->right);
            }
        }
        vector<vector<int>> res(maxwid-minwid+1);

        queue<Node*> nq;
        nq.push(rt);

        while(!nq.empty()){
            int sz=nq.size();
            vector<Node*> level;
            while(sz--){
                Node* curr=nq.front();
                nq.pop();
                level.push_back(curr);
                if(curr->left) nq.push(curr->left);
                if(curr->right) nq.push(curr->right);
            }
            sort(level.begin(),level.end(),[](Node* a,Node* b){
                if(a->c!=b->c)
                    return a->c<b->c;
                return a->nd->val<b->nd->val;
            });
            for(Node* curr:level)
                res[curr->c-minwid].push_back(curr->nd->val);
        }
        return res;
    }
};

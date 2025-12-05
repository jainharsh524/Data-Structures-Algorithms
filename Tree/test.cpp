#include <iostream>
using namespace std;
struct treeNode{
    int val;
    treeNode* left;
    treeNode* right;
    treeNode(int value){
        val = value;
        left = NULL;
        right = NULL;
    }
};
treeNode* insert(vector<int> lvlOrder){
    int index = 0;
    treeNode* root = new treeNode(lvlOrder[index++]);
    queue<treeNode*> q;
    q.push(root);
    while(!q.empty()){
        treeNode* curr = q.front();
        q.pop();
        if (index < lvlOrder.size()) {
            if (lvlOrder[index] != -1) {
                curr->left = new treeNode(lvlOrder[index]);
                q.push(curr->left);
            } else {
                curr->left = nullptr;
            }
            index++;
        }

        // Right child
        if (index < lvlOrder.size()) {
            if (lvlOrder[index] != -1) {
                curr->right = new treeNode(lvlOrder[index]);
                q.push(curr->right);
            } else {
                curr->right = nullptr;
            }
            index++;
        }
    }
    return root;
}
void dfs(treeNode* root){
    if(root==NULL) return;
    cout<<root->val;
    dfs(root->left);
    dfs(root->right);
}
vector<int> bfs(treeNode* root){
    queue<treeNode*> q;
    q.push(root);
    vector<int> lvlOrder;
    while(!q.empty()){
        treeNode* curr = q.front();
        lvlOrder.push_back(curr->val);
        q.pop();
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
    return lvlOrder;
}
int depth(treeNode* root){
    if(root==NULL) return 0;
    return 1+ max(depth(root->left), depth(root->right));
}
bool isBalanced(treeNode *root){
    if(root == NULL) return true;
    if(abs(depth(root->left)-depth(root->right))<=1){
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    else {
        return false;
    }
}
int diameter(treeNode *root, int &res){ //res is diameter
    if(root==NULL) return 0;
    int left = diameter(root->left, res);
    int right = diameter(root->right, res);
    res = max(res, left+right);
    return max(left, right)+1;
}
int maxPathSum(treeNode* root, int &sum){
    if(root==NULL) return 0;
    int left = maxPathSum(root->left, sum);
    int right = maxPathSum(root->right, sum);
    sum = max(sum, left+right+root->val);
    return max(left, right) + root->val; //basically we can only choose one path either left or right, so we take maximum
}
vector<vector<int>> zigzag(treeNode* root){
    bool flag = true;
    vector<vector<int>> zig;
    queue<treeNode*> q;
    q.push(root);
    while(!q.empty()){
        int lvlsize = q.size();
        vector<int> currLvl(lvlsize);
        for(int i = 0;i<lvlsize;i++){
            treeNode* curr = q.front();
            q.pop();
            (flag)?currLvl[i] = curr->val:currLvl[q.size()-i-1] = curr->val;
            if(curr->left)  q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        zig.push_back(currLvl);
        flag = !flag;
    }
    return zig;
}
bool isLeaf(treeNode* curr){
    return curr->left==NULL && curr->right==NULL;
}
void leftboundary(treeNode* root, vector<int> &left){
    if(root==NULL) return;
    if(!isLeaf(root)){
        left.push_back(root->val);
        if(root->left){
            leftboundary(root->left, left);
        }
        else{
            leftboundary(root->right, left);
        }
    }
    else return;
}
void rightboundary(treeNode* root, vector<int> &right){
    if(root==NULL) return;
    if(!isLeaf(root)){
        right.push_back(root->val);
        if(root->right){
            rightboundary(root->right, right);
        }
        else{
            rightboundary(root->left, right);
        }
    }
    else return;
}
void leafNodes(treeNode* root, vector<int> &leaves){
    if(root==NULL) return;
    if(isLeaf(root)){
        leaves.push_back(root->val);
        return;
    }
    if(root->left) leafNodes(root->left, leaves);
    if(root->right) leafNodes(root->right, leaves);
}
vector<int> boundaryTraversal(treeNode* root){
    vector<int> right;
    vector<int> left;
    vector<int> leaves;
    vector<int> boundary;
    leftboundary(root, left);
    leafNodes(root, leaves);
    rightboundary(root->right, right);
    reverse(right.begin(), right.end());
    for(auto iter: left){
        boundary.push_back(iter);
    }
    for(auto iter: leaves){
        boundary.push_back(iter);
    }
    for(auto iter: right){
        boundary.push_back(iter);
    }
    return boundary;
}
vector<int> verticalOrderTraversal(treeNode* root){

}
vector<int> top_view(treeNode* root){
    vector<int> filled(500, 0);
    vector<int> topV(500, 0);
    queue<pair<treeNode*, int>> q;int minlvl = INT_MAX;int maxlvl = INT_MIN;
    q.push({root, 0});
    int offset = 250;
    while(!q.empty()){
        treeNode* curr = q.front().first;
        int lvl = q.front().second;
        q.pop();
        if(!filled[offset+lvl]) {
            filled[offset+lvl] = 1;
            topV[offset+lvl] = curr->val;
            if(lvl<=minlvl) minlvl = lvl;
            if(lvl>=maxlvl) maxlvl = lvl;
        }
        if(curr->left){
            q.push({curr->left, lvl-1});
        }
        if(curr->right){
            q.push({curr->right, lvl+1});
        }
    }
    vector<int> ans;
    for(int i = offset+minlvl;i<=offset+maxlvl;i++){
        ans.push_back(topV[i]);
    }
    return ans;
}
vector<int> bottom_view(treeNode* root){
    vector<int> topV(500, 0);
    queue<pair<treeNode*, int>> q;int minlvl = INT_MAX;int maxlvl = INT_MIN;
    q.push({root, 0});
    int offset = 250;
    while(!q.empty()){
        treeNode* curr = q.front().first;
        int lvl = q.front().second;
        q.pop();
        topV[offset+lvl] = curr->val;
        if(lvl<=minlvl) minlvl = lvl;
        if(lvl>=maxlvl) maxlvl = lvl;
        if(curr->left){
            q.push({curr->left, lvl-1});
        }
        if(curr->right){
            q.push({curr->right, lvl+1});
        }
    }
    vector<int> ans;
    for(int i = offset+minlvl;i<=offset+maxlvl;i++){
        ans.push_back(topV[i]);
    }
    return ans;
}
vector<int> right_view(treeNode* root){
    queue<pair<treeNode*, int>> q;
    vector<int> filled(500, 0);
    vector<int> rview;
    q.push({root, 0});
    while(!q.empty()){
        treeNode* curr = q.front().first;
        int lvl = q.front().second;
        q.pop();
        if(!filled[lvl]){
            filled[lvl] = 1;
            rview.push_back(curr->val);
        }
        if (curr->right) q.push({curr->right, lvl + 1});
        if (curr->left)  q.push({curr->left, lvl + 1});
    }
    return rview;
}
vector<int> left_view(treeNode* root){
    queue<pair<treeNode*, int>> q;
    vector<int> filled(500, 0);
    vector<int> lview;
    q.push({root, 0});
    while(!q.empty()){
        treeNode* curr = q.front().first;
        int lvl = q.front().second;
        q.pop();
        if(!filled[lvl]){
            filled[lvl] = 1;
            lview.push_back(curr->val);
        }
        if (curr->left)  q.push({curr->left, lvl + 1});
        if (curr->right) q.push({curr->right, lvl + 1});
    }
    return lview;
}
int maxwidth(treeNode *root){
    if (!root) return 0;
    int ans = 0;
    queue<pair<treeNode*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        int lvlsize = q.size();
        int dist = q.front().second;
        int last = 0;
        for(int i = 0;i<lvlsize;i++){
            treeNode* curr = q.front().first;
            int idx = q.front().second;
            q.pop();
            if(i==lvlsize-1) last = idx;
            if(curr->left) q.push({curr->left, 2*idx+1});
            if(curr->right) q.push({curr->right, 2*idx+2});
        }
        ans = max(ans, last - dist + 1);
    }
    return (int)ans;
}
int main(){
    return 0;
}
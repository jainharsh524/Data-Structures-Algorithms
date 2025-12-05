#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode{
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

void cildrenSumProp(struct treeNode* root){
    if(root==NULL){
        return;
    }
    int childSum = 0;
    if(root->left!=NULL) childSum = childSum+root->left->val;
    if(root->right!=NULL) childSum = childSum+root->right->val;

    if(childSum>root->val) root->val = childSum;
    else {
        if(root->left!=NULL) root->left->val = root->val;
        else if(root->right!=NULL) root->right->val = root->val;
    }
    cildrenSumProp(root->left);
    cildrenSumProp(root->right);
    int tot = 0;
    if(root->left!=NULL) tot = tot+root->left->val;
    if(root->right!=NULL) tot = tot+root->right->val;
    if(root->left!=NULL||root->right!=NULL) root->val = tot;
}

int main(){
    return 0;
}
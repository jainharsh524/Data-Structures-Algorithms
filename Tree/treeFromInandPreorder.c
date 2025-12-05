#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode{
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

struct treeNode* createNode(int val){
    struct treeNode* curr = (struct treeNode*)malloc(sizeof(struct treeNode));
    curr->val = val;
    curr->left = curr->right = NULL;
    return curr;
}

int search(int inorder[], int start, int end, int val){
    for(int i = start;i<=end;i++){
        if(inorder[i]==val) return i;
    }
    return -1;
}

struct treeNode* treeBuilder(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex){
    if(inStart>inEnd) return NULL;

    struct treeNode* root = createNode(preorder[(*preIndex)++]);
    if(inStart==inEnd) return root;

    int inIndex = search(inorder, inStart, inEnd, root->val);

    root->left = treeBuilder(preorder, inorder, inStart, inIndex-1, preIndex);
    root->right = treeBuilder(preorder, inorder, inIndex+1, inEnd, preIndex);
    return root;
}

struct TreeNode* buildTree(int preorder[], int inorder[], int n) {
    int preIndex = 0;
    return treeBuilder(preorder, inorder, 0, n - 1, &preIndex);
}

// Print Inorder to check correctness
void printInorder(struct treeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode* root = buildTree(preorder, inorder, n);

    printf("Inorder of constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode{
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

struct treeNode* newNode(int val) {
    struct treeNode* node = (struct treeNode*)malloc(sizeof(struct treeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct treeNode* LCA(struct treeNode* root, struct treeNode* a, struct treeNode* b){
    if(root==NULL||root==a||root==b) return root;

    struct treeNode* left = LCA(root->left, a, b);
    struct treeNode* right = LCA(root->right, a, b);
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    else{
        return root;
    }
}
int main(){
    // Manually creating a tree
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    struct treeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    int arr[100];
    int size = 0;
    int target = 6;

    if(getPath(root, arr, &size, target)) {
        printf("Path to %d: ", target);
        for(int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    } else {
        printf("Target %d not found in the tree.\n", target);
    }

    return 0;
}
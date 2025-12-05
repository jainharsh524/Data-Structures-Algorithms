#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode
{
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *createNode(int val)
{
    struct treeNode *curr = (struct treeNode *)malloc(sizeof(struct treeNode));
    curr->val = val;
    curr->left = curr->right = NULL;
    return curr;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct treeNode* buildTree(int postorder[], int inorder[], int inStart, int inEnd, int* postIndex)
{
    if(inStart>inEnd) return NULL;
    struct treeNode* root = createNode(postorder[(*postIndex)--]);

    if (inStart == inEnd) return root;
    int inIndex = search(inorder, inStart, inEnd, root->val);

    root->right = buildTree(postorder, inorder, inIndex+1, inEnd, postIndex);
    root->left = buildTree(postorder, inorder, inStart, inIndex-1, postIndex);

    return root;
}

void printInorder(struct treeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

int main() {
    int inorder[]   = {4, 2, 5, 1, 6, 3};
    int postorder[] = {4, 5, 2, 6, 3, 1};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = n - 1;

    struct treeNode* root = buildTree(postorder, inorder, 0, n - 1, &postIndex);

    printf("Inorder Traversal of constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}
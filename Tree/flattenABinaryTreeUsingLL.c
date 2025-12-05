#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

struct treeNode* createNode(int val) {
    struct treeNode* node = (struct treeNode*)malloc(sizeof(struct treeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct treeNode* prevNode = NULL;

void flatten(struct treeNode* root) {
    if (!root) return;
    flatten(root->right);
    flatten(root->left);
    root->right = prevNode; // and last processed node ko right me chipkaate jao
    root->left = NULL;
    prevNode = root; //jis node ki bhi processing khtm hui h wahi prev hoga

}

void printFlattened(struct treeNode* root) {
    while (root) {
        printf("%d ", root->val);
        root = root->right;
    }
}

int main() {
    struct treeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->right = createNode(6);

    flatten(root);

    printf("Flattened Tree: ");
    printFlattened(root);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(struct treeNode* node) {
    return (node == NULL) ? -1 : node->height;
}

struct treeNode* createNode(int val) {
    struct treeNode* curr = (struct treeNode*)malloc(sizeof(struct treeNode));
    curr->val = val;
    curr->left = NULL;
    curr->right = NULL;
    curr->height = 0;
    return curr;
}

struct treeNode* insertion(struct treeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (root->val < val) {
        root->right = insertion(root->right, val);
    } else if (root->val > val) {
        root->left = insertion(root->left, val);
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    return root;
}

bool search(struct treeNode* root, int val) {
    if (root == NULL) return false;
    if (val == root->val) return true;
    else if (val < root->val) return search(root->left, val);
    else return search(root->right, val);
}

int ceilValue(struct treeNode* root, int val) {
    int ceil = -1;
    while (root) {
        if (root->val == val) {
            return val;
        } else if (root->val < val) {
            root = root->right;
        } else {
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}

int floorValue(struct treeNode* root, int val) {
    int floor = -1;
    while (root) {
        if (root->val == val) {
            return val;
        } else if (root->val > val) {
            root = root->left;
        } else {
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}

struct treeNode* inorderpredessor(struct treeNode* root){
    struct treeNode* curr = root->left;
    while(curr!=NULL&&curr->right!=NULL){
        curr = curr->right;
    }
    return curr;
}

struct treeNode* deletion(struct treeNode* root, int key){
    if (root == NULL) return root;
    //find the key
    if(root->val<key){
        root->right = deletion(root->right, key);
    }
    else if(root->val>key){
        root->left = deletion(root->left, key);
    }
    else{
        //keyfound
        if(root->left==NULL){
            struct treeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct treeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct treeNode* pred = inorderpredessor(root);
        root->val = pred->val;
        //basically jis node se value swap ki h use bhi to del krna hoga
        // so we go in left subtree.
        root->left = deletion(root->left, pred->val);

    }
    return root;
}

void inorder(struct treeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

bool isValidBST(struct treeNode* root, int min_val, int max_val){
    if(root==NULL) return true;
    else if(root->val>=max_val||root->val<=min_val){
        return false;
    }
    return isValidBST(root->left, min_val, root->val)&&
    isValidBST(root->right, root->val, max_val);
}

struct treeNode* LCAInBST(struct treeNode* root, struct treeNode* p, struct treeNode* q){
    if(root==NULL){
        return NULL;
    }
    if(root->val<p->val&&root->val<q->val){
        return LCAInBST(root->right, p, q); //either u are going right for both node or left, so whenever
        // u have to split or u have to go to different direction for nodes then that will be the last common ansector
    }
    if(root->val>p->val&&root->val>q->val){
        return LCAInBST(root->left, p, q);
    }
    return root;
}

int main() {
    struct treeNode* root = NULL;
    root = insertion(root, 50);
    root = insertion(root, 30);
    root = insertion(root, 70);
    root = insertion(root, 20);
    root = insertion(root, 40);
    root = insertion(root, 60);
    root = insertion(root, 80);

    printf("Inorder before deletion: ");
    inorder(root);

    root = deletion(root, 50); // Delete root using inorder predecessor

    printf("\nInorder after deletion: ");
    inorder(root);

    return 0;
}

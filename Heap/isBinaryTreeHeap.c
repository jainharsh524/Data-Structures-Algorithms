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
    curr->left = NULL;
    curr->right = NULL;
    return curr;
}
int size(struct treeNode* root){
    if(root==NULL) return 0;
    return 1+size(root->left)+size(root->right);
}
struct treeNode* treeBuilder(int arr[], int size){
    if(arr[0]==-1||size==0) return NULL;
    int i = 0;
    struct treeNode* root = createNode(arr[i++]);
    struct treeNode* queue[1000];
    int rear = 0;int front = 0;
    queue[rear++] = root;
    while(front<rear){
        struct treeNode* temp = queue[front++];
        if(i<size&&arr[i]!=-1){
            temp->left = createNode(arr[i++]);
            queue[rear++] = temp->left;
        }
        if(i<size&&arr[i]!=-1){
            temp->right = createNode(arr[i++]);
            queue[rear++] = temp->right;
        }
    }
    return root;
}

bool isCBT(struct treeNode* root, int size, int index){
    if(root==NULL) return true;
    else if(index>=size) return false;
    else {
        bool left = isCBT(root->left, size, 2*index+1);
        bool right = isCBT(root->right, size, 2*index+2);
        return(left&&right);
    }
}

bool isMaxHeapOrder(struct treeNode* root){
    if(root->left==NULL&&root->right==NULL) return true;
    if(root->right==NULL){
        return root->val>root->left->val;
    }
    else{
        bool left = isMaxHeapOrder(root->left);
        bool right = isMaxHeapOrder(root->right);
        return left&&right&&(root->val>root->left->val&&root->val>root->right->val);
    }
}

bool isHeap(struct treeNode* root){
    int index = 0;
    int treeSize = size(root);
    return (isCBT(root, treeSize, index)&&isMaxHeapOrder(root));
}

int main() {
    int n;
    printf("Enter number of nodes (including -1 for NULLs): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter tree in level order (-1 for NULLs):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct treeNode* root = treeBuilder(arr, n);

    if (isHeap(root)) {
        printf("The given binary tree IS a Max Heap.\n");
    } else {
        printf("The given binary tree is NOT a Max Heap.\n");
    }

    return 0;
}

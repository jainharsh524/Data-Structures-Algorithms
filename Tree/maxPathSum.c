#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Node structure
struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
    int height;
};
struct treeNode* createNode(int val) {
    struct treeNode* curr = (struct treeNode*)malloc(sizeof(struct treeNode));
    curr->val = val;
    curr->height = 0;
    curr->left = NULL;
    curr->right = NULL;
    return curr;
}

// Get height
int height(struct treeNode* root) {
    if (root == NULL) return -1;
    return root->height;
}

struct treeNode* createTreeUsingLevelOrder(int arr[], int size){
    if(arr[0]==-1||size==0) return NULL;

    int i = 0;
    struct treeNode* root = createNode(arr[i++]);

    struct treeNode* queue[1000];
    int rear = 0;
    int front = 0;
    queue[rear++] = root;
    while(front<rear&&i<size){
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


int maxPathSum(struct treeNode* root, int *maxi){
    if (root == NULL) return 0;

    int left = max(0,maxPathSum(root->left, maxi));
    int right = max(0,maxPathSum(root->right, maxi));

    *maxi = max(*maxi, left + right + root->val); // update max path sum
    return max(left, right) + root->val;
}

// Main function
int main() {
    int nums[] = {20, 9, -10, -11, -15, 15, 7};
    int size = sizeof(nums) / sizeof(nums[0]);

    struct treeNode* root = createTreeUsingLevelOrder(nums, size);


    int maxi = 0;
    printf("Maximum Path Sum: ");
    printf("%d", maxPathSum(root, &maxi));
    printf("\n");

    return 0;
}

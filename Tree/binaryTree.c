#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct treeNode{
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct treeNode* createNode(int val){
    struct treeNode* curr = (struct treeNode*) malloc(sizeof(struct treeNode));
    curr->val = val;
    curr->right = NULL;
    curr->left = NULL;
    return curr;
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

void zigzag(struct treeNode* root, bool flag){
    struct treeNode* queue[1000];
    int rear = 0;
    int front = 0;
    queue[rear++] = root;
    int arr[100][100];int index =0;
    int returnsize[100];
    while(front<rear){
        int levelsize = rear-front;
        returnsize[index] = levelsize;
        for(int i = 0;i<levelsize;i++){
            struct treeNode* curr = queue[front++];
            int idx = (flag) ? (levelsize - i - 1) : i;
            arr[index][idx] = curr->val;
            if(curr->left) queue[rear++] = curr->left;
            if(curr->right) queue[rear++] = curr->right;
        }
        index++;
        flag = !flag;
    }
    for(int i = 0;i<index;i++){
        for(int j = 0;j<returnsize[i];j++){
            printf("%d ", arr[i][j]);
        }
    }
}

void inorder(struct treeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int maxPathSum(struct treeNode* root, int *maxi){
    if (root == NULL) return 0;


    int left = max(0, maxPathSum(root->left, maxi));
    int right = max(0, maxPathSum(root->right, maxi));


    *maxi = max(*maxi, left + right + root->val); // update max path sum
    return max(left, right) + root->val;
}

int main(){
    int size;
    scanf("%d", &size);
    int arr[size];
    char temp;
    for(int i = 0;i<size;i++){
        scanf("%d", &arr[i]);
        scanf("%c", &temp);
    }
    struct treeNode* root = createTreeUsingLevelOrder(arr, size);
    // printf("Inorder: ");
    // inorder(root);
    int maxi = INT_MIN;
    printf("Maximum Path Sum: ");
    printf("%d", maxPathSum(root, &maxi));
    printf("\n");
}
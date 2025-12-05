#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode{
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

struct queueNode{
    struct treeNode* n;
    int level;
};

int* rightView(struct treeNode* root, int * returnsize){
    if(root==NULL){
        *returnsize = 0;
        return NULL;
    }
    int* rightArray = malloc(1000*sizeof(int));
    int filled[1000] = {0};
    int size = 0;
    struct queueNode queue[1000];
    int rear = 0;
    int front = 0;

    queue[rear++] = (struct queueNode){root, 0};
    while(front<rear){
        struct queueNode temp = queue[front++];
        struct treeNode* n = temp.n;
        if(!filled[temp.level]){
            filled[temp.level] = 1;
            rightArray[size++] = n->val;
        }

        if(n->right){
            queue[rear++] = (struct queueNode){n->right, temp.level+1};
        }
        if(n->left){
            queue[rear++] = (struct queueNode){n->left, temp.level+1};
        }
    }
    *returnsize = size;
    return rightArray;
}

int main(){
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode{
    int val;
    struct treeNode* left;
    struct treeNode* right;
    int height;
};

struct queueNode{
    struct treeNode* n;
    int level;
};

int* leftView(struct treeNode* root, int* returnsize){
    if(root==NULL){
        *returnsize = 0;
        return NULL;
    }
    int* leftArray = malloc(1000*sizeof(int));
    int filled[1000] = {0};
    int size = 0;

    struct queueNode queue[1000];
    int front = 0;
    int rear = 0;

    struct queueNode temp;
    temp.n = root;
    temp.level = 0;

    queue[rear++] = temp;
    while(rear<front){
        struct queueNode curr = queue[front++];
        struct treeNode* n = curr.n;
        if(!filled[curr.level]){
            filled[curr.level] = 1;
            leftArray[size++] = n->val;
        }

        if(n->left){
            queue[rear++] = (struct queueNode){n->left, curr.level+1};
        }
        if(n->right){
            queue[rear++] = (struct queueNode){n->right, curr.level+1};
        }
    }
    *returnsize = size;
    return leftArray;
}

int main(){
    return 0;
}
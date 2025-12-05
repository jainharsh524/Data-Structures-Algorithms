#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
    int height;
};

// Queue Node
struct queueNode {
    struct treeNode* n;
    int horizon_dis;
};

int* topView(struct treeNode* root, int* returnsize){
    if(root==NULL){
        *returnsize = 0;
        return NULL;
    }

    //basically hum log ek array le rhe hn in which each element is having 2 things one is node and other one is its horizontal distance.
    struct queueNode queue[1000];
    int front = 0;
    int rear = 0;

    int map[1001];
    int filled[1001] = {0};
    int offset = 500;
    int minHd = INT_MAX, maxHd = INT_MIN;
    struct queueNode temp;
    temp.n = root;
    temp.horizon_dis = 0;
    queue[rear++] = temp;

    while(front<rear){
        temp = queue[front++];
        struct treeNode* n = temp.n;
        int hd = temp.horizon_dis;

        if (!filled[hd + offset]) {
            filled[hd + offset] = 1;
            map[hd + offset] = n->val;
            if (hd < minHd) minHd = hd;
            if (hd > maxHd) maxHd = hd;
        }

        if(n->left){
            struct queueNode temp1;
            temp1.n = n->left;
            temp1.horizon_dis = hd-1;
            queue[rear++] = temp1;
        }
        if(n->right){
            struct queueNode temp1;
            temp1.n = n->right;
            temp1.horizon_dis = hd+1;
            queue[rear++] = temp1;
        }
    }
    int size = maxHd - minHd + 1;
    int* result = malloc(size * sizeof(int));
    *returnsize = size;
    for (int i = 0; i < size; i++) {
        result[i] = map[minHd + i + offset];
    }
    return result;
}
int main(){
    return 0;
}
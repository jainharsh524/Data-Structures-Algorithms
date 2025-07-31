/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* st) {
    st->top = -1;
}

void push(Stack* st, int val) {
    if (st->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    st->data[++(st->top)] = val;
}

int pop(Stack* st) {
    if (st->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return st->data[(st->top)--];
}

int isEmpty(Stack* st) {
    return st->top == -1;
}

int peek(Stack* st) {
    if (st->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return st->data[st->top];
}

void recHelper(int* nums, int numsize, int** res, int* returnSize, int** returnColumnSizes, Stack* temp, bool arr[]){
    if(temp->top+1==numsize){
        res[*returnSize] = malloc(numsize*sizeof(int));
        for(int i = 0;i<numsize;i++){
            res[*returnSize][i] = temp->data[i];
        }
        (*returnColumnSizes)[*returnSize] = numsize;
        (*returnSize)++;
        return;
    }
    for(int i = 0;i<numsize;i++){
        if(!arr[i]){
            arr[i] = true;
            push(temp, nums[i]);
            recHelper(nums, numsize, res, returnSize, returnColumnSizes, temp, arr);
            pop(temp);
            arr[i] = false;
        }
    }
}
int fact(int n){
    int mul = 1;
    for(int i = n; i>0;i--){
        mul*=i;
    }
    return mul;
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = fact(numsSize);
    int** res = malloc(total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));
    *returnSize = 0;
    bool arr[numsSize];
    for (int i = 0; i < numsSize; i++) arr[i] = false;
    Stack temp;
    initStack(&temp);
    recHelper(nums, numsSize, res, returnSize, returnColumnSizes, &temp, arr);
    return res;
}


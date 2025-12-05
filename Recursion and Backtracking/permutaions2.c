#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

int compare(const void*a, const void*b){
    return(*(int*)a-*(int*)b);
}

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
            if (i > 0 && nums[i] == nums[i - 1] && !arr[i - 1]) continue;

            else{
                arr[i] = true;
                push(temp, nums[i]);
                recHelper(nums, numsize, res, returnSize, returnColumnSizes, temp, arr);
                pop(temp);
                arr[i] = false;
            }
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
    qsort(nums, numsSize, sizeof(int), compare);
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


int main() {
    int nums[] = {1, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int* returnColumnSizes;
    int returnSize;

    int** result = permute(nums, numsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("{ ");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("}\n");
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);
    return 0;
}

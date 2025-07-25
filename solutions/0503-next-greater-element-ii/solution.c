/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int* stack = (int*)malloc(sizeof(int) * numsSize);
    int top = -1;

    for (int i = 2 * numsSize - 1; i >= 0; i--) {
        int curr = nums[i % numsSize];

        while (top >= 0 && stack[top] <= curr) {
            top--;
        }

        if (i < numsSize) {
            res[i] = (top == -1) ? -1 : stack[top];
        }

        stack[++top] = curr; // Push current number
    }

    *returnSize = numsSize;
    return res;
}

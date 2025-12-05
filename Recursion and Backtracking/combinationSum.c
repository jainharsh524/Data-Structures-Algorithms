#include <stdio.h>
#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target,
               int** result, int* returnSize, int** returnColumnSizes,
               int* temp, int tempSize, int start) {
    
    if (target == 0) {
        result[*returnSize] = malloc(tempSize * sizeof(int));
        for (int i = 0; i < tempSize; i++) {
            result[*returnSize][i] = temp[i];
        }
        (*returnColumnSizes)[*returnSize] = tempSize;
        (*returnSize)++;
        return;
    }

    if(start>=candidatesSize||target<0) return;
    temp[tempSize] = candidates[start];
    backtrack(candidates, candidatesSize, target-candidates[start], 
            result, returnSize, returnColumnSizes, 
        temp, tempSize+1, start);
     backtrack(candidates, candidatesSize, target, 
            result, returnSize, returnColumnSizes, 
        temp, tempSize, start+1);
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {
    
    int** result = malloc(1000 * sizeof(int*));
    *returnColumnSizes = malloc(1000 * sizeof(int));
    int* temp = malloc(1000 * sizeof(int));
    *returnSize = 0;
    
    backtrack(candidates, candidatesSize, target, result, returnSize,
              returnColumnSizes, temp, 0, 0);
    
    free(temp);
    return result;
}

int main() {
    int arr[] = {2, 3, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    
    int returnSize;
    int* returnColumnSizes;
    
    int** result = combinationSum(arr, size, target, &returnSize, &returnColumnSizes);
    
    printf("Combinations:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Backtracking function
void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* temp, int tempSize,
               int** result, int* returnSize, int** returnColumnSizes) {
    
    if (target == 0) {
        (result)[*returnSize] = malloc(tempSize * sizeof(int));
        for (int i = 0; i < tempSize; i++) {
            (result)[*returnSize][i] = temp[i];
        }
        (*returnColumnSizes)[*returnSize] = tempSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        // Skip duplicates
        if (i > start && candidates[i] == candidates[i - 1]) continue;

        if (candidates[i] > target) break; // Prune if value too big

        temp[tempSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i + 1,
                  temp, tempSize + 1, result, returnSize, returnColumnSizes);
    }
}

// Main function
int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes) {
    
    qsort(candidates, candidatesSize, sizeof(int), compare);  // Sort input
    
    int resultCapacity = 100;
    int** result = malloc(resultCapacity * sizeof(int*));
    *returnColumnSizes = malloc(resultCapacity * sizeof(int));
    int* temp = malloc(candidatesSize * sizeof(int));
    *returnSize = 0;

    backtrack(candidates, candidatesSize, target, 0, temp, 0,
              result, returnSize, returnColumnSizes);

    free(temp);
    return result;
}

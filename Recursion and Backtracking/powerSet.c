#include <stdio.h>
#include <stdlib.h>

void recHelper(int arr[], int size, int** res, int* resSize, int* colSizes, int* temp, int tempIndex, int currIndex){
    // Save the current subset
    res[*resSize] = malloc(tempIndex * sizeof(int));
    for(int i = 0; i < tempIndex; i++) {
        res[*resSize][i] = temp[i];
    }
    colSizes[*resSize] = tempIndex;
    (*resSize)++;

    for(int i = currIndex; i < size; i++){
        temp[tempIndex] = arr[i];
        recHelper(arr, size, res, resSize, colSizes, temp, tempIndex + 1, i + 1);
    }
}

int** powerSet(int arr[], int size, int* returnSize, int** returnColumnSizes){
    int len = 1 << size; // 2^n subsets
    int** res = malloc(len * sizeof(int*));
    int* colSizes = malloc(len * sizeof(int));
    int* temp = malloc(size * sizeof(int));
    *returnSize = 0;

    recHelper(arr, size, res, returnSize, colSizes, temp, 0, 0);

    *returnColumnSizes = colSizes;
    free(temp);
    return res;
}

int main(){
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int resSize;
    int* colSizes;
    int** subsets = powerSet(arr, size, &resSize, &colSizes);

    printf("All subsets:\n");
    for (int i = 0; i < resSize; i++) {
        printf("{ ");
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d, ", subsets[i][j]);
        }
        printf("}\n");
        free(subsets[i]);
    }

    free(subsets);
    free(colSizes);
    return 0;
}

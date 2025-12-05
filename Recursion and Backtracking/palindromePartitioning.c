#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void backtrack(char* s, int start, char*** result, int* returnSize,
               char** currentList, int currentSize, int** returnColumnSizes) {
    // base case jaha par result me palindrome combinations ko add kiya h
    if(s[start]=='\0'){
        result[*returnSize] = malloc(currentSize*sizeof(char*));
        for(int i = 0;i<currentSize;i++){
            result[*returnSize][i] = strdup(currentList[i]);
        }
        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;
        return; //always use return statement at the base conition
    }
    int size = strlen(s);
    for(int i = start;i<size;i++){
        if(isPalindrome(s, start, i)){
            int len = i - start + 1;
            char *substr = malloc((len + 1) * sizeof(char));
            strncpy(substr, s + start, len);
            substr[len] = '\0';

            currentList[currentSize] = strdup(substr);
            //currentList[currentSize] = malloc((len + 1) * sizeof(char));

            backtrack(s, i+1, result, returnSize, 
            currentList, currentSize+1, returnColumnSizes);

             free(currentList[currentSize]);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    char*** res = malloc(1000*sizeof(char**));
    *returnColumnSizes = malloc(1000*sizeof(int));
    *returnSize = 0;
    char** currentList = malloc(strlen(s) * sizeof(char*));
    backtrack(s, 0, res, returnSize, currentList, 0, returnColumnSizes);
    return res;
}

int main() {
    char input[100];
    printf("Enter string: ");
    scanf("%s", input);

    int returnSize;
    int* returnColumnSizes;
    char*** result = partition(input, &returnSize, &returnColumnSizes);

    printf("Palindrome Partitions:\n");
    printf("%d", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("{ ");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("\"%s\" ", result[i][j]);
            free(result[i][j]);
        }
        printf("}\n");
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}
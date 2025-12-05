#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void recHelper(int arr[], int size, int targetSum, int currSum, int suffixArray[], int currindex, int*res, int* resIndex){
    if(targetSum==currSum){
        
        return;
    }
    else if(currindex>=size||suffixArray[currindex]<targetSum-currSum){
        return;
    }
    res[*resIndex] = arr[currindex];
    recHelper(arr, size, targetSum, currSum+arr[currindex],suffixArray,currindex+1, res, resIndex+1);
    recHelper(arr, size, targetSum, currSum,suffixArray,currindex+1, res, resIndex);
}
int* subsetSum(int arr[], int size, int targetSum, int suffixArray[]){
    int* res = malloc(size*sizeof(int));
    int* resIndex = 0;
    recHelper(arr, size, targetSum,0, suffixArray, 0, res, resIndex);
    int sum = 0;
    for(int i =0;i<resIndex;i++){
        sum = sum+res[i];
    }
    if(sum==targetSum){
        return res;
    }
    else{
        return NULL;
    }
}

int main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i =0;i<size;i++){
        scanf("%d", &arr[i]);
    }
    int targetSum;
    scanf("%d", &targetSum);
    int suffixArray[size];
    suffixArray[size-1] = arr[size-1];
    for(int i = size-2;i>=0;i--){
        suffixArray[i] = arr[i]+suffixArray[i+1];
    }
    for(int i =0;i<size;i++){
        printf("%d ", suffixArray[i]);
    }
    return 0;
}
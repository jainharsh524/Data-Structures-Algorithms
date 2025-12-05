#include <stdio.h>
#include <stdbool.h>
int BS(int* arr, int target, int l, int h){
    if(l>h) return -1;
    int mid = l+(h-l)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if (arr[mid]>target){
        return BS(arr, target, l, mid-1);
    }
    else{
        return BS(arr, target, mid+1, h);
    }
}
bool subsetS(int len, int *arr, int targetSum, int index){
    if(targetSum==0){
        return true;
    }
    if (index >= len){
    return false;}
    else if(index<len&&arr[index]<=targetSum){
        if(subsetS(len, arr, targetSum-arr[index], index+1)){
            return true;
        }
    }
    else return subsetS(len, arr, targetSum, index+1);
}
bool subsetS2(int len, int *arr, int targetSum, int index){
    if(targetSum==0){
        return true;
    }
    if (index >= len){
    return false;}
    else if(index<len&&arr[index]<=targetSum){
        if(subsetS2(len, arr, targetSum-arr[index], index)||subsetS2(len, arr, targetSum, index+1)){
            return true;
        }
    }
    else return subsetS2(len, arr, targetSum, index+1);
}
void swap(int *arr, int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
int pivot(int *arr, int l, int h){
    int start = l;
    int i = l+1;
    int j = h;
    while(i<j){
        while(arr[i]<=arr[start]&&i <= h - 1){
            i++;
        }
        while(arr[j]>arr[start]&&j >= l + 1){
            j--;
        }
        if (i < j) swap(arr, i, j);
    }
    swap(arr, start, j);
    return j;
}
void quick(int *arr, int l, int h){
    if(l<h){
        int pi = pivot(arr, l, h);
        quick(arr, l, pi-1);
        quick(arr, pi+1, h);
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int res = BS(arr, 6, 0, -1);
    printf("%d", res);
    int arr[] = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;
    int len = sizeof(arr) / sizeof(arr[0]);

    if (subsetS(len, arr, targetSum, 0))
        printf("Subset with sum %d exists\n", targetSum);
    else
        printf("No subset with sum %d\n", targetSum);
    return 0;
}

#include <stdlib.h>
#include <stdio.h>

void twoWayMerge(int arr[], int l, int m, int r) {
    int i, j, k;
    int len1 = m - l + 1;
    int len2 = r - m;

    int *arr1 = (int *)malloc(len1 * sizeof(int));
    int *arr2 = (int *)malloc(len2 * sizeof(int));

    for (i = 0; i < len1; i++) {
        arr1[i] = arr[l + i];
    }
    for (j = 0; j < len2; j++) {
        arr2[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l; // Initial index of merged array

    while (i < len1 && j < len2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < len2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    free(arr1);
    free(arr2);
}

void mergeSort(int arr, int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    printf("Enter the elements of array: ");
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
}
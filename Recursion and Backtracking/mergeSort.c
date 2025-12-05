#include <stdio.h>
#include <stdlib.h>

void twoWayMerge(int arr[], int l, int m, int h){
    int* arr1 = (int*)malloc((m-l+1)*sizeof(int*));
    int* arr2 = (int*)malloc((h-m)*sizeof(int*));
    int* res = (int*)malloc((h-l+1)*sizeof(int*));
    int k =0;
    for (int i = l; i < m+1; i++)
    {
        arr1[k] = arr[i];
        k++; 
    }
    k = 0;
    for (int i = m+1; i < h+1; i++)
    {
        arr2[k] = arr[i];
        k++; 
    }
    int ptr1 = 0;
    int ptr2 = 0;
    k = 0;
    while(ptr1<m-l+1&&ptr2<h-m){
        if(arr1[ptr1]<arr2[ptr2]){
            res[k++] = arr1[ptr1++];
        }
        else{
            res[k++] = arr2[ptr2++];
        }
    }
    while(ptr1<m-l+1){
        res[k++] = arr1[ptr1++];
    }
    while(ptr2<h-m){
        res[k++] = arr2[ptr2++];
    }
    k = 0;
    for(int i = l;i<h+1;i++){
        arr[i] = res[k++];
    }
}

void mergeSort(int arr[], int l, int h){
    if(l<h){
        int m = l+(h-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, h);
        twoWayMerge(arr, l, m, h);
    }
}

int main(){
    int size;
    scanf("%d", &size);
    int arr[size];

    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    printf("Array before sort: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    mergeSort(arr, 0, size-1);
    printf("Array after sort: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
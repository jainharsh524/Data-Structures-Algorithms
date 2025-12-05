#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int l, int h, int target){
    if (l > h)
        return -1;

    int m = l + (h - l) / 2;

    if (arr[m] == target)
        return m;
    else if (arr[m] < target)
        return binarySearch(arr, m + 1, h, target);
    else
        return binarySearch(arr, l, m - 1, target);
}

int main(){
    int size;
    scanf("%d", &size);
    int arr[size];
    int target;

    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);}
    
    scanf("%d", &target);
    int index = binarySearch(arr, 0, size - 1, target);

    if (index == -1)
        printf("Element Not Found");
    else
        printf("Element found at index %d", index);

    return 0;
}

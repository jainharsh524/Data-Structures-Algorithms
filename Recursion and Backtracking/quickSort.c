#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int pivot(int arr[], int pi, int l, int h){
    int pivot_value = arr[l]; // Choosing the first element as pivot
    int i = l - 1;            // Pointer for left side
    int j = h + 1;           // Pointer for right side

    while (1) {
        // Find leftmost element greater than or equal to pivot_value
        do {
            i++;
        } while (arr[i] < pivot_value);

        // Find rightmost element smaller than or equal to pivot_value
        do {
            j--;
        } while (arr[j] > pivot_value);

        // If pointers cross, partitioning is complete
        if (i >= j) {
            return j; // Return the partition point
        }

        // Swap elements that are on the wrong side
        swap(arr, i, j);
    }
}
void quicksort(int arr[], int l, int h ){
    if(l<h){
        int pi = pivot(arr, l,l,h);
        quicksort(arr, l, pi-1);
        quicksort(arr, pi+1, h);
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
    quicksort(arr, 0, size-1);
    printf("Array after sort: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
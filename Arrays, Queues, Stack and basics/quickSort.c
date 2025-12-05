#include <stdio.h>
#include <stdlib.h> // For rand(), srand(), if using random pivot
#include <time.h>   // For time() in srand()

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function (Lomuto partition scheme)
// This function places the pivot element at its correct sorted position
// in the array and places all smaller elements to its left
// and all greater elements to its right.
// It uses the last element as the pivot.
// Returns the partitioning index.

// basically ye algo sirf arr[j] ko check krti h that if it is small or not
// if it is greater than assumed pivot element then ye correct pos pe h isko pivot element ke baad hi hona chahiye
// if it is less then swap with arr[i] - which is starting from low and after swapping i++.
// and at last pivot ko uski correct position tak pahuchane ke liye 
// swap(&arr[i+1], &arr[high])->swap(correct position, pivot element position)

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nOriginal array 2: \n");
    printArray(arr2, n2);

    quickSort(arr2, 0, n2 - 1);

    printf("Sorted array 2: \n");
    printArray(arr2, n2);
    //worst time complexity
    int arr_sorted[] = {1, 2, 3, 4, 5, 6, 7};
    int n_sorted = sizeof(arr_sorted) / sizeof(arr_sorted[0]);
    printf("\nOriginal sorted array (worst-case for simple pivot): \n");
    printArray(arr_sorted, n_sorted);
    quickSort(arr_sorted, 0, n_sorted - 1);
    printf("Sorted (still sorted): \n");
    printArray(arr_sorted, n_sorted);


    return 0;
}
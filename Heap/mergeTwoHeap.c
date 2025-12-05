#include <stdio.h>
#include <stdlib.h>

// Swap helper
void swap(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

// Heapify function (max-heap)
void heapify(int arr[], int size, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }
    if (rightChild < size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(arr, index, largest);
        heapify(arr, size, largest);
    }
}

// Function to merge two heaps
int* mergeHeaps(int arr1[], int arr2[], int size1, int size2, int* finalSize) {
    *finalSize = size1 + size2;
    int* merged = (int*)malloc((*finalSize) * sizeof(int));

    // Copy first heap
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    // Copy second heap
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }

    // Build max heap from merged array
    for (int i = (*finalSize) / 2 - 1; i >= 0; i--) {
        heapify(merged, *finalSize, i);
    }

    return merged;
}

int main() {
    int arr1[] = {50, 30, 40, 10, 5, 20, 30}; // Max-heap 1
    int arr2[] = {45, 35, 25, 15, 10};        // Max-heap 2
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int finalSize;

    int* mergedHeap = mergeHeaps(arr1, arr2, size1, size2, &finalSize);

    printf("Merged Max-Heap: ");
    for (int i = 0; i < finalSize; i++) {
        printf("%d ", mergedHeap[i]);
    }
    printf("\n");

    free(mergedHeap);
    return 0;
}

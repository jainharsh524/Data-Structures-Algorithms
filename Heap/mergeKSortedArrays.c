#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int val;
    int arrIndex;
    int eleIndex;
} Heap;

void swap(Heap* a, Heap* b) {
    Heap temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Heap arr[], int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && arr[parent].val > arr[i].val) {
        swap(&arr[i], &arr[parent]);
        heapifyUp(arr, parent);
    }
}

void heapifyDown(Heap arr[], int size, int i) {
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < size && arr[leftChild].val < arr[smallest].val) {
        smallest = leftChild;
    }
    if (rightChild < size && arr[rightChild].val < arr[smallest].val) {
        smallest = rightChild;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapifyDown(arr, size, smallest);
    }
}

void insertion(Heap arr[], int *size, Heap val) {
    arr[*size] = val;
    heapifyUp(arr, *size);
    (*size)++;
}

Heap extractMin(Heap arr[], int* size) {
    Heap root = arr[0];
    arr[0] = arr[--(*size)];
    heapifyDown(arr, *size, 0);
    return root;
}

void mergeKSortedArrays(int arr[][4], int k, int n) {
    Heap heap[k];
    int size = 0;

    for (int i = 0; i < k; i++) {
        Heap node = {arr[i][0], i, 0};
        heap[size++] = node;
    }

    // Build heap
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapifyDown(heap, size, i);

    while (size > 0) {
        Heap root = extractMin(heap, &size);
        printf("%d ", root.val);

        if (root.eleIndex + 1 < n) {
            Heap nextNode = {arr[root.arrIndex][root.eleIndex + 1], root.arrIndex, root.eleIndex + 1};
            insertion(heap, &size, nextNode);
        }
    }
}

int main() {
    int arr[3][4] = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };
    int k = 3, n = 4;
    mergeKSortedArrays(arr, k, n);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[1000];
    int size;
} Heap;

void swap(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void heapifyUp(Heap* hp, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && hp->data[parent] > hp->data[index]) {
        swap(hp->data, parent, index);
        heapifyUp(hp, parent);
    }
}

void heapifyDown(Heap* hp, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < hp->size && hp->data[leftChild] < hp->data[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < hp->size && hp->data[rightChild] < hp->data[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(hp->data, index, smallest);
        heapifyDown(hp, smallest);
    }
}

void insertHeap(Heap* hp, int val) {
    hp->data[hp->size] = val;
    heapifyUp(hp, hp->size);
    hp->size++;
}

int extractRoot(Heap* hp) {
    if (hp->size <= 0) return -1;
    int val = hp->data[0];
    hp->data[0] = hp->data[hp->size - 1];
    hp->size--;
    heapifyDown(hp, 0);
    return val;
}

int merge(Heap* hp) {
    if (hp->size == 1) return hp->data[0];
    int a = extractRoot(hp);
    int b = extractRoot(hp);
    int sum = a + b;
    insertHeap(hp, sum);
    return merge(hp);
}

int main() {
    Heap hp = {.size = 0};
    insertHeap(&hp, 4);
    insertHeap(&hp, 3);
    insertHeap(&hp, 2);
    insertHeap(&hp, 6);

    int cost = merge(&hp);
    printf("Final merged cost: %d\n", cost);

    return 0;
}

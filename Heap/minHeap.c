#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int arr[1000];
    int size;
}Heap;

void swap(int arr[], int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int compare(int a, int b){
    return a<b;
}

Heap heapifyUp(Heap hp, int index){
    int parent = (index-1)/2;
    if(index>0&&compare(hp.arr[index], hp.arr[parent])){
        swap(hp.arr, index, parent);
        hp = heapifyUp(hp, parent);
    }
    return hp;
}

Heap heapifyDown(Heap hp, int index){
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;
    int parent = index;

    if(leftChild<hp.size&&compare(hp.arr[leftChild], hp.arr[parent])){
        parent = leftChild;
    }
    if(rightChild<hp.size&&compare(hp.arr[rightChild], hp.arr[parent])){
        parent = rightChild;
    }

    if(parent!=index){
        swap(hp.arr, parent, index);
        hp = heapifyDown(hp, parent);
    }
    return hp;
}

Heap insertHeap(Heap hp, int val){
    hp.arr[hp.size] = val;
    hp = heapifyUp(hp, hp.size);
    hp.size++;
    return hp;
}

int extractRoot(Heap* hp){
    if(hp->size<=0){
        printf("Heap is empty!\n");
        return -1;
    }
    int root = hp->arr[0];
    hp->arr[0] = hp->arr[hp->size-1];
    hp->size--;
    *hp = heapifyDown(*hp, 0);
    return root;
}

void printHeap(Heap hp) {
    for (int i = 0; i < hp.size; i++) {
        printf("%d ", hp.arr[i]);
    }
    printf("\n");
}

int main(){
    int size;
    scanf("%d", &size);
    int temp;
    char extra;
    Heap hp;
    hp.size = 0;
    for(int i = 0;i<size;i++){
        scanf("%d", &temp);
        scanf("%c", &extra);
        hp = insertHeap(hp, temp);
    }
    printf("Heap: ");
    printHeap(hp);
    printf("\n");
    // printf("Extracted root: %d\n", extractRoot(&hp));
    // printf("Heap after extraction: ");
    // printHeap(hp);

    int arr[size];
    for(int i = 0;i<size;i++){
        int a = extractRoot(&hp);
        arr[i] = a;
    }
    printf("Sorted array after heap sort: ");
    for(int i = 0;i<size;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
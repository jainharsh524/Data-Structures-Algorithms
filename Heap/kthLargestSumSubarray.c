#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data[1000];
    int size;
} Heap;

void swap(int arr[], int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void heapifyUp(Heap* hp, int index){
    int parent = (index-1)/2;
    if(index>0&&hp->data[parent]>hp->data[index]){
        swap(hp->data, parent, index);
        heapifyUp(hp, parent);
    }
}
void heapifyDown(Heap* hp, int index){
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

void insertion(Heap* hp, int val){
    hp->data[hp->size] = val;
    heapifyUp(hp, hp->size);
    hp->size++;
}

int extractRoot(Heap* hp){
    if (hp->size <= 0) return -1;
    int root = hp->data[0];
    hp->data[0] = hp->data[hp->size-1];
    hp->size--;
    heapifyDown(hp, 0);
    return root;
}

long long kthLargestSubsetSum(int arr[], int size, int k){
    Heap* hp = (Heap*)malloc(sizeof(Heap));
    hp->size = 0;
    for(int i = 0;i<size;i++){
        int sum = 0;
        for(int j = i;j<size;j++){
            sum+=arr[j];
            if(hp->size<k){
                insertion(hp, sum);
            }
            else{
                if(hp->data[0]<sum){
                    extractRoot(hp);
                    insertion(hp, sum);
                }
            }
        }
    }
    return hp->data[0];
}
int main(){
    int arr[] = {4, 3, 2, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    long long res = kthLargestSubsetSum(arr, n, 2);
    printf("%lld", res);
    return 0;
}
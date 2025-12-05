#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_limit 100

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;  // ✅ Important!
    return newNode;
}
struct Node* initiate(int val){
    struct Node* top = createNode(val);
    return top;
}

struct Node* push(struct Node* top, int val){
    struct Node* curr = createNode(val);
    curr->next = top;
    top = curr;
    return top;
}
struct Node* pop(struct Node* top){
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return NULL;
    }
    struct Node* temp = top;
    top = top->next;
    int popped = temp->data;
    free(temp);  // ✅ Free the node that was popped
    printf("Popped Value: %d\n", popped);
    return top;
}

char peek(struct Node* top){
    return top->data;
}

bool isEmpty(struct Node* top){
    int ch = peek(top);
    return ch==-1;
}

void printStack(struct Node* top) {
    struct Node* curr = top;
    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}
int size(struct Node* top){
    struct Node* curr = top;
    int count = 0;
    while (curr != NULL) {
        curr = curr->next;
        count++;
    }
    return count;
}

//Hashmap in C

#define MAX_MAP_SIZE 1000
struct MapEntry {
    int key;
    int value;
};

struct Map {
    struct MapEntry entries[MAX_MAP_SIZE];
    int size;
};

void put(struct Map* map, int key, int value) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            map->entries[i].value = value;
            return;
        }
    }

    if (map->size < MAX_MAP_SIZE) {
        map->entries[map->size].key = key;
        map->entries[map->size].value = value;
        map->size++;
    } else {
        printf("Map is full!\n");
    }
}

int get(struct Map* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return map->entries[i].value;
        }
    }
    return -1;
}

int contains(struct Map* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return 1;
        }
    }
    return 0;
}

//4. https://leetcode.com/problems/next-greater-element-ii/
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int* stack = (int*)malloc(sizeof(int) * numsSize);
    int top = -1;

    for (int i = 2 * numsSize - 1; i >= 0; i--) {
        int curr = nums[i % numsSize];

        while (top >= 0 && stack[top] <= curr) {
            top--;
        }

        if (i < numsSize) {
            res[i] = (top == -1) ? -1 : stack[top];
        }

        stack[++top] = curr; // Push current number
    }

    *returnSize = numsSize;
    return res;
}

int main() {
    //1. https://leetcode.com/problems/valid-parentheses/
    // struct Node* top = initiate('x');
    // char ch;
    // printf("Enter numbers (enter 0 to stop):\n");
    // printf("Enter the string: ");
    // do {
    //     scanf("%c", &ch);
    //     if(ch=='('|| ch=='['||ch=='{'){
    //         top = push(top, ch);
    //     }
    //     else if(ch==')'){
    //         if(peek(top)=='('){
    //             top = pop(top);
    //         }
    //     }
    //     else if(ch==']'){
    //         if(peek(top)=='['){
    //             top = pop(top);
    //         }
    //     }
    //     else if(ch=='}'){
    //         if(peek(top)=='{'){
    //             top = pop(top);
    //         }
    //     }
    // } while (ch!='0');
    // printf("Input taken.\n");
    // if(isEmpty(top)){
    //     printf("Yes, Parentheses string is valid.");
    // }
    // else printf("No, Parentheses string is invalid.");

    //2.https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
    //sol. https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/solutions/7001361/easy-solution-in-c-using-stack-concepts-hbe3t/
    // int count = 0;
    // struct Node* top = initiate('x');
    // char ch;
    // printf("Enter numbers (enter 0 to stop):\n");
    // printf("Enter the string: ");
    // do {
    //     scanf("%c", &ch);
    //     if(ch=='('){
    //         top = push(top, ch);
    //     }
    //     else if(isEmpty(top)&&ch==')'){
    //         count++;
    //     }

    // } while (ch!='0');
    // printf("Input taken.\n");
    // printf("Minimum Add to Make Parentheses Valid: %d", size(top)-1);

    //3.https://leetcode.com/problems/next-greater-element-i/description/
    //sol. https://leetcode.com/problems/next-greater-element-i/solutions/7002276/easy-length-c-solution-using-stack-and-m-zjr2/
    int size1, size2;
    printf("Enter the sizes for both the arrays: ");
    scanf("%d %d", &size1, &size2);
    int arr1[size1];
    int arr2[size2];
    struct Node* top = initiate(-1);
    struct Map myMap;
    myMap.size = size2;
    printf("Enter the elements for both the arrays: ");

    for(int i = 0;i<size1;i++){
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < size2; i++) {
    scanf("%d", &arr2[i]);

        while (!isEmpty(top) && peek(top) < arr2[i]) {
            put(&myMap, peek(top), arr2[i]);
            top = pop(top);
        }
        top = push(top, arr2[i]);
    }
    while (!isEmpty(top)) {
        put(&myMap, peek(top), -1);
        top = pop(top);
    }

    int res[size1];
    for (int i = 0; i < size1; i++)
    {
        res[i] = get(&myMap, arr1[i]);
    }
    for (int i = 0; i < size1; i++)
    {
        printf("%d ", res[i]);
    }
    
    return 0;
}
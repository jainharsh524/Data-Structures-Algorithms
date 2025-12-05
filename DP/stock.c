#include <stdio.h>

int max(int a, int b){
    return (a>b)?a:b;
}

int min(int a, int b){
    return (a<b)?a:b;
}
int profit(int arr[], int size){
    int maxProfit = 0;
    int mini = arr[0];
    for(int i = 0;i<size;i++){
        int pro = arr[i]-mini;
        maxProfit = max(maxProfit, pro);
        mini = min(mini, arr[i]);
    }
}
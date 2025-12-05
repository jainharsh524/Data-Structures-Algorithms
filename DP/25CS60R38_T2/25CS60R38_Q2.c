#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int count(int size, int i, int arr[size], int pro, int c){
    int took = 0;
    int left = 0;
    if(i<0||pro<1) {
        int temp = c;
        c = 0;
        return temp;
    }
    if(i>=0&&arr[i]!=0){
        if(pro>=1){
            took = count(size, i-1, arr, pro/arr[i], c);
            c++;
        }
        left = count(size, i-1, arr, pro, c);
    }
    return left;
}
int main(){
    int size;
    scanf("%d ", &size);
    int test[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &test[i]);
    }
    int pro;
    scanf("%d", &pro);
    int ans = count(size, size-1,test, pro, 0);
    printf("%d", ans);
    return 0; 
}
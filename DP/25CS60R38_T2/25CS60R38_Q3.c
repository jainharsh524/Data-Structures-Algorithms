#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int max(int a, int b){
    return (a<b)?b:a;
}
int LCS(int size,int i, int j, char arr1[size], char arr2[size], int dp[size][size]){
    if(i==-1||j==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(arr1[i]==arr2[j]) {
        return dp[i][j] = 1+LCS(size, i-1, j-1, arr1, arr2, dp);
    }
    else {
        return dp[i][j] = max(LCS(size, i-1, j, arr1, arr2, dp), LCS(size, i, j-1, arr1, arr2, dp));
    }
}

int main(){
    int size1;
    scanf("%d", &size1);
    char *arr1 = (char *)malloc((size1+1)*sizeof(char));
    char *arr2 = (char *)malloc((size1+1)*sizeof(char));
    char temp;
    scanf("%c", &temp);
    for(int i =0;i<size1;i++){
        scanf("%c", &arr1[i]);
        scanf("%c", &temp);
    }
    arr1[size1] = '\0';
    for(int i =0;i<size1;i++){
        arr2[i] = arr1[size1-i-1];
    }
    arr2[size1] = '\0';
    // for(int i =0;i<size1;i++){
    //     printf("%c ", arr2[i]);
    // }
    int dp[size1][size1];
    for(int i = 0;i<size1;i++){
        for(int j = 0;j<size1;j++){
            dp[i][j] = -1;
        }
    }
    int pal = LCS(size1, size1-1, size1-1, arr1, arr2, dp);
    printf("%d", size1-pal);
}
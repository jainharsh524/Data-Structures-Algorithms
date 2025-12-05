#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool issafe(int size, char test[][12], int r, int c){
    for(int i = r;i>=0;i--){
        if(test[i][c]=='Q'){return false;}
    }
    int i =r;
    int j =c;
    while(i>=0&&j>=0){
        if(test[i][j]=='Q'){return false;}
        i--; j--;
    }
    i = r;
    j = c;
    while(i>=0&&j<size){
        if(test[i][j]=='Q'){return false;}
        i--;j++;
    }
    return true;
}

bool NQueensexists(int size, char test[][12], int r, int* count){
    if(r==size){
        (*count) = (*count)+1;
        return false;
    }
    for(int i = 0;i<size;i++){
        if(issafe(size, test, r, i)){
            test[r][i] = 'Q';
            if(NQueensexists(size, test, r+1, count)){return true;}
            test[r][i] = '.';
        }
    }
    return false;
}

int main(){
    int size;
    scanf("%d", &size);
    char test[12][12];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for(int j=0;j<size;j++){
             test[i][j] = '.';
        }
    }
    NQueensexists(size, test, 0, &count);
    printf("%d", count);
    return 0; 
}
#include<stdio.h>
#include<stdbool.h>

int maxCal(int a, int b){
    return (a>b) ? a: b; // if we have to use return statements in the ternary operator then use it outside.
}
int ninja(int last, int day, int n, int arr[n][3], int dp[n][4]){
    if(day==0){ 
        int maximum = 0;
        for (int i = 0; i < 3; i++)
        {
            if(i!=last&&arr[day][i]>maximum){
                maximum = arr[day][i];
            }
        }
        
        return maximum;
    }

    if(dp[day][last]!=-1) return dp[day][last];

    int maximum = 0;
    for (int i = 0; i < 3; i++)
    {
        if(i!=last){
            int points = arr[day][i]+ninja(i, day-1, n, arr, dp);
            maximum = maxCal(maximum, points);
        }
    }
    return dp[day][last] = maximum;

}

int main(){

    return 0;
}
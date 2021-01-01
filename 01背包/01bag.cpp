#include<stdio.h>
#define MAX_NUM 5
#define max(a,b) ( ((a)>(b)) ? (a):(b) )

//int weight[MAX_NUM];
//int value[MAX_NUM];
int maxCapacity;

void init(){
    maxCapacity=10;
}
void solution(){
    init();
    int weight[MAX_NUM]={2,2,6,5,4};
    int value[MAX_NUM]={6,3,5,4,6};
    int dp[MAX_NUM+1][maxCapacity+1];
    for(int i=0;i<MAX_NUM;i++)
        for(int j=0;j<=maxCapacity;j++)
            dp[i][j]=0;
    for(int i=1;i<=MAX_NUM;i++){
        for(int j=1;j<=maxCapacity;j++){
            if(weight[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1]);
            }
        }
    }
    for(int i=1;i<=MAX_NUM;i++){
        for(int j=1;j<=maxCapacity;j++){
            printf("%2d ",dp[i][j]);
        }
        printf("\n");
    }
}
int main(){
    solution();
}
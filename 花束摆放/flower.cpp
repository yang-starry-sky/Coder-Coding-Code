#include<iostream>
#define max(a,b) ( ((a)>(b)) ? (a):(b) )
using namespace std;
void solution(){
    int fNum=3;
    int vNum=5;
    int value[3][5]={7,23,-5,-24,16,
                     5,21,-4,10,23,
                    -21,5,-4,-20,20};
    int dp[3][5];
    int len=vNum-fNum;
    for(int i=0;i<fNum;i++)
        for(int j=0;j<vNum;j++)
            dp[i][j] =0;
        
    for(int i=0;i<=len;i++)
        dp[0][i]=value[0][i];
    for(int i=1;i<fNum;i++){
        for(int j=i;j<=len+i;j++){
            dp[i][j]=dp[i-1][i-1]+value[i][j];
            for(int k=i;k<j&&k<=len+i-1;k++){
                dp[i][j] =max(dp[i][j],dp[i-1][k]+value[i][j]);
            }
        }
    }
    for(int i=0;i<fNum;i++){
        for(int j=0;j<vNum;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    solution();
}
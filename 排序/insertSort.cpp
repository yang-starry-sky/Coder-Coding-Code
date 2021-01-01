#include<cstdio>
using namespace std;

void insertSort(int s[], int begin,int end){
    for(int i = begin+1; i < end; i++){
        int tmp=s[i];
        for(int j = begin; j <=i;j++){
            if(s[j]>tmp){
                for(int k=i;k>=j+1;k--){
                    s[k]=s[k-1];
                }
                s[j]=tmp;
                break;
            }
        }
    }
}
int main(){
    int s[]={2,1,3,9,7,8,5,6,4};
    int len=sizeof(s) / sizeof(s[0]);
    insertSort(s,0,len);
    for(int i=0;i<len;i++)
        printf("%d ",s[i]);
}

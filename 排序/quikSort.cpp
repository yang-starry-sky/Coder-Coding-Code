#include<cstdio>
using namespace std;

void quikSort(int s[], int begin,int end){
    if(end<=begin)
        return;
    int mid=s[begin];
    int pos=begin+1;
    for(int i=begin+1;i<=end;i++){
        int tmp=s[i];
        if(tmp<=mid){
            if(i>pos){
                for(int j=i;j>=pos+1;j--)
                    s[j]=s[j-1];
                s[pos]=tmp;
            }
            pos++;
        }
    }
    pos--;
    for(int i=begin;i<pos;i++)
        s[i]=s[i+1];
    s[pos]=mid;
    quikSort(s,begin,pos-1);
    quikSort(s,pos+1,end);
}
int main(){
    int s[]={2,1,3,9,7,8,5,6,4};
    int len=sizeof(s) / sizeof(s[0]);
    quikSort(s,0,len);
    for(int i=0;i<len;i++)
        printf("%d ",s[i]);
}
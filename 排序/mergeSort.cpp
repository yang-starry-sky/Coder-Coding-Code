#include<cstdio>
#include<vector>
using namespace std;

void merge(int s[], int begin1,int end1,int begin2,int end2){
    int len=end2-begin1+1;
    int tmp=begin1;
    vector<int> v;
    while(begin1<=end1&&begin2<=end2){
        if(s[begin1]>s[begin2]){
            v.push_back(s[begin2]);
            begin2++;
        }
        else{
            v.push_back(s[begin1]);
            begin1++;
        }
    }
    if(v.size()!=len){
        if(begin1<=end1){
            for(int j=begin1;j<=end1;j++){
                v.push_back(s[j]);
            }
        }
        else if(begin2<=end2){
            for(int j=begin2;j<=end2;j++){
                v.push_back(s[j]);
            }
        }
    }
    for(int i=0,j=tmp;j<=end2;i++,j++){
        s[j]=v[i];
    }
}
void mergeSort(int s[],int begin,int end){
    if(begin==end){
        return;
    }
    if(begin==end-1){
        if(s[begin]>s[end]){
            int tmp=s[begin];
            s[begin]=s[end];
            s[end]=tmp;
        }
        return;
    }
    int middle=(begin+end)/2;
    mergeSort(s,begin,middle-1);
    mergeSort(s,middle,end);
    merge(s,begin,middle-1,middle,end);
}
int main(){
    int s[]={2,1,3,9,7,8,5,6,4};
    int len=sizeof(s) / sizeof(s[0]);
    mergeSort(s,0,len);
    for(int i=0;i<len;i++)
        printf("%d ",s[i]);
}

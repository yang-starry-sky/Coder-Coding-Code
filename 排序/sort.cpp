#include<cstdio>
#include<vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

int compareCount=0;
int moveCount=0;

int quikSortFlag1=0;
int quikSortFlag2=0;
int quikSortFlag3=0;

int mergeFlag1=0;
int mergeFlag2=0;
int mergeFlag3=0;
int mergeFlag4=0;
int mergeFlag5=0;
int mergeFlag6=0;
int mergeFlag7=0;
int mergeFlag8=0;

int insertSortFlag=0;

void quikSort(int s[], int begin,int end){
    if(end<=begin){
        quikSortFlag1=1;
        compareCount++;
        return;
    }
    int mid=s[begin];
    int pos=begin+1;
    for(int i=begin+1;i<=end;i++){
        int tmp=s[i];
        if(tmp<=mid){
            quikSortFlag2=1;
            compareCount++;
            if(i>pos){
                quikSortFlag3=1;
                for(int j=i;j>=pos+1;j--){
                    moveCount++;
                    s[j]=s[j-1];
                } 
                s[pos]=tmp;
            }
            pos++;
        }
    }
    pos--;
    for(int i=begin;i<pos;i++){
        s[i]=s[i+1];
        moveCount++;
    }
    s[pos]=mid;
    quikSort(s,begin,pos-1);
    quikSort(s,pos+1,end);
}
void merge(int s[], int begin1,int end1,int begin2,int end2){
    int len=end2-begin1+1;
    int tmp=begin1;
    vector<int> v;
    while(begin1<=end1&&begin2<=end2){
        compareCount++;
        if(s[begin1]>s[begin2]){
            mergeFlag1=1;
            v.push_back(s[begin2]);
            begin2++;
        }
        else{
            mergeFlag2=1;
            v.push_back(s[begin1]);
            begin1++;
        }
    }
    if(v.size()!=len){
        mergeFlag3=1;
        compareCount++;
        if(begin1<=end1){
            mergeFlag4=1;
            for(int j=begin1;j<=end1;j++){
                v.push_back(s[j]);
            }
        }
        else if(begin2<=end2){
            mergeFlag5=1;
            for(int j=begin2;j<=end2;j++){
                v.push_back(s[j]);
            }
        }
    }
    for(int i=0,j=tmp;j<=end2;i++,j++){
        moveCount++;
        s[j]=v[i];
    }
}

void mergeSort(int s[],int begin,int end){
    if(begin==end){
        mergeFlag6=1;
        return;
    }
    if(begin==end-1){
        mergeFlag7=1;
        if(s[begin]>s[end]){
            mergeFlag8=1;
            compareCount++;
            int tmp=s[begin];
            s[begin]=s[end];
            s[end]=tmp;
            moveCount+=3;
        }
        return;
    }
    int middle=(begin+end)/2;
    mergeSort(s,begin,middle-1);
    mergeSort(s,middle,end);
    merge(s,begin,middle-1,middle,end);
}

void insertSort(int s[], int begin,int end){
    for(int i = begin+1; i < end; i++){
        int tmp=s[i];
        for(int j = begin; j <=i;j++){
            if(s[j]>tmp){
                insertSortFlag=1;
                compareCount++;
                for(int k=i;k>=j+1;k--){
                    moveCount++;
                    s[k]=s[k-1];
                }
                s[j]=tmp;
                break;
            }
        }
    }
}
void initCount(){
    compareCount=0;
    moveCount=0;
}
void outPut(int s[],int len){
    printf("Sorted Result:");
    for(int i=0;i<len;i++)
        printf("%d ",s[i]);
    printf("\n");
    printf("move:%d compare:%d\n",moveCount,compareCount);
}
void testQuik(){
    int s[]={2,1,3,9,7,8,5,6,4,12,11,10};
    int len=sizeof(s) / sizeof(s[0]);
    initCount();
    quikSort(s,0,len);
    printf("QuikSort:\n");
    printf("Flag:%d %d %d\n",quikSortFlag1,quikSortFlag2,quikSortFlag3);
    outPut(s,len);
    
}
void testMerge(){
    int s[]={2,1,3,9,7,8,5,6,4,12,11,10};
    int len=sizeof(s) / sizeof(s[0]);
    initCount();
    mergeSort(s,0,len);
    printf("MergeSort:\n");
    printf("Flag:%d %d %d %d %d %d %d %d\n",mergeFlag1,mergeFlag2,mergeFlag3,
                        mergeFlag4,mergeFlag5,mergeFlag6,mergeFlag7,mergeFlag8);
    outPut(s,len);
    
}
void testInsert(){
    int s[]={2,1,3,9,7,8,5,6,4,12,11,10};
    int len=sizeof(s) / sizeof(s[0]);
    initCount();
    insertSort(s,0,len);
    printf("InsertSort:\n");
     printf("Flag:%d\n",insertSortFlag);
    outPut(s,len);
    
}
bool testCorrect(int s[],int len){
    bool flag = true;
    for(int i =1;i<len;i++)
        if(s[i]<s[i-1]){
            flag=false;
            break;
        }
    return flag;        
}
void whiteTest(){
    testQuik();
    testMerge();
    testInsert();
}
void blackTest(){
    srand(time(NULL));

    int correctRate=0;
    int len=100;
    int s[100];

    for(int j=0;j<100;j++){
        for(int i=0;i<len;i++){
            s[i]=rand()%1000;
        }
        quikSort(s,0,len-1);
        if(testCorrect(s,len))
            correctRate++;
    }
    printf("QuikSort:\ncorrectRate: %d \n",correctRate);

    correctRate=0;
    for(int j=0;j<100;j++){
        for(int i=0;i<len;i++){
            s[i]=rand()%1000;
        }
        mergeSort(s,0,len-1);
        if(testCorrect(s,len))
            correctRate++;
    }
    printf("MergeSort:\ncorrectRate: %d \n",correctRate);

    correctRate=0;
    for(int j=0;j<100;j++){
        for(int i=0;i<len;i++){
            s[i]=rand()%1000;
        }
        insertSort(s,0,len);
        if(testCorrect(s,len))
            correctRate++;
    }
    printf("InsertSort:\ncorrectRate: %d \n",correctRate);
    
    
}
int main(){
    blackTest();
    whiteTest();
}

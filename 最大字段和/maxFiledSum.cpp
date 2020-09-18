#include <cstdio>
#include <stdlib.h>
#include <time.h>
using namespace std;
int algorithm1(const int s[], int N){
    int maxSum =0;
    int thisSum = 0;
    for(int i=0; i<N;i++)
        for(int j=i; j<N;j++){
            thisSum=0;
            for(int k=i;k<=j;k++){
                thisSum+=s[k];
            }
            if(thisSum>maxSum)
                maxSum=thisSum;
        }
    return maxSum;
}
int algorithm2(const int s[], int N){
    int maxSum =0;
    int thisSum = 0;
    for(int i=0; i<N;i++){
        for(int j=i,thisSum=0; j<N;j++){
            thisSum+=s[j];
            if(thisSum>maxSum)
                maxSum=thisSum;
        }
    }
    return maxSum;
}
int algorithm3(const int s[], int start, int end){
    if (start==end)
    {
        return s[start];
    }

    int middle=(start+end)/2;
    int leftSum = algorithm3(s, start,middle);
    int rightSum = algorithm3(s,middle+1,end);

    int middleSum1=s[middle];
    int middleSum2=s[middle+1];
    int sum=0;
    for(int i=middle;i>=start;i--){
        sum+=s[i];
        if(sum>middleSum1)
            middleSum1=sum;
    }
    for(int i=middle+1,sum=0;i<=end;i++) {
        sum+=s[i];
        if(sum>middleSum2)
            middleSum2=sum;
    }
    sum=middleSum1+middleSum2;

    if(sum<leftSum)
        sum=leftSum;
    if (sum<rightSum)
        sum=rightSum;
    
    return sum;

}
int algorithm4(const int s[], int N){
    int thisSum=0;
    int maxSum =0;
    for(int i=0;i<N;i++){
        thisSum+=s[i];
        if(thisSum>maxSum)
            maxSum=thisSum;
        else if(thisSum<0)
                thisSum=0;
    }
    return maxSum;
}

void output(const int s[], int N){
    clock_t start,finish;
    start=clock();
    printf("%d :",algorithm1(s,N));
    finish=clock();
    printf("%f seconds\n",(double)finish-start);

    start=clock();
    printf("%d :",algorithm2(s,N));
    finish=clock();
    printf("%f seconds\n",(double)finish-start);

    start=clock();
    printf("%d :",algorithm3(s,0,N-1));
    finish=clock();
    printf("%f seconds\n",(double)finish-start);

    start=clock();
    printf("%d :",algorithm4(s,N));
    finish=clock();
    printf("%f seconds\n",(double)finish-start);
}

void test1(){
    srand(time(NULL));
    int N=10;
    int s[10];
    for(int i=0;i<N;i++)
        s[i]=rand()%20-10;

    output(s,N);
}

void test2(){
    srand(time(NULL));
    int N=100;
    int s[100];
    for(int i=0;i<N;i++)
        s[i]=rand()%200-100;

    output(s,N);
}

void test3(){
    srand(time(NULL));
    int N=1000;
    int s[1000];
    for(int i=0;i<N;i++)
        s[i]=rand()%200-100;

    output(s,N);
}

void test4(){
    srand(time(NULL));
    int N=10000;
    int s[10000];
    for(int i=0;i<N;i++)
        s[i]=rand()%200-100;

    output(s,N);
}

void test5(){
    srand(time(NULL));
    int N=100000;
    int s[100000];
    for(int i=0;i<N;i++)
        s[i]=rand()%200-100;

    output(s,N);
}

int main(){
    printf("test1--------------------------------\n");
    test1();
    printf("test2--------------------------------\n");
    test2();
    printf("test3--------------------------------\n");
    test3();
    printf("test4--------------------------------\n");
    test4();
    printf("test5--------------------------------\n");
    test5();
}
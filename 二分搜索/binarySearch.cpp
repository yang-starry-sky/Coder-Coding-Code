#include <cstdio>
using namespace std;
int search(int ch[],int begin,int end,int num){
    int middle=(begin+end)/2;
    if(ch[middle]==num)
        return middle;
    else if(ch[middle]<num)
        return search(ch, middle,end,num);
    else
        return search(ch, begin,middle,num);
}
int power(int a,int N){
    if(N==0)
        return 1;
    if(N==1)
        return a;
    if(N%2==0)
        return power(a,N/2)^2;
    else
        return power(a,N/2)^2*a;
}
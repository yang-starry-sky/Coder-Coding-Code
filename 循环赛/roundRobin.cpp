# include <cstdio>
#define MAX_DATE 100
using namespace std;

void even(int n, int date[][MAX_DATE]){
    int mid=n/2;
    for(int i=0;i<mid;i++)
        for(int j=0;j<mid;j++){
            date[i+mid][j]=date[i][j]+mid;
            date[i+mid][j+mid]=date[i][j];
            date[i][j+mid]=date[i+mid][j];
        }
}

void odd(int n, int date[][MAX_DATE]){
    int mid=n/2;
    int *tmp=new int[n];
    for(int i=0;i<mid;i++){
        tmp[i]=mid+i+1;
        tmp[mid+i]=tmp[i];
    }
    for(int i=0;i<mid;i++){
        for(int j=0;j<mid+1;j++){
            if(date[i][j]>mid){
                date[i][j]=tmp[i];
                date[mid+i][j]=(tmp[i]+mid)%n;
            }
            else 
                date[mid+i][j]=date[i][j]+mid;
        }
        for(int j=1;j<mid;j++){
            date[i][mid+j]=tmp[i+j];
            date[tmp[i+j]-1][mid+j]=i+1;
        }
    }
}

void solution(int n, int date[][MAX_DATE]){
    if(n==1){
        date[0][0] = 1;
        return;
    }
    if(n%2==1){
        solution(n+1,date);
        return;
    }
    solution(n/2,date);
    if((n/2>1)&&((n/2)%2==1)) 
        odd(n,date);
    else 
        even(n,date);
}

void output(int n,int date[][MAX_DATE]){
    if(n%2==1){
        printf(" arr/d");
        for(int i=1;i<n+1;i++)
            printf("%6d",i);
        printf("\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n+1;j++){
                if(date[i][j]==n+1)
                    printf("     0");
                else  
                    printf("%6d",date[i][j]);
            }
            printf("\n");
        }
    } 
    else{
        printf(" arr/d");
        for(int i=1;i<n;i++)
            printf("%6d",i);
        printf("\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%6d",date[i][j]);
            printf("\n");
        }
    }     
}

void test(int n){
    int date[MAX_DATE][MAX_DATE]={0};
    solution(n, date);
    output(n,date);
    
}
void tests(){
    for(int i=8;i<20;i++){
        test(i);
    }
}
int main(){
    test(9);
}

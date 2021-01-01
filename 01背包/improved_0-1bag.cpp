#include<stdio.h>
#include<vector>
#define MAX_NUM 5
#define max(a,b) ( ((a)>(b)) ? (a):(b) )
using namespace std;

typedef vector<pair<int,int> > jumpingPoint;

int maxCapacity;

void init(){
    maxCapacity=10;
}

void solution(){
    init();
    int weight[MAX_NUM]={2,2,6,5,4};
    int value[MAX_NUM]={6,3,5,4,6};
    jumpingPoint v[MAX_NUM];
    v[0].push_back(make_pair(0,0));
    v[0].push_back(make_pair(weight[0],value[0]));
    for(int i=1;i<MAX_NUM;i++){
        
        jumpingPoint p=v[i-1];
        jumpingPoint q;
        int len1=p.size();
        for(int j=0;j<len1;j++)
            if(weight[i]+p[j].first<=maxCapacity)
                q.push_back(make_pair(weight[i]+p[j].first,value[i]+p[j].second));
    
        int j=1;
        int k=0;
        v[i].push_back(make_pair(0,0));
        printf("i=%d\n",i);
        printf("P:");
        for(int a=0;a<len1;a++)
            if(a!=len1-1)
                printf("%2d %2d, ",p[a].first,p[a].second);
            else
                printf("%2d %2d\n",p[a].first,p[a].second);
        printf("Q:");
        int len2=q.size();
        for(int a=0;a<len2;a++)
            if(a!=len2-1)
                printf("%2d %2d, ",q[a].first,q[a].second);
            else
                printf("%2d %2d\n",q[a].first,q[a].second);    
        while(j!=len1&&k!=len2){
            if(p[j].first<q[k].first){
                if(p[j].second>v[i][v[i].size()-1].second)
                    v[i].push_back(p[j]);
                j++;
            }
            else{
                if(q[k].second>v[i][v[i].size()-1].second)
                    v[i].push_back(q[k]);
                k++;
            }
        }
        if(j==len1&&k!=len2){
            while(k<len2){
                if(q[k].second>v[i][v[i].size()-1].second)
                    v[i].push_back(q[k]);
                k++;
            }
        }
        else if(j!=len1&&k==len2){
            while(j<len1){
                if(p[j].second>v[i][v[i].size()-1].second)
                    v[i].push_back(p[j]);
                j++;
            }
        }
        printf("\n");
    }
    printf("Jumping Points:\n");
    for(int i=0;i<MAX_NUM;i++){
        int len=v[i].size();
        for(int j=0;j<len;j++)
            if(j!=len-1)
                printf("%2d %2d, ",v[i][j].first,v[i][j].second);
            else
                printf("%2d %2d\n",v[i][j].first,v[i][j].second);
    }
}

int main(){
    solution();
}

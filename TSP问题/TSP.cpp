#include <cstdio>
#include <iostream>
#define POINT_NUM 4
using namespace std;

int minCost=(1<<30)-1;
bool flag[POINT_NUM];
int graph[POINT_NUM][POINT_NUM]={0,30,6,4,
                30,0,5,10,
                6,5,0,20,
                4,10,20,0};
int minPath[POINT_NUM];
void TSP(int cost,int x,int from,int path[]){
    if(x==POINT_NUM){
        cost+=graph[from][0];
        cout<<"current path:"<<endl;
        for(int i=0;i<POINT_NUM;i++)
            cout<<path[i]<<" ";
        cout<<endl;
        if(minCost>cost){
            minCost=cost;
            for(int i=0;i<POINT_NUM;i++)
                minPath[i]=path[i];
        }
    }
    if(cost>minCost)
        return;
    for(int i=0;i<POINT_NUM;i++){
        if(!flag[i]){
            flag[i]=true;
            path[x]=i;
            TSP(cost+graph[from][i],x+1,i,path);
            flag[i]=false;
        }
    }
}
void solution(){
    for(int i=0;i<POINT_NUM;i++)
        flag[i]=false;
    flag[0]=true;
    int path[POINT_NUM];
    path[0]=0;
    TSP(0,1,0,path);
    cout<<"minCost="<<minCost<<endl;
    cout<<"minPath:"<<endl;
    for(int i=0;i<POINT_NUM;i++)
            cout<<minPath[i]<<" ";

}
int main(){
    solution();
}
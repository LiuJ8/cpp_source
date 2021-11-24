#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N =5005;
int dis[N];
struct node{
    int from,to,dis;
}edge[N];
int main()
{   
    for(int i=2;i<N;i++) dis[i] = 1e9;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edge[i]=(node){y,x,z};
    }
    dis[1]=0;
    for(int j=1;j<n;j++)
        for(int i=1;i<=m;i++)
        {
           if(dis[edge[i].to]>dis[edge[i].from]+edge[i].dis)
               dis[edge[i].to] = dis[edge[i].from] + edge[i].dis;
         }
    int flag = 0;
    
    for(int i=1;i<=m;i++)
    {
        if(dis[edge[i].from]+edge[i].dis < dis[edge[i].to])
         {
                flag=1;break;
         }
    }
    if(!flag)for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    else cout<<"NO";
}
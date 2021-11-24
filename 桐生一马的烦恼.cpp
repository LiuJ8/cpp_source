#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 200001;
 int n,m;
typedef struct node{
    int s;
    int e;
    int w;
}Edge;
Edge g[N];
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int parent[N];
int find(int x)
{
    if(x==parent[x])
        return x;
    else return parent[x]=find(parent[x]);//只能这么写。
}
void Init(){
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }
}
int main(){
   int flag=0;
    cin>>n>>m;
    if(m<n-1)
    {
         flag=1;
        cout<<"-1";return 0;
    }
    int k=0;
    for(int i=1;i<=m;i++)
    {
        cin>>g[i].s>>g[i].e>>g[i].w;
    }
    sort(g+1,g+1+m,cmp);
    int i=1,t=1,res=0;
    Init();
    int sum=0,x=0;
   for(int i=1;i<=m;i++)
   {
       
       int v1=find(g[i].s);
       int v2=find(g[i].e);
       if(v1!=v2)
       {
           x++;
           sum+=g[i].w;
           parent[v1]=v2;
       }
       if(x==n-1){
           flag=0;
           break;
       }
   }
    if(!flag)
        cout<<sum;
    else cout<<"-1";
}
/*
1.对n个点用n第dijkstra，求出dis的和，最小的S个去掉
2.剩下的是需要装卫星电话的。求出到S个最小的dis的最小值。
3.这些S个dis取最大值。
pass。这也叫算法？
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
const int N = 500001;
int f[N];
struct node{
    int x,y;
}a[N];
struct edge{
    int from,to;
    double dis;
    bool operator<(const edge &a) const{
        return dis<a.dis;
    }
}e[N];
double getdistance(int i,int j)
{
    int x1,x2,y1,y2;
    x1=a[i].x;x2=a[j].x;y1=a[i].y;y2=a[j].y;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int find(int x)
{
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
void Init()
{
    for(int i=1;i<N;i++) f[i]=i;
}
void Union(int a,int b)
{
    a=find(a);b=find(b);
    f[a]=b;
}
void kruscal(int P,int S,int k)//k:所有边的数量和
{
    Init();
   int i=0,j=1;
    while(i<=S-P)
    {
           int v1=e[j].from,v2=e[j].to;
           v1=find(v1);v2=find(v2);
           if(v1!=v2)
           {
               i++;
               Union(v1,v2);
           }
        if(i==S-P){ printf("%.2lf",e[j].dis);break;}
        j++;
    }
}
int main()
{
    int S,P;cin>>S>>P;
    for(int i=1;i<=P;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    int k=0;
    for(int i=1;i<=P;i++)
        for(int j=i+1;j<=P;j++)
        {
            e[++k].from=i;e[k].to=j;e[k].dis=getdistance(i,j);
        }
    sort(e+1,e+1+k);
   // for(int i=1;i<=k;i++) cout<<e[i].dis<<" ";cout<<endl;
    kruscal(S,P,k);
}
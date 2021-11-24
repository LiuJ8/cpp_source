//应该是求第i个点到第j个点的距离，而不是直接求最短距离
//思路总有一点偏颇
/*
直接求最短距离，不知道是求的谁的。但是我也不知道哪里错了。哎很烦。
先能写出来对的，再去搞错了的把
*/
/*
后面处理提前设置好的边的时候，再添加一条边，from to都不变，distance变成0
然后sort的时候这个就会排到最前面，然后前面这两个点Union了后面就不会Union了
我实在是想不到。。。。。
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
const int N =  5000100;//是边的个数。。。。
int f[N];
int n,m;
struct nod{
    int x,y;
}node[N];
struct Edge{
    int from,to;
    double distance;
}edge[N];
void Init()
{
    for(int i=1;i<N;i++)
        f[i]=i;
}
int find(int x)
{
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
void Union(int a,int b)
{
    a=find(a);b=find(b);
    f[b]=a;
}
double getdistance(int i,int j)
{
    int x1,x2,y1,y2;
    x1=node[i].x;x2=node[j].x;
    y1=node[i].y;y2=node[j].y;
    double res;
    res=(double)sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
    return res;
}
bool cmp(Edge a,Edge b)
{
    if(a.distance==b.distance) return a.from<b.from;
    return a.distance<b.distance;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&node[i].x,&node[i].y);
    }
    //求第i个点到其余各点的距离。
    int k=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            edge[++k].from=i;
            edge[k].to=j;
            edge[k].distance=getdistance(i,j);
        }
    }
      Init();
  //  for(int i=1;i<=k;i++)cout<<"("<<node[edge[i].from].x<<","<<node[edge[i].from].y<<")到("<<node[edge[i].to].x<<","<<node[edge[i].to].y<<")的距离是"<<edge[i].distance<<endl;
    for(int i=1;i<=m;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        Union(p,q);
        edge[++k].from=p;
        edge[k].to=q;
        edge[k].distance=0;
    }
  
    double res=0;
    sort(edge+1,edge+1+k,cmp);
   // for(int i=1;i<=k;i++)cout<<"("<<node[edge[i].from].x<<","<<node[edge[i].from].y<<")到("<<node[edge[i].to].x<<","<<node[edge[i].to].y<<")的距离是"<<edge[i].distance<<endl;
    for(int i=1;i<=k;i++)
    {
        int a=edge[i].from,b=edge[i].to;
        int roota=find(a),rootb=find(b);
        if(roota!=rootb)
        {
          //  cout<<"当前节点为("<<node[a].x<<","<<node[a].y<<")和("<<node[b].x<<","<<node[b].y<<")的距离为"<<edge[i].distance<<endl;
            res+=edge[i].distance;
            f[roota]=rootb;
        }
    }
    //cout<<endl;
    printf("%.2lf",res);
}

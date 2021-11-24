#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 501;
int dis[N],tim[N],a[N][N],times[N][N];
int vis[N],path[N],res1[N],res2[N],sum[N];
int n,m;
void Init()
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    memset(tim,0x3f,sizeof(times));
    memset(path,-1,sizeof(path));
}
void dijkstra(int u,int v)
{
   // for(int i=0;i<n;i++) dis[i]=a[u][i],tim[i]=times[u][i];
    dis[u]=tim[u]=0;
    for(int i=1;i<n;i++)
    {
        int minn=0x7ffffff,k=0;
        for(int j=0;j<n;j++)
            if(dis[j]<minn&&!vis[j])
            {
                minn=dis[j];k=j;
            }
        vis[k]=1;
        for(int j=0;j<n;j++)
            if(dis[j]>dis[k]+a[k][j])
            {
                dis[j]=dis[k]+a[k][j];
                tim[j]=tim[k]+times[k][j];
                path[j]=k;
            }
            else if(dis[j]==dis[k]+a[k][j])
            {
                if(tim[j]>tim[k]+times[k][j])
                {
                    tim[j]=tim[k]+times[k][j];
                    path[j]=k;
                }
            }
    }
}
void dijkstra2(int u,int v)
{
    Init();
   // for(int i=0;i<n;i++) tim[i]=times[u][i];
    tim[u]=0;
    sum[u]=1;
    for(int i=1;i<n;i++)
    {
        int minn=0x7fffffff,k=0;
        for(int j=0;j<n;j++)
        {
            if(tim[j]<minn&&!vis[j])
                minn=tim[j],k=j;
        }
        vis[k]=1;
        for(int j=0;j<n;j++)
        {
            if(tim[j]>tim[k]+times[k][j])
            {
                tim[j]=tim[k]+times[k][j];
                sum[j]=sum[k]+1;
                path[j]=k;
            }
            else if(tim[j]==tim[k]+times[k][j])
            {
                if(sum[j]>sum[k]+1)
                {
                    sum[j]=sum[k]+1;
                    path[j]=k;
                }
            }
        }
    }
}
int main()
{
       Init();
       memset(a,0x3f,sizeof(a));
       memset(times,0x3f,sizeof(times));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int v1,v2,mod,l,t;scanf("%d%d%d%d%d",&v1,&v2,&mod,&l,&t);
        if(mod==1) {a[v1][v2]=min(a[v1][v2],l);times[v1][v2]=min(t,times[v1][v2]);}
        else if(mod==0)
        {
            a[v1][v2]=a[v2][v1]=min(min(a[v1][v2],a[v2][v1]),l);
            times[v1][v2]=times[v2][v1]=min(min(times[v1][v2],times[v2][v1]),t);
        }
    }
    int u,v;    scanf("%d%d",&u,&v);
 
    dijkstra(u,v);
    cout<<"Distance = "<<dis[v];
    int k=0;
    for(int i=v;i!=-1;i=path[i]) res1[++k]=i;res1[++k]=u; 
    dijkstra2(u,v);
    int l=0;
    for(int i=v;i!=-1;i=path[i]) res2[++l]=i;res2[++l]=u;
    int i;for(i=1;i<=min(l,k);i++) if(res1[i]!=res2[i]) break;
    if(i>min(l,k)) cout<<"; ";
    else {cout<<": ";for(int i=k;i>1;i--) cout<<res1[i]<<" -> ";cout<<res1[1];cout<<endl;}
    cout<<"Time = "<<tim[v]<<": ";
    for(int i=l;i>1;i--) cout<<res2[i]<<" -> ";cout<<res2[1];
}
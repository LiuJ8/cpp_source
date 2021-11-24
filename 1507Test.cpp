//堆优化的地理斯科拉算法
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 601;
const int MAX = 0x7fffffff ;
int a[N][N],cost[N][N];
int dis[N],vis[N],money[N],path[N];
int main()
{
    memset(path,-1,sizeof(path));
  /* for(int i=0;i<N;i++)
     for(int j=0;j<N;j++)
     {
         if(i!=j)
         cost[i][j]=a[i][j]=MAX;
         
     }*/
    memset(cost,0x3f,sizeof(cost));
    memset(a,0x3f,sizeof(a));
    int n,m,s,d;
    cin>>n>>m>>s>>d;
    for(int i=1;i<=m;i++)
    {
        int q,w,e,r;
        scanf("%d%d%d%d",&q,&w,&e,&r);
        a[q][w]=a[w][q]=e;
        cost[q][w]=cost[w][q]=r;
    }
    for(int i=0;i<n;i++)
    {
        if(i==s)
        {
            money[i]=dis[i]=path[i]=0;continue;
        }
        money[i]=cost[s][i];
        dis[i]=a[s][i];
        if(dis[i]!=MAX)
            path[i] = s;
        else path[i] = -1;
    }
    //for(int i=0;i<n;i++) cout<<money[i]<<" ";cout<<endl;
    //for(int i=0;i<n;i++) cout<<dis[i]<<" ";cout<<endl<<endl;;
    int now=s;
    for(int i=1;i<n;i++)
    {
        int minn=MAX,u;
        for(int j=0;j<n;j++)
        {
            if(dis[j]<minn&&!vis[j])
            {
                minn=dis[j];
                u=j;
            }
        }
        vis[u] = 1;
        for(int j=0;j<n;j++)
        {
            if(dis[u]+a[u][j] < dis[j])
            {
                dis[j] = dis[u] + a[u][j];
                money[j] = money[u] + cost[u][j];
                path[j] = u;
            }
            else if(dis[u] + a[u][j] == dis[j]&& money[j]>money[u]+cost[u][j])
            {
                money[j] = money[u] + cost[u][j];
                path[j] = u;
            }
        }
        //for(int i=0;i<n;i++) cout<<money[i]<<" ";cout<<endl;
       // for(int i=0;i<n;i++) cout<<dis[i]<<" ";cout<<endl;
    }
    int res[501],k=0;
    for(int i=d;i!=s;i=path[i])
    {
        res[++k]=i;
    }
    res[++k]=s;
    for(int i=k;i>=1;i--) cout<<res[i]<<" "; cout<<dis[d]<<" "<<money[d];
}

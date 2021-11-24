#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const  int N = 501;
const int MAX = 0x7fffffff;
int a[N][N],cost[N][N];
int dis[N],money[N];
int vis[N],path[N];
int res[N];
int n,m,s,d;
void Init()
{

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            a[i][j]=cost[i][j]=MAX;
}
void dijkstra()
{

    for(int i=1;i<n;i++)
    {
        int u,minn=0x7fffffff;
        for(int j=0;j<n;j++)
            if(dis[j]<minn&&!vis[j])
            {
                u=j;minn=dis[j];
            }
        vis[u]=1;
      //  cout<<"当前最小点"<<u<<endl;
        for(int j=0;j<n;j++)
        {
            if(dis[u]+a[u][j]<dis[j]&&a[u][j]!=MAX)//a[u][j]!=MAX是因为MAX是int最大，防止再加一个数溢出，下面cost[u][j]同理
            {
                dis[j]=dis[u]+a[u][j];path[j]=u;
                money[j]=money[u]+cost[u][j]; //选取新的最小点之后，对应的花费也需要修改
            }
            else if(dis[u]+a[u][j]==dis[j]&&money[u]+cost[u][j]<money[j]&&cost[u][j]!=MAX)
            {
                money[j] = money[u]+cost[u][j];path[j]=u;
            }
        }
       // for(int j=0;j<n;j++) cout<<dis[j]<<" ";cout<<endl;
        //for(int j=0;j<n;j++) cout<<money[j]<<" ";cout<<endl;
    }
}
int main()
{
    cin>>n>>m>>s>>d;
    Init();
    for(int i=0;i<m;i++)
    {
        int x,y,c,d;
        cin>>x>>y>>c>>d;
        a[x][y]=a[y][x]=c;
        cost[x][y]=cost[y][x]=d;
    }

    for(int i=0;i<n;i++)
    {
        if(i==s) {dis[i]=money[i]=0;continue;}
        dis[i]= a[i][s];
        money[i]=cost[i][s];
        if(dis[i]!=MAX)
            path[i]=s;
        else path[i]=-1;
    }
    //for(int i=0;i<n;i++) cout<<path[i]<<" ";cout<<endl;
    //for(int i=0;i<n;i++) cout<<money[i]<<" ";cout<<endl;
    dijkstra();
    int k=0,sum=0;
    for(int i=d;i!=s;i=path[i])
    {
        res[++k]=i;
        sum+=money[i];
    }
    cout<<s<<" ";for(int i=k;i>=1;i--)cout<<res[i]<<" ";cout<<dis[d]<<" "<<money[d];
}
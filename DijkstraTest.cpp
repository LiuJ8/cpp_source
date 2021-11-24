//
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 2147483647
using namespace std;
const int N = 2000001;
int dist[N];//初始点到每个点的距离
int vis[N];
int head[N];
int n,m,s;

struct Edge{
    int to;
    int w;
    int next;
}edge[N];

int cnt=0;
void add(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void Init()
{
    //i:以s为起点的边的编号
    for(int i=1;i<=n;i++) dist[edge[i].to] = MAX;
   for(int i=head[s];i!=-1;i=edge[i].next)
   {
       dist[edge[i].to] = edge[i].w; 
   }
}
 void Dijkstra()
{
    int now=s;
    dist[s]=0;
    vis[s]=1;
    int minn=MAX;
    for(int i=1;i<n;i++)
    {
        
        //s~now + now~j < s~j
        //更新以now为起点的边
        for(int i=1;i<=n;i++) cout<<vis[i]<<" ";cout<<endl;
        minn=MAX;
        for(int j=1;j<=n;j++)
        {
            
            if(minn>dist[j]&&!vis[j])
            {cout<<j<<" "<<vis[j]<<endl;
                minn=dist[j];
                now=j;
            }
        }
        cout<<"当前最小节点为"<<now<<endl;
        vis[now]=1;
        for(int j=head[now];j!=-1;j=edge[j].next)
        {
            cout<<s<<"~"<<now<<"的距离"<<dist[now]<<"+"<<now<<"~"<<edge[j].to<<"的距离"<<edge[j].w<<"应该小于"<<s<<"~"<<j<<"的距离"<<dist[edge[j].to]<<endl;
            if(dist[now]+edge[j].w<dist[edge[j].to])
               {
                   cout<<"成立，所以更新"<<s<<"~"<<edge[j].to<<"的距离由"<<dist[edge[j].to];
                    dist[edge[j].to] = dist[now] + edge[j].w;
                    cout<<"为"<<dist[edge[j].to]<<endl;
                    
               }
        }
    }
}
int main()
{
    cin>>n>>m>>s;
    memset(head,-1,sizeof(head)) ;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;//from,to,weight
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    Init();
    Dijkstra();
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";cout<<endl;
}
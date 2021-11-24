#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 10001;
int dis[N],path[N],times[N],head[N],vis[N];
int sum=0;// ×ÜµÄÕ¾Êý
vector<int> zhan[N];
struct edge{
    int to,next;
}e[N];
int iszhan[N];
void Init()
{
    memset(dis,0x3f,sizeof(dis));
    memset(times,0x3f,sizeof(times));
    memset(path,-1,sizeof(path));
    memset(head,-1,sizeof(head));
}
int cnt=0;
void add(int u,int v)
{
    e[cnt].next=head[u];
    e[cnt].to=v;
    head[u]=cnt++;
}
void dijkstra(int u)
{
     Init();
    dis[u]=times[u]=0;
    for(int i=1;i<sum;i++)
    {
        int minn=0x3f3f3f3f,k=-1;
        for(int j=1;j<=sum;j++)
        {
            if(minn>dis[j]&&!vis[j]) {minn=dis[j];k=j;}
        }
        if(minn!=0x3f3f3f3f) vis[k]=1;
        for(int j=head[k];j!=-1;j=e[j].next)
        {
            int to=e[j].to;
            if(dis[to]>dis[k]+1)
            {
                dis[to]=dis[k]+1;
                path[to]=k;
            }
            else if(dis[to]==dis[k]+1)
            {
                if(times[to]>times[k]+)
            }
        }
    }
}
int main()
{
   
    int n,m,id,node;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&id);
        int first; sum++;
        scanf("%d",&first); zhan[id].push_back(first);
        for(int j=2;j<=id;j++)
        {
            scanf("%d",&node); add(first,node);add(node,first);
            zhan[id].push_back(node);
            first=node;sum++;
        }
    }
    scanf("%d",&m);
    //for(int i=1;i<=m;i++)
    {
        int from,to;    scanf("%d%d",&from,&to);
        dijkstra(from);
    }
}
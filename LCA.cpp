#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
const int N = 8*1e7+1;
const int maxn= 40010;
int head[maxn],vis[maxn];
int dfn[maxn],low[maxn];
int n,m;
int cnt=0;
struct edge{
    int to,w,next;
}e[N];
void Init()
{
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
}
void add(int u,int v,int w)
{
    e[++cnt].w=w;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u] = cnt;
}
void tarjan(int x)
{
    stack<int> q;
    low[x] = dfn[x] = ++cnt;
    q.push(x);
    vis[x]=1;
    for(int i=head[x];i!=-1;i=e[i].next)
    {
        int to=e[i].to;
        if(!dfn[to]) { tarjan(to); low[x] = min(low[x],low[to]);}//没被深搜过。深搜to
        else if(vis[to])    //被深搜过且to目前在栈内，说明x和to是一个强连通分量
            low[to] = min(low[x],dfn[to]);///////////////////////////
    }
    if(low[x]==dfn[x])
    {
        vis[q.top()]=0;
        q.pop();
    }
    vis[q.top()] =0;q.pop();
}
void work()
{
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
}
int main()
{
    int cishu;
    cin>>cishu;
    while(cishu--)
    {
        Init();
        cin>>n>>m;
        for(int i=1;i<=n-1;i++)
        {
            int u,v,w;scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);add(v,u,w);
        }

    }
    
}
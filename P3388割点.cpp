#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e6+1;
int cnt=0;
int head[N];
int vis[N];
int dfn[N],low[N];
int res[N];
void Init()
{
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(dfn));
}
struct edge{
    int to,next;
}e[N];
void add(int u,int v)
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
int c=0;
void tarjan(int x,int fa)//fa是本次搜索的根节点
{
    int child=0;
    low[x]=dfn[x]=++c; 
    //vis[x]=1; 求强连通分量的时候需要用到vis，求割点不需要
    for(int i=head[x];i!=-1;i=e[i].next)
    {
        int to=e[i].to;
        if(!dfn[to])    
        {
            tarjan(to,fa);
            low[x]=min(low[x],low[to]);
            if(low[to]>=dfn[x]&&x!=fa) res[x]=1; //x->to 如果通过to不能回溯到x前面，则x是割点，割掉x to就回不去了。
            if(x==fa) child++;
        }
        else low[x]=min(low[x],dfn[to]);
    }
    if(child>=2&&x==fa) res[x]=1;
}
int main()
{
    int n,m;
    cin>>n>>m;
    Init();
    for(int i=1;i<=m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i]) tarjan(i,i);    //可能不连通，每个点都要考虑
    }
    int sum=0;
    for(int i=1;i<=n;i++)if(res[i])sum++;
    for(int i=1;i<=n;i++) cout<<low[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++) cout<<dfn[i]<<" ";cout<<endl;
    cout<<sum<<endl;
    for(int i=1;i<=n;i++)if(res[i])cout<<i<<" ";
}
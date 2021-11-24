/*
染色法。用深搜，用链式前向星。
用染色，一条边相邻的两个点的颜色不能相同。
未说明图一定联通，所以对每个点都需要判断是否vis然后对每个连通分量而言
可以染成一个颜色或者另外一个颜色。这个怎么理解呢，每个连通分量都给一个初始点，这个点的颜色是固定的（0或1，所以这个图的其他点的颜色也全部确定了。可能是染成初始点这个颜色，也可能是反过来。然后取这两个颜色的最小值。
嗯。学会了应该
*/
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 200000;
int cnt=0;
int head[N],vis[N];
int sum[2],color[N];
void Init()
{
    memset(head,-1,sizeof(head));
}
struct edge{
    int to,next;
}e[N];
void add(int u,int v)
{
    e[cnt].to=v; e[cnt].next=head[u];head[u]=cnt++;
}
bool dfs(int node,int clr)  //染色，返回false则impossible
{
    if(vis[node])
    {
        if(color[node]==clr) return true;
        return false;
    }
    vis[node]=1;
    color[node]=clr;
    sum[clr]++;
    bool viable=true;
    for(int i=head[node];i!=-1&&viable;i=e[i].next)
    {
        int to=e[i].to;
        viable=viable&&dfs(to,1-clr);
    }
    return viable;
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
    int res=0;
    for(int i=1;i<=n;i++)
    {
        memset(sum,0,sizeof(sum));
        if(!vis[i])
        {
            if(!dfs(i,1))
            {
                cout<<"Impossible";return 0;
            }
            res+=min(sum[1],sum[0]);
        }
    }
    cout<<res;
}
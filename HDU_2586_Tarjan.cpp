#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;
//const int N = 8*1e7+1;
const int maxn= 40010*2;
int head[maxn],vis[maxn];
int f[maxn],dis[maxn];
int ans[maxn];
vector<int> query[maxn];
vector<int> num[maxn];
int n,m;
int cnt;
struct edge{
    int to,w,next;
}e[maxn*2]; //存的是双向边
void Init()
{
    cnt=0;
    memset(ans,0,sizeof(ans));
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));  //设置为0 不同于dijkstra
    for(int i=1;i<maxn;i++) f[i]=i;
    query->clear();
    num->clear();
}
int find(int x)
{
    if(x==f[x]) return x;return f[x] =find(f[x]);
}
void Union(int a,int b) //a=u b=to
{
    a=find(a);b=find(b);f[b]=a;//f[a]=b就不对。因为是从a点到b点，所以a是b的父节点。很细节。
}
void add(int u,int v,int w)
{
    e[++cnt].w=w;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u] = cnt;
}
void tarjan(int u,int val)  //u是点，val是源点到u的路径和。 初始点是1，1到1的距离是0，后面就要加上边的权值
{
    vis[u]=1; dis[u]=val;
    for(int i=head[u];i!=-1;i=e[i].next)
    {
        int to=e[i].to;
        if(vis[to]) continue; //双向边，防止重复
        tarjan(to,val+e[i].w); //dfs
        Union(u,to);    //合并 
    }
    for(int i=0;i<query[u].size();i++)
    {
        int t=query[u][i];//query[u][i]是询问的点，i只是按下标存的点
        if(!vis[t]) continue;   //没被访问过，说明深搜没有到。这个询问的点距离不算
        ans[num[u][i]] = dis[u]+dis[t]-2*dis[find(t)];
    }
}
int main()
{
    int cishu;
    cin>>cishu;
    while(cishu--)
    {
        Init();
        cin>>n>>m;
        for(int i=1;i<n;i++)
        {
            int u,v,w;  scanf("%d%d%d",&u,&v,&w);
            add(u,v,w); add(v,u,w); //双向边
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            query[u].push_back(v);query[v].push_back(u);//query[u]里存的是询问u~v的全部询问的点
            num[u].push_back(i);num[v].push_back(i);    //num[u]里存的是询问点u是第几次询问
        }
        tarjan(1,0);    //将1设置为根节点，点是1~n的
        for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
       // cout<<endl;for(int i=1;i<=n;i++)cout<<f[i]<<" ";cout<<endl;
    }
}

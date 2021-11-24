//堆优化的Dijkstra
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 200001;
struct edge{
    int to,w,next;
};
edge e[N];
int head[N],dis[N],cnt=0;
int vis[N];
int n,m,s;
void add(int u,int v,int d)
{
    cnt++;
    e[cnt].w=d;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
struct node
{
    int dis;
    int pos;
    bool operator<(const node &x)const
    {
        return x.dis<dis;
    }
};
priority_queue<node> q;
inline void dijkstra()
{
    dis[s]=0;
    q.push((node){0,s});
    while(!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int x=tmp.pos,d=tmp.dis;
        if(vis[x])
        {
            cout<<x<<"已经被访问过"<<endl;
            continue;
        }
         vis[x]=1;
         for(int i=1;i<=n;i++) cout<<dis[i]<<" ";cout<<endl;
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].to;
            //u~y > u~x + x~y
            cout<<"起点："<<x<<" 终点:"<<y<<endl;
            if(dis[y]>dis[x]+e[i].w)
            {
                cout<<dis[y]<<">"<<dis[x]<<"+"<<e[i].w<<endl;
                dis[y] = dis[x] + e[i].w;
                if(vis[y]) cout<<y<<"被访问过"<<endl;else cout<<y<<"未未被访问过"<<endl;
                if(!vis[y])
                {
                    q.push((node){dis[y],y});
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) dis[i]=0x7fffffff;
    for(int i=0;i<m;i++)    
    {
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        add(u,v,d);
    }
    dijkstra();
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
}
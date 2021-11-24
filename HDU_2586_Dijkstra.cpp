#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long int ll;
const int N = 8*1e7+1;
const int maxn = 40010;
int vis[maxn],head[maxn];
ll dis[maxn];
struct edge{
    int to,w,next;
}e[N];
int cnt=0;
void add(int u,int v,int w)
{
    e[++cnt].w=w;
    e[cnt].to = v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
struct node{
    int dis,x;
    bool operator<(const node &a)const {
        return  a.dis < dis;
    }
};
void dijkstra(int u,int v)
{
    priority_queue<node> q;
    dis[u] = 0;
    node temp;temp.x=u;temp.dis=0; 
    q.push(temp);
    while(!q.empty())
    {
        node front =q.top();q.pop();
        if(vis[front.x]) continue;
        vis[front.x] = 1;
        for(int i=head[front.x];i!=-1;i=e[i].next)
        {
            int to=e[i].to;
            if(dis[to] > dis[front.x] + e[i].w)
            {
                dis[to] = dis[front.x] + e[i].w;
                if(!vis[to]){ node temp;temp.dis=dis[to];temp.x=to;q.push(temp); }//  q.push((node){dis[to],to});}
            }
        }
    }
}
ll query(int u,int v)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dijkstra(u,v);
    return dis[v];
}
int main()
{
    int cishu;
    cin>>cishu;
    while(cishu--)
    {
        int n,m;
        cin>>n>>m;
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n-1;i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            add(x,y,w);
            add(y,x,w);
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            cout<<query(u,v)<<endl;;
        }
    }
}
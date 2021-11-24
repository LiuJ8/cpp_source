#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N = 5001; 
int cnt=0;
int vis[N],head[N],times[N],dis[N];
int n,m;
struct edge{
    int to,w,next;
}e[N*3];    //有超级源点的n条边，还有a==b时添加的时两条边。
void add(int u,int v,int w)
{
    e[++cnt].to=v;
    e[cnt].next=head[u];
    e[cnt].w=w;
    head[u] = cnt;
}
bool spfs(int s)
{
    dis[s] = 0;times[s] = 1;vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front(); q.pop();
        vis[x] = 0;
        for(int i=head[x];i!=-1;i=e[i].next)
        {
            int to = e[i].to;
            if(dis[to] > dis[x] + e[i].w)
            {
                dis[to] = dis[x] + e[i].w;
                if(!vis[to])
                {
                    q.push(to); vis[to] = 1; times[to]++;
                }
                if(times[to] > n) return false;
            }
        }
    }
    return true;
}
int main()
{
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
        add(0,i,0);
    for(int i=1;i<=m;i++)
    {
        int mod,a,b,c;
        scanf("%d",&mod);
       if(mod==1)
       {
           scanf("%d%d%d,",&a,&b,&c);
            add(a,b,-c);
       }
       else if(mod==2)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(b,a,c);
        }
        else if(mod==3)
        {
            scanf("%d%d",&a,&b);
            add(b,a,c);
            add(a,b,-c);
        }
    }
    bool flag=spfs(0);
    if(flag) cout<<"Yes";else cout<<"No";
}
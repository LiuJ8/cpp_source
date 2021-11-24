#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 5005;
int dis[N],vis[N],head[N];
int times[N];
struct edge{
    int to,w,next;
}e[N*2]; //记得算上连接超级源点的n条边。
int cnt=0;
void add(int u,int v,int w)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].w=w; 
    e[cnt].next=head[u];
    head[u]=cnt;
}
bool spfs(int s,int n)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    times[s] = 1;
    dis[s] = 0;
    while(!q.empty())
    {
        int temp=q.front();q.pop();
        vis[temp]=0;
       for(int i=head[temp];i!=-1;i=e[i].next)
       {
           //e[i].to
           int x=e[i].to;
           if(dis[x] > dis[temp] + e[i].w)
           {
               dis[x] = dis[temp] + e[i].w;
               if(!vis[x]){ q.push(x);vis[x]=1; times[x]++;}
           }
           if(times[x] > n) return false; //这个地方是 > n 题才能AC，网上说的全是 >=n 不会，前面Ford算法最后的判断也不知道为什么。
       }
    }
    return true;
}
int main()
{
    memset(dis,0x3f,sizeof(dis));
    memset(head,-1,sizeof(head));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) add(0,i,0);
    for(int i=1;i<=m;i++)
    {
        int x,y,w;scanf("%d%d%d",&x,&y,&w);
        add(y,x,w);
    }

    if(!spfs(0,n)) cout<<"NO"; else for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
}
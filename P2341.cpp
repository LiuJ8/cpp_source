#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int N = 50001;
int head[N],sum[N],id[N],chudu[N];//sum[i]表示第i个强连通分量内点的个数
int low[N],dfn[N],vis[N];//vis[i]用来判断i是否在栈中
void Init()
{
    memset(head,-1,sizeof(head));
}
int cnt=0;
struct edge{
    int to,next;
}e[N];
void add(int u,int v)
{
    e[cnt].to=v;e[cnt].next=head[u];head[u]=cnt++;
}
int chuo=0;//时间戳儿
stack<int >s;
int total=0;    //强连通分量的个数
void tarjan(int x)
{
    low[x]=dfn[x]=++chuo;
    s.push(x);vis[x]=1;
    for(int i=head[x];i!=-1;i=e[i].next)
    {
        if(!dfn[e[i].to])
        {
            tarjan(e[i].to);
            low[x]=min(low[x],low[e[i].to]);
        }
        else if(vis[x]) //被访问过且当前在栈中
            low[x]=min(low[x],dfn[e[i].to]);
    }
        int k;
        if(low[x]==dfn[x])
        {
            total++;
            do
            {
                k=s.top();s.pop();
                vis[k]=0;
                id[k]=total;sum[total]++;
            } while (k!=x);  
        }
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    Init();
    for(int i=1;i<=m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);    add(u,v);
    }
   for(int i=1;i<=n;i++)
   {
        if(!dfn[i]) tarjan(i);
   }
   for(int i=1;i<=n;i++)//遍历以所有点开始的所有边，如果边的两端点染色不一致，说明该边不在一个强连通分量内，起点的出度+1
   {
       for(int j=head[i];j!=-1;j=e[j].next)
       {
           if(id[i]!=id[e[j].to])
           {
               chudu[id[i]]++;
           }
       }
   }
    int res=0;
    for(int i=1;i<=total;i++)//遍历所有的连通分量
    {
        if(!chudu[i])
        {
            if(res) {cout<<"0";return 0;}
            res=i;
        }
    }
    cout<<sum[res];
}
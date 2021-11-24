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
void tarjan(int x,int fa)//fa�Ǳ��������ĸ��ڵ�
{
    int child=0;
    low[x]=dfn[x]=++c; 
    //vis[x]=1; ��ǿ��ͨ������ʱ����Ҫ�õ�vis�����㲻��Ҫ
    for(int i=head[x];i!=-1;i=e[i].next)
    {
        int to=e[i].to;
        if(!dfn[to])    
        {
            tarjan(to,fa);
            low[x]=min(low[x],low[to]);
            if(low[to]>=dfn[x]&&x!=fa) res[x]=1; //x->to ���ͨ��to���ܻ��ݵ�xǰ�棬��x�Ǹ�㣬���x to�ͻز�ȥ�ˡ�
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
        if(!dfn[i]) tarjan(i,i);    //���ܲ���ͨ��ÿ���㶼Ҫ����
    }
    int sum=0;
    for(int i=1;i<=n;i++)if(res[i])sum++;
    for(int i=1;i<=n;i++) cout<<low[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++) cout<<dfn[i]<<" ";cout<<endl;
    cout<<sum<<endl;
    for(int i=1;i<=n;i++)if(res[i])cout<<i<<" ";
}
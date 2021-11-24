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
}e[maxn*2]; //�����˫���
void Init()
{
    cnt=0;
    memset(ans,0,sizeof(ans));
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));  //����Ϊ0 ��ͬ��dijkstra
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
    a=find(a);b=find(b);f[b]=a;//f[a]=b�Ͳ��ԡ���Ϊ�Ǵ�a�㵽b�㣬����a��b�ĸ��ڵ㡣��ϸ�ڡ�
}
void add(int u,int v,int w)
{
    e[++cnt].w=w;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u] = cnt;
}
void tarjan(int u,int val)  //u�ǵ㣬val��Դ�㵽u��·���͡� ��ʼ����1��1��1�ľ�����0�������Ҫ���ϱߵ�Ȩֵ
{
    vis[u]=1; dis[u]=val;
    for(int i=head[u];i!=-1;i=e[i].next)
    {
        int to=e[i].to;
        if(vis[to]) continue; //˫��ߣ���ֹ�ظ�
        tarjan(to,val+e[i].w); //dfs
        Union(u,to);    //�ϲ� 
    }
    for(int i=0;i<query[u].size();i++)
    {
        int t=query[u][i];//query[u][i]��ѯ�ʵĵ㣬iֻ�ǰ��±��ĵ�
        if(!vis[t]) continue;   //û�����ʹ���˵������û�е������ѯ�ʵĵ���벻��
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
            add(u,v,w); add(v,u,w); //˫���
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            query[u].push_back(v);query[v].push_back(u);//query[u]������ѯ��u~v��ȫ��ѯ�ʵĵ�
            num[u].push_back(i);num[v].push_back(i);    //num[u]������ѯ�ʵ�u�ǵڼ���ѯ��
        }
        tarjan(1,0);    //��1����Ϊ���ڵ㣬����1~n��
        for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
       // cout<<endl;for(int i=1;i<=n;i++)cout<<f[i]<<" ";cout<<endl;
    }
}

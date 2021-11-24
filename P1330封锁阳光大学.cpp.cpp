/*
Ⱦɫ���������ѣ�����ʽǰ���ǡ�
��Ⱦɫ��һ�������ڵ����������ɫ������ͬ��
δ˵��ͼһ����ͨ�����Զ�ÿ���㶼��Ҫ�ж��Ƿ�visȻ���ÿ����ͨ��������
����Ⱦ��һ����ɫ��������һ����ɫ�������ô����أ�ÿ����ͨ��������һ����ʼ�㣬��������ɫ�ǹ̶��ģ�0��1���������ͼ�����������ɫҲȫ��ȷ���ˡ�������Ⱦ�ɳ�ʼ�������ɫ��Ҳ�����Ƿ�������Ȼ��ȡ��������ɫ����Сֵ��
�š�ѧ����Ӧ��
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
bool dfs(int node,int clr)  //Ⱦɫ������false��impossible
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
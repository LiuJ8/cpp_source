//
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 2147483647
using namespace std;
const int N = 2000001;
int dist[N];//��ʼ�㵽ÿ����ľ���
int vis[N];
int head[N];
int n,m,s;

struct Edge{
    int to;
    int w;
    int next;
}edge[N];

int cnt=0;
void add(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void Init()
{
    //i:��sΪ���ıߵı��
    for(int i=1;i<=n;i++) dist[edge[i].to] = MAX;
   for(int i=head[s];i!=-1;i=edge[i].next)
   {
       dist[edge[i].to] = edge[i].w; 
   }
}
 void Dijkstra()
{
    int now=s;
    dist[s]=0;
    vis[s]=1;
    int minn=MAX;
    for(int i=1;i<n;i++)
    {
        
        //s~now + now~j < s~j
        //������nowΪ���ı�
        for(int i=1;i<=n;i++) cout<<vis[i]<<" ";cout<<endl;
        minn=MAX;
        for(int j=1;j<=n;j++)
        {
            
            if(minn>dist[j]&&!vis[j])
            {cout<<j<<" "<<vis[j]<<endl;
                minn=dist[j];
                now=j;
            }
        }
        cout<<"��ǰ��С�ڵ�Ϊ"<<now<<endl;
        vis[now]=1;
        for(int j=head[now];j!=-1;j=edge[j].next)
        {
            cout<<s<<"~"<<now<<"�ľ���"<<dist[now]<<"+"<<now<<"~"<<edge[j].to<<"�ľ���"<<edge[j].w<<"Ӧ��С��"<<s<<"~"<<j<<"�ľ���"<<dist[edge[j].to]<<endl;
            if(dist[now]+edge[j].w<dist[edge[j].to])
               {
                   cout<<"���������Ը���"<<s<<"~"<<edge[j].to<<"�ľ�����"<<dist[edge[j].to];
                    dist[edge[j].to] = dist[now] + edge[j].w;
                    cout<<"Ϊ"<<dist[edge[j].to]<<endl;
                    
               }
        }
    }
}
int main()
{
    cin>>n>>m>>s;
    memset(head,-1,sizeof(head)) ;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;//from,to,weight
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    Init();
    Dijkstra();
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";cout<<endl;
}
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
    for(int i=1;i<=n;i++)    
        dist[i]=MAX;
}
 void Dijkstra()
{
    int now=s;
    dist[s]=0;
    int minn=MAX;
    while(!vis[now]) //������ͼ
    {
        vis[now] = 1;
        //s~ i   s~now+now~j < s~j
       // for(int i=1;i<=n;i++) cout<<dist[i]<<" ";cout<<endl;
        for(int i=head[now];i!=-1;i=edge[i].next)
        {
            //i :��nowΪ���ı߱��
            //cout<<s<<"��"<<now<<"�ľ���Ϊ"<<dist[now]<<"+"<<edge[i].w<<"��ҪС��"<<s<<"��"<<edge[i].to<<"�ľ���"<<dist[edge[i].to]<<endl;;
            if(!vis[edge[i].to]&&dist[now]+edge[i].w<dist[edge[i].to])
                dist[edge[i].to] = dist[now] + edge[i].w;
        }
      minn=MAX;
      for(int i=1;i<=n;i++)
      {
          if(!vis[i]&&dist[i]<minn)
            {
                   minn=dist[i];
                   now=i;
            }
      }
      //cout<<"��ǰ�ڵ�Ϊ"<<now<<endl;
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
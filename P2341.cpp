#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int N = 50001;
int head[N],sum[N],id[N],chudu[N];//sum[i]��ʾ��i��ǿ��ͨ�����ڵ�ĸ���
int low[N],dfn[N],vis[N];//vis[i]�����ж�i�Ƿ���ջ��
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
int chuo=0;//ʱ�����
stack<int >s;
int total=0;    //ǿ��ͨ�����ĸ���
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
        else if(vis[x]) //�����ʹ��ҵ�ǰ��ջ��
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
   for(int i=1;i<=n;i++)//���������е㿪ʼ�����бߣ�����ߵ����˵�Ⱦɫ��һ�£�˵���ñ߲���һ��ǿ��ͨ�����ڣ����ĳ���+1
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
    for(int i=1;i<=total;i++)//�������е���ͨ����
    {
        if(!chudu[i])
        {
            if(res) {cout<<"0";return 0;}
            res=i;
        }
    }
    cout<<sum[res];
}
#include<iostream>
#include<algorithm>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAX 0x3f3f3f3f
using namespace std;
const int N = 300000;
int head[N],path[N];
int dis[N],times[N],vis[N];
int res[N],res2[N],vist[N];
int sum[N];
struct edge{
    int to,w,t,next;
}e[N*2];
struct node{
    int x,t,w;//x是点，t是起点到x的时间，w是起点到x的距离
    bool operator<(const node &a)const {
        if(a.w==w)return a.t<t;
        return a.w<w;
    }
};
struct nod{
    int x,t;
    bool operator<(const nod &a)const {
        return a.t<t;
    }
};
int cnt=0;
void Init()
{
    memset(path,-1,sizeof(path));
    memset(vis,0,sizeof(vis));
    //for(int i=0;i<N;i++)dis[i]=times[i]=sum[i]=MAX;
    memset(dis,0x3f,sizeof(dis));
    memset(times,0x3f,sizeof(times));
    memset(sum,0x3f,sizeof(sum));
}
void add(int u,int v,int w,int t)
{
    e[cnt].w=w;
    e[cnt].to=v;
    e[cnt].t=t;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
void dijkstra(int u,int v)
{
    priority_queue<node>q;
    node temp;temp.x=u;temp.w=temp.t=0; 
    dis[u]=times[u]=0;   ///aaaaaaaaaaaaaaaaaaaa这个忘了写了！！！！！！！！！！！！
    q.push(temp);
    while(!q.empty())
    {
        node x=q.top();q.pop();
        int from=x.x,d=x.w,t=x.t;
      //  cout<<"当前节点为"<<from<<endl;
        if(vis[from])  {continue;}
        //cout<<from<<"未被访问过"<<endl;
        vis[from]=1;
        for(int i=head[from];i!=-1;i=e[i].next)
        {
           // cout<<from<<"->"<<e[i].to<<endl;
            int to=e[i].to;
        //    cout<<"距离 "<<dis[to]<<"应该>"<<dis[from]<<"+"<<e[i].w<<endl;
        //    cout<<"时间 "<<times[to]<<"应该>"<<times[from]<<"+"<<e[i].t<<endl;
            if(dis[to]>dis[from]+e[i].w)
            {
                dis[to]=dis[from]+e[i].w;
                times[to]=times[from]+e[i].t;
                path[to]=from;
                if(!vis[to]){node temp;temp.x=to;temp.w=dis[to];temp.t=times[to];q.push(temp);}
            }
            else if(dis[to]==dis[from]+e[i].w)
                if(times[to]>times[from]+e[i].t)
                {
                    times[to]=times[from]+e[i].t;
                    path[to]=from;
                    if(!vis[to]){node temp;temp.x=to;temp.w=dis[to];temp.t=times[to];q.push(temp);}
                }
            
        }

    }
}
void dijkstra2(int u,int v)
{
    priority_queue<nod>q;
    nod temp;temp.x=u;temp.t=0;
    dis[u]=times[u]=0;
    sum[u]=1;
    q.push(temp);
    while(!q.empty())
    {
        nod x=q.top();q.pop();
        int from=x.x;
      //  cout<<"当前节点为"<<from<<endl;
        if(vis[from]) {continue;}
      //  cout<<from<<"未被访问过"<<endl;
        vis[from]=1;
        for(int i=head[from];i!=-1;i=e[i].next)
        {
          //  cout<<from<<"->"<<e[i].to<<endl;
            int to=e[i].to;
         //     cout<<"距离 "<<dis[to]<<"应该>"<<dis[from]<<"+"<<e[i].w<<endl;
         //  cout<<"时间 "<<times[to]<<"应该>"<<times[from]<<"+"<<e[i].t<<endl;
            if(times[to]>times[from]+e[i].t)
            {
                times[to]=times[from]+e[i].t;
                sum[to]=sum[from]+1;
                path[to]=from;
              //  for(int j=to;j!=-1;j=path[j])   total++; sum[to]=total;
               // cout<<to<<"有无访问过："<<vis[to]<<endl;
                if(!vis[to]) {nod temp1;temp1.x=to;temp1.t=times[to];q.push(temp1);}
            }
            else if(times[to]==times[from]+e[i].t)
            {
                if(sum[to]>sum[from]+1)
                {   
                    sum[to]=sum[from]+1;
                    path[to]=from;
                  // int total=0; for(int j=to;j!=-1;j=path[j])   total++; sum[to]=total;
                  //   cout<<to<<"有无访问过："<<vis[to]<<endl;
                    if(!vis[to]) {nod temp1;temp1.x=to;temp1.t=times[to];q.push(temp1);}
                }
            }
           // for(int i=1;i<=10;i++) cout<<sum[i]<<" ";cout<<endl;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    Init();
     memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++)   
    {
        int v1,v2,mod,l,t,flag=0;
        scanf("%d%d%d%d%d",&v1,&v2,&mod,&l,&t);
        //for(int j=head[v1];j!=-1;j=e[j].next)
        //    if(v2==e[j].to) e[j].w=min(l,e[j].w),e[j].t=min(t,e[j].t),flag=1;
        //if(mod==0)
           // for(int j=head[v2];j!=-1;j=e[j].next)
          //  if(v1==e[j].to) e[j].w=min(l,e[j].w),e[j].t=min(t,e[j].t),flag=1;
            if(mod==1) add(v1,v2,l,t);
            else if(mod==0) {add(v1,v2,l,t);add(v2,v1,l,t);}
        
    }
    int u,v;scanf("%d%d",&u,&v);
    dijkstra(u,v);
    int k=0;
    //for(int i=1;i<=10;i++) cout<<path[i]<<" ";cout<<endl;
    for(int i=v;i!=-1;i=path[i])
        res[++k]=i;
    cout<<"Distance = "<<dis[v];
    //cout<<endl;
    //第二次弄
    Init();
    dijkstra2(u,v);
    int l=0;
     for(int i=v;i!=-1;i=path[i])
        res2[++l]=i;
    int i;
    for(i=1;i<=min(l,k);i++) if(res[i]!=res2[i]) {break;}    
    
    if(i>min(l,k)) cout<<"; ";
    else {cout<<":"<<" ";for(int i=k;i>1;i--)cout<<res[i]<<" -> "; cout<<res[1]<<endl;}
    cout<<"Time = "<<times[v]<<": ";for(int i=l;i>1;i--)cout<<res2[i]<<" -> ";cout<<res2[1];
}
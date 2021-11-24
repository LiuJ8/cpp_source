//Ӧ�������i���㵽��j����ľ��룬������ֱ������̾���
//˼·����һ��ƫ��
/*
ֱ������̾��룬��֪�������˭�ġ�������Ҳ��֪��������ˡ����ܷ���
����д�����Եģ���ȥ����˵İ�
*/
/*
���洦����ǰ���úõıߵ�ʱ�������һ���ߣ�from to�����䣬distance���0
Ȼ��sort��ʱ������ͻ��ŵ���ǰ�棬Ȼ��ǰ����������Union�˺���Ͳ���Union��
��ʵ�����벻������������
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
const int N =  5000100;//�Ǳߵĸ�����������
int f[N];
int n,m;
struct nod{
    int x,y;
}node[N];
struct Edge{
    int from,to;
    double distance;
}edge[N];
void Init()
{
    for(int i=1;i<N;i++)
        f[i]=i;
}
int find(int x)
{
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
void Union(int a,int b)
{
    a=find(a);b=find(b);
    f[b]=a;
}
double getdistance(int i,int j)
{
    int x1,x2,y1,y2;
    x1=node[i].x;x2=node[j].x;
    y1=node[i].y;y2=node[j].y;
    double res;
    res=(double)sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
    return res;
}
bool cmp(Edge a,Edge b)
{
    if(a.distance==b.distance) return a.from<b.from;
    return a.distance<b.distance;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&node[i].x,&node[i].y);
    }
    //���i���㵽�������ľ��롣
    int k=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            edge[++k].from=i;
            edge[k].to=j;
            edge[k].distance=getdistance(i,j);
        }
    }
      Init();
  //  for(int i=1;i<=k;i++)cout<<"("<<node[edge[i].from].x<<","<<node[edge[i].from].y<<")��("<<node[edge[i].to].x<<","<<node[edge[i].to].y<<")�ľ�����"<<edge[i].distance<<endl;
    for(int i=1;i<=m;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        Union(p,q);
        edge[++k].from=p;
        edge[k].to=q;
        edge[k].distance=0;
    }
  
    double res=0;
    sort(edge+1,edge+1+k,cmp);
   // for(int i=1;i<=k;i++)cout<<"("<<node[edge[i].from].x<<","<<node[edge[i].from].y<<")��("<<node[edge[i].to].x<<","<<node[edge[i].to].y<<")�ľ�����"<<edge[i].distance<<endl;
    for(int i=1;i<=k;i++)
    {
        int a=edge[i].from,b=edge[i].to;
        int roota=find(a),rootb=find(b);
        if(roota!=rootb)
        {
          //  cout<<"��ǰ�ڵ�Ϊ("<<node[a].x<<","<<node[a].y<<")��("<<node[b].x<<","<<node[b].y<<")�ľ���Ϊ"<<edge[i].distance<<endl;
            res+=edge[i].distance;
            f[roota]=rootb;
        }
    }
    //cout<<endl;
    printf("%.2lf",res);
}

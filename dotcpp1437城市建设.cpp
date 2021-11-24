#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N =  1000001; //码头后面还要加边，设置大一点
struct edge{
    int x,y;
    int w;
    bool operator<(const edge &a)
    {
        return w<a.w;
    }
}e[N];
int f[N];
void Init()
{
    for(int i=1;i<N;i++)
        f[i] = i;
}
int find(int x)
{
    if(x==f[x]) return x;
    return f[x] = find(f[x]);
}
void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    f[a]=b;
}
int main()
{
    Init();
    int n,m;
    cin>>n>>m;
    int res=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
    }
    for(int i=1;i<=n;i++)
    {
        int temp;
        scanf("%d",&temp);
        if(temp!=-1)
        {
            e[++m].x=0;
            e[m].y=i;
            e[m].w=temp;
        }
    }
    sort(e+1,e+1+m);
    vector<int> G;
    for(int i=1;i<=m;i++)
    {
        int a=e[i].x,b=e[i].y;
        int roota=find(a),rootb=find(b);
        if(roota!=rootb||e[i].w<=0)
        {
            if(a==0)  G.push_back(i);
            res+=e[i].w;
            Union(roota,rootb);
        }
    }
    if(G.size()==1) res-=e[G[0]].w;
    cout<<res;
}
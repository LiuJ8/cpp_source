/*
��С������һ����ƿ����������ƿ����������һ������С��������
һ��ͼ��n����������ÿ������������һ�����ľ��롣
ƿ��������������С������
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 20001;
int n,s,t,m;
struct edge{
    int u,v,w;
    bool operator<(const edge &a)const {
        return w<a.w;
    }
}e[N];
int f[N];
int find(int x)
{
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
void Init()
{
    for(int i=1;i<N;i++)
        f[i]=i;
}
void kruscal(){
    Init();
    int i=1,j=1;
    int res=-1;
    while(i<n)
    {
        int u=e[j].u,v=e[j].v;
        if(find(u)!=find(v))    
        {
            i++;
            f[find(u)]=find(v);
            if(find(s)==find(t)) {cout<<e[j].w;break;}
        }
        j++;
    }
}
int main()
{
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e+1,e+1+m);
    kruscal();
}
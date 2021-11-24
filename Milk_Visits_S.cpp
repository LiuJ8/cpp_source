#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5+1;
int f[N];//f[i]是i的父亲结点
char a[N];//接收字符串的
int res[N];//最后的结果
int n,m;
void Init()
{
    for(int i=1;i<=n;i++)
        f[i]=i;
}
int find(int x)
{
    if(x==f[x])return x;
    return f[x]=find(f[x]);
}
void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    f[a]=b;
}
int main()
{
    cin>>n>>m;
    Init();
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(a[x]==a[y])
            Union(x,y);
    }
    int x,y;char c;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>c;
        if(a[x]==a[y]&&c!=a[x])
            res[i]=0;
        else res[i]=1;;
    }
    for(int i=1;i<=m;i++)
    cout<<res[i];
}
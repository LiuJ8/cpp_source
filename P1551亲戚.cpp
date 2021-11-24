#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e4+1;
int f[N];//f[i]表示i的父结点而不是祖先节点
void Init(int n)
{
    for(int i=1;i<=n;i++)
        f[i]=i;
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
    int n,m,p;
    cin>>n>>m>>p;
    Init(n);
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        Union(x,y);
    }
    while(p--)
    {
        int x,y;cin>>x>>y;
        if(find(x)==find(y))
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
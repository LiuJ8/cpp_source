#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e4+1;
int f[N];//f[i]表示i的父结点而不是祖先节点
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
    int n,m;
    int x,y,z;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        f[i]=i;
    while(m--)
    {
        cin>>x>>y>>z;
        if(x==1)
            Union(y,z);
        else{
            cout<<((find(y)==find(z))?"Y":"N")<<endl;
        }
    }
}
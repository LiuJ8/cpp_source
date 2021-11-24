#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 20000;
int f[N];
void Init()
{
    for(int i=1;i<N;i++)
        f[i]=i;
}
int findstep(int x,int step)
{
    if(x==f[x])
        return step;
    return findstep(f[x],step+1);
}
int find(int x)
{
    if(x==f[x]) return x;
    return find(f[x]);
}
void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    f[a]=b;
}
int main()
{
    int n;
    while((scanf("%d",&n))!=EOF)
    {
        Init();
        int a,b;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            Union(a,b);
        }
        a=findstep(1,0);
        b=findstep(2,0);
        if(a<b)
            cout<<"You are my younger"<<endl;
        else if(a>b)
            cout<<"You are my elder"<<endl;
        else cout<<"You are my brother"<<endl;
    }
}
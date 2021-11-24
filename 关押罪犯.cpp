#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100001;
struct node
{
    int x,y,z;
};
node a[N];
int f[N];
void Init()
{
    for(int i=1;i<=N;i++)
        f[i] = i;
}
int find(int x)
{
    if(x==f[x]) return x;
    return f[x] = find(f[x]);
}
void Union(int a,int b)
{
    a=find(a);b=find(b);
    f[a]=b;
}
int b[N];//b[i]表示i的敌人
bool cmp(node a,node b)
{
    return a.z>b.z;
}
int main()
{
    int n,m;
    Init();
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    sort(a+1,a+1+m,cmp);
    int i;
    for(i=1;i<=m;i++)
    {
        if(find(a[i].x)==find(a[i].y))
        {
            printf("%d",a[i].z);break;
        }
        //不相等，就设置敌人，设置敌人的敌人好了
        if(!b[a[i].x]) //如果a[i].x没有敌人，需要为他设置敌人
            b[a[i].x]=a[i].y;
        //如果有敌人，就把这个人的敌人设置为另一个人的朋友
        else  Union(a[i].y,b[a[i].x]);
        if(!b[a[i].y])
            b[a[i].y]=a[i].x;
        else Union(a[i].x,b[a[i].y]);
        //还需要设置敌人的敌人。
    }
    if(i>m)
     cout<<"0"; 
}
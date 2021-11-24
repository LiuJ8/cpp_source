#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100005;
int f[40005];
struct node{
    int x,y,z;
};
node a[N];
void Init()
{
    for(int i=1;i<=40004;i++)
        f[i]=i;
}
int find(int x)
{
    if(x==f[x]) return x;
    return f[x] = find(f[x]);
}
void Union(int a,int b)
{
    int x=find(a);
    int y=find(b);
    f[x]=y;
}
bool cmp(node a,node b)
{
    return a.z>b.z;//按照怒气值降序排序。
    //要先让最大的怒气值双方，不能让他们在一起
}

int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    Init();
    for(int i=1;i<=m;i++)
    {
       scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    }
    sort(a+1,a+1+m,cmp);
    int i;
    for(i=1;i<=m;i++)
    {
        if(find(a[i].x)==find(a[i].y))
        {
            cout<<a[i].z;break;
        }
        else {
            //如果两个人祖先不同，说明是敌人，加起来。
            //合并的时候合并两次。因为不知道下次来的是谁的敌人
            /* 12 23是敌人，下次不知道来的是1的敌人还是3的敌人，但是都得变成朋友。*/
            Union(a[i].x,a[i].y+n);
            Union(a[i].y,a[i].x+n);
        }
    }
    if(i>m) cout<<"0";
}
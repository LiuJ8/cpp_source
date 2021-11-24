#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 10005;
int n;
struct  node
{
    int id,cnt;
    double num,area;
    /* data */
}a[MAXN],ans[MAXN];
void Init()
{
    for(int i=0;i<MAXN;i++)
    {
        a[i].id=i; a[i].cnt=0;
        a[i].num=a[i].area=0.0;
    }
}
int Find(int x)
{
    if(a[x].id==x) return x;
    a[x].id=Find(a[x].id);
    return a[x].id;
}
void Union(int x,int y)
{
    int root1=min(Find(x),Find(y)),root2=max(Find(x),Find(y));
    if(root1!=root2)
    {
        a[root1].cnt+=a[root2].cnt;
        a[root1].num+=a[root2].num;
        a[root1].area+=a[root2].area;
        a[root2].id=root1;
    }
}
bool cmp(node a,node b)
{
    if(a.area/a.cnt!=b.area/b.cnt)
        return a.area/a.cnt>b.area/b.cnt;
    return a.id<b.id;
}
int main()
{
    Init();
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int id,father,mather,k,child,num,area;
        cin>>id>>father>>mather>>k;
        if(a[id].cnt==0) a[id].cnt=1;
        if(father!=-1)
        {
            if(a[father].cnt==0) a[father].cnt=1;
            Union(id,father);
        }
        if(mather!=-1)
        {
            if(a[mather].cnt==0) a[mather].cnt=1;
            Union(id,mather);
        }
        while(k--)
        {
            cin>>child;
            if(a[child].cnt==0) a[child].cnt=1;
            Union(id,child);
        }
        cin>>num>>area;
        a[Find(id)].area+=area;
        a[Find(id)].num+=num;
    }
    int cnt=0;
    for(int i=0;i<MAXN;i++)
    {
        if(a[i].id==i&&a[i].cnt!=0)
            ans[cnt++]=a[i];
    }
    sort(ans,ans+cnt,cmp);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
    {
        printf("%04d %d",ans[i].id,ans[i].cnt);
        printf(" %.3lf %.3lf\n",ans[i].num/ans[i].cnt,ans[i].area/ans[i].cnt);
    }
}
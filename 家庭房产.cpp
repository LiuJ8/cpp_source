#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10001;
struct  node
{
    /* data */
    int parent,total;
    double fang,area;
}person[N],ans[N];
void Init()
{
    for(int i=1;i<=N;i++)
    {
        person[i].parent=i; person[i].total=0;
        person[i].fang=person[i].area=0;
    }
}
int find(int x)
{
    if(x==person[x].parent)
        return x;
    return person[x].parent=find(person[x].parent);
}
void Union(int a,int b)
{
    a=find(a);b=find(b);
    int root1=max(a,b),root2=min(a,b);
    if(root1!=root2)
    {
        person[root1].parent=root2;
        person[root2].total+=person[root1].total;
        person[root2].fang+=person[root1].fang;
        person[root2].area+=person[root2].area;
    }
}
bool cmp(node a,node b)
{
    double p1=a.area/a.total;
    double p2=b.area/b.total;
    if(p1!=p2)
        return p1>p2;
    return (p1==p2)&&a.parent<b.parent;
}
int main()
{
    Init();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int me,fa,ma,k;
        cin>>me>>fa>>ma>>k;
        if(person[me].total==0)
            person[me].total=1;
        if(fa!=-1)
        {
            if(person[fa].total==0)
                person[fa].total=1;
            Union(me,fa);
        }
        if(ma!=-1)
        {
            if(person[ma].total==0)
                person[ma].total=1;
            Union(me,ma);
        }
        while(k--)
        {
            int child;cin>>child;
            if(person[child].total==0)
                person[child].total==1;
            Union(me,child);
        }
        int fang,area;
        cin>>fang>>area;
        person[find(me)].fang+=fang;
        person[find(me)].area+=area;
    }
    int s=0;
    for(int i=1;i<=N;i++)
    {
        if(i==person[i].parent&&person[i].total!=0){
            ans[++s]=person[i];
        }
    }
    sort(ans+1,ans+1+s,cmp);
    for(int i=1;i<=s;i++)
    {
        printf("%04d %d ",ans[i].parent,ans[i].total);
        printf("%.3lf %.3lf\n",ans[i].fang/ans[i].total,ans[i].area/ans[i].total);
    }
}
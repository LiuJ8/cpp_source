#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100000;
typedef struct nod{
    int l,r;
}node;
node a[N];
bool cmp(node a,node b)
{
    if(a.r!=b.r)
        return a.r>b.r;
    return a.l>b.l;
}
int main()
{
    int n;
    cin>>n;
    int x,y,p,q;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        p=max(x,y);
        q=min(x,y);
        a[i].l=q;
        a[i].r=p;
    }
    sort(a+1,a+1+n,cmp);
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(a[i+1].r>=a[i].l)
            res++;
    }
    cout<<res;
}

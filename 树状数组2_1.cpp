#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 500001;
long long int d[N],a[N]; //d[]表示差分数组，树状数组。a[]表示一开始输入的数组
int n,m;
int lowbit(int i)
{
    return i&(-i);
}
void add(int x,int k)
{
    for(int i=x;i<=n;i+=lowbit(i))
        d[i]+=k;
}
void range_add(int x,int y,int k)
{
    add(x,k);add(y+1,-k);
}
long long int query(int x)
{
    long long int res=0;
    for(int i=x;i>=1;i-=lowbit(i))
        res+=d[i];
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    while(m--)
    {
        int t;
        long long int x,y,k;
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%lld%lld%lld",&x,&y,&k);
            range_add(x,y,k);
        }
        else{
            scanf("%lld",&x);
            printf("%lld\n",query(x)+a[x]);
        }
    }
}
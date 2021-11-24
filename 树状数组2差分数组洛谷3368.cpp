#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 500001;
long long int tree[N],b[N],a[N];
    int n,m;
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int k)
{
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i]+=k;
}
long long int query(int x)
{
    long long int res=0;
    for(int i=x;i>=1;i-=lowbit(i))
        res+=tree[i];
    return res;
}
int main()
{

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
     {  
        scanf("%lld",&b[i]);
        a[i]=b[i]-b[i-1];
        add(i,a[i]);
     }
    int mod;
    long long int x,y,k;
    while(m--)
    {
        scanf("%d",&mod);
        if(mod==1)
        {
            scanf("%lld%lld%lld",&x,&y,&k);
            add(x,k);
            add(y+1,-k);
        }
        if(mod==2)
        {
            scanf("%d",&x);
            printf("%lld\n",query(x));
        }
    }
}
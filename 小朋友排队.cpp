#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1000001;
typedef long long int ll;
ll tree[N];
ll a[N],re[N];
ll res[N];
int n;
ll m=0;
int lowbit(int x)
{
    return x&-x;
}
void add(int x)
{
    for(int i=x;i<=m+1;i+=lowbit(i))
        tree[i]+=1;
}
ll query(int x)
{
    ll re=0;
    for(int i=x;i>=1;i-=lowbit(i))
        re+=tree[i];
    return re;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        m=max(m,++a[i]);    //后面要询问a[i] - 1 
    }
    for(int i=1;i<=n;i++)
    {
        add(a[i]);
        res[i]=i-query(a[i]);//逆序对数，前面多少个比它大的
    }
    //for(int i=1;i<=n;i++) cout<<res[i]<<" ";cout<<endl;
    memset(tree,0,sizeof(tree));
    for(int i=n;i>=1;i--)
    {
        add(a[i]);
      //  cout<<query(a[i]-1)<<" ";
        res[i]+=query(a[i]-1);
    }
    //for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=(res[i]+1)*res[i]/2;
    }
    cout<<sum;
}

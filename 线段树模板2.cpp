#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const long long int N = 200010;
typedef long long int ll;
ll p;

struct node{
    long long int l,r;
    long long int mlz;//乘法懒标记
    long long int plz;//加法懒标记
    long long int sum;
}tree[N];
long long int a[N];
void Build(ll i,ll l,ll r)
{
    tree[i].l=l;
    tree[i].r=r;
    tree[i].mlz=1;
    if(l==r)
    {
        tree[i].sum=a[l]%p;
        return;
    }
    long long int mid=(l+r)/2;
    Build(2*i,l,mid);
    Build(2*i+1,mid+1,r);
    tree[i].sum=(tree[2*i].sum+tree[2*i+1].sum)%p;
}
void pushdown(ll i)
{
    long long int k1 = tree[i].mlz;
    long long int k2 = tree[i].plz;
    //乘的传递：上一层的乘的乘这一层的sum + 上一层的加的乘这一层的长度
    tree[2*i].sum=(ll)(tree[2*i].sum*k1 + (tree[2*i].r-tree[2*i].l+1)*k2)%p;
    tree[2*i+1].sum=(ll)(tree[2*i+1].sum*k1 + (tree[2*i+1].r-tree[2*i+1].l+1)*k2)%p;
    tree[2*i].mlz=(ll)(tree[2*i].mlz*k1)%p;
    tree[2*i+1].mlz=(ll)(tree[2*i+1].mlz*k1)%p;
    tree[2*i].plz=(ll)(tree[2*i].plz*k1+k2)%p;
    tree[2*i+1].plz=(ll)(tree[2*i+1].plz*k1+k2)%p;
    tree[i].plz=0;
    tree[i].mlz=1;
}
void add1(ll i,ll l,ll r,ll k) //将[l,r]区间的每个数加k
{
    if(tree[i].l>=l&&tree[i].r<=r)//区间完全包含
    {
        tree[i].sum=(ll)(tree[i].sum+k*(tree[i].r-tree[i].l+1))%p;
        tree[i].plz=(ll)(tree[i].plz+k)%p;
        return;
    }
    //区间没有完全包含，则先下传lz
    pushdown(i);
    if(l<=tree[2*i].r)
        add1(2*i,l,r,k);
    if(r>=tree[2*i+1].l)    
        add1(2*i+1,l,r,k);
    tree[i].sum=(tree[2*i].sum+tree[2*i+1].sum)%p;
}
void add2(ll i,ll l,ll r,ll k)//[l,r]区间内每个数都乘k
{
    //区间完全包含将值乘k
    if(tree[i].l>=l&&r>=tree[i].r)
    {
        tree[i].sum=(tree[i].sum*k)%p;
        tree[i].mlz=(tree[i].mlz*k)%p;
        tree[i].plz=(tree[i].plz*k)%p;
        return;
    }
    //区间未完全包含先下穿懒标记
    pushdown(i);
    if(tree[2*i].r>=l)
        add2(2*i,l,r,k);
    if(tree[2*i+1].l<=r)
        add2(2*i+1,l,r,k);
    tree[i].sum=(tree[2*i].sum+tree[2*i+1].sum)%p;
}
ll query(ll i,ll l,ll r)
{
    if(tree[i].l>=l&&r>=tree[i].r)
    {
        return tree[i].sum;
    }
    //查询的时候也需要下穿懒标记
    pushdown(i);
    long long int res=0;
    if(tree[2*i].r>=l)
        res=(res+query(2*i,l,r))%p;
    if(tree[2*i+1].l<=r)
        res=(res+query(2*i+1,l,r))%p;
    return res;
}
int main()
{
    
    ll n,m;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    Build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        ll mod,x,y,k;
        scanf("%lld",&mod);
        if(mod==1)
        {
            scanf("%lld%lld%lld",&x,&y,&k);
                add2(1,x,y,k);
        }
        if(mod==2)
        {
            scanf("%lld%lld%lld",&x,&y,&k);
                add1(1,x,y,k);
        }
        if(mod==3)
        {
            scanf("%lld%lld",&x,&y);
                cout<<query(1,x,y)<<endl;
        }
    }
}
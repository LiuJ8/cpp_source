#include<iostream>
#include<cstring>
#include<algorithm>
//AC了！！哭了
using namespace std;
const int N = 4000000;
typedef long long int ll;
typedef struct {
    int l,r;
   long long int lazy;
    long long int sum;
}tre;
tre tree[N];
long long int a[N];
void build(ll i,ll l,ll r)
{
    tree[i].l=l;
    tree[i].r=r;
    if(l==r)
    {
      tree[i].sum=a[l];
      return;
    }
    int mid=(l+r)/2;
    build(2*i,l,mid);
    build(2*i+1,mid+1,r);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;

}
//区间修改
/*如果当前区间在[l,r]内，则tree[i].sum+=k*(tree[i].r-tree[i].l+1);并且标上懒标记
    如果当前区间没被完全覆盖，则下传懒标记
    如果左区间部分覆盖，找之
    如果右区间部分覆盖，找之。
    */
//下移懒标记
void push_down(int i)
{
    if(tree[i].lazy!=0) 
    {
        tree[2*i].lazy+=tree[i].lazy;
        tree[2*i+1].lazy+=tree[i].lazy;
        int mid=(tree[i].l+tree[i].r)/2;
        tree[2*i].sum+=tree[i].lazy*(mid-tree[2*i].l+1);
        tree[2*i+1].sum+=tree[i].lazy*(tree[2*i+1].r-mid-1+1);
        tree[i].lazy=0;
        return;
    } 
}
void add(int i,int l,int r,int k)//k是区间上加几
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].sum+=k*(tree[i].r-tree[i].l+1);
        tree[i].lazy+=k;
        return;
    }
    push_down(i);//如果区间未全覆盖，懒标记下移
    int mid=(l+r)/2;
    if(tree[2*i].r>=l)
        add(2*i,l,r,k);
    if(tree[2*i+1].l<=r)
        add(2*i+1,l,r,k);
    tree[i].sum=tree[2*i].sum+tree[2*i+1].sum;
    return;    
}
long long int search(int i,int l,int r)
{
    if(tree[i].l>=l&&tree[i].r<=r)
        return tree[i].sum;
    if(tree[i].r<l||tree[i].l>r) return 0;
    push_down(i);//传递懒标记
    long long int s=0;
    if(tree[i*2].r>=l) 
        s+=search(2*i,l,r);
    if(tree[2*i+1].l<=r)
        s+=search(2*i+1,l,r);
    return s;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    int t;
    while(m--)
    {
        cin>>t;
    if(t==1){
        int x,y,k;
        cin>>x>>y>>k;
        add(1,x,y,k);
    }
    if(t==2)
    {
        int x,y;
        cin>>x>>y;
        cout<<search(1,x,y)<<endl;
    }
    }
}
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100001;
int a[N],tree[N],res[N];
int n;
struct node{
    int data;
    int index;
}b[N];
bool cmp(node a,node b)
{
    if(a.data==b.data)
        return a.index<b.index;
    return a.data<b.data;
}
int lowbit(int x)
{
    return x&-x;
}
void add(int x)
{
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i]++;
}
int query(int x)
{
    int res=0;
    for(int i=x;i>=1;i-=lowbit(i))
        res+=tree[i];
    return res;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i].data);
        b[i].index=i;
    }
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++)
        a[b[i].index]=i;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        add(a[i]);
       // cout<<i<<" "<<a[i]<<" "<<query(a[i])<<endl;
        //for(int j=1;j<=n;j++)
         //   cout<<tree[j]<<" ";cout<<endl;
        if(i==a[i]&&i==query(a[i]))
            {
                res[++sum]=b[i].data;
            }
    }
    cout<<sum<<endl;
    if(!sum) cout<<endl;
    else
    {
        for(int i=1;i<=sum;i++)
            printf("%d ",res[i]);
    }
}
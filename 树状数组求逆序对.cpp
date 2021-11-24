#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 500001;
int tree[N],b[N];
    struct node{
        int data;
        int index;
    }a[N];
bool cmp(node a,node b)
{
    if(a.data==b.data)
        return a.index>b.index;
    return a.data>b.data;
}
int n;
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
            scanf("%d",&a[i].data);
           a[i].index=i;
        }
    sort(a+1,a+1+n,cmp);
    long long int res=0;    //一开始没有long long AC 不了
    for(int i=1;i<=n;i++)
        b[a[i].index]=i;
    for(int i=1;i<=n;i++)
    {
        add(b[i]);   
        res+=query(b[i]-1);//数小的，是第i大的，反而是大的。
      //  for(int j=1;j<=n;j++)
          //      cout<<tree[j]<<" ";cout<<endl;
    }
    cout<<res;
}
/*
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 500001;
int tree[N];
struct node{
    int data;
    int index;
}a[N];
bool cmp(node a,node b)
{
    if(a.data==b.data)
        return a.index>b.index;
    return a.data>b.data;
}
int n;
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
        scanf("%d",&a[i].data);
        a[i].index=i;
    }
    sort(a+1,a+1+n,cmp);
    long long int res=0;    //一开始没有long long AC 不了
    for(int i=1;i<=n;i++)
    {
        add(a[i].index);
            res+=query(a[i].index-1);
    }
    cout<<res;
}
*/
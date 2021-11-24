#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100001;

int tree[N];
int a[N];//å»é‡åçš„ç¦»æ•£åŒ?
int res[N];
int n;
struct nod{
    int data;
    int index;
}node[N];
int lowbit(int i)
{
    return i&-i;
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
    cout<<"1~"<<x<<"µÄºÍÊÇ"<<res<<endl;
    return res;
}
bool cmp(nod a,nod b)
{
    return a.data<b.data;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&node[i].data);
        node[i].index=i;
    }
    sort(node+1,node+1+n,cmp);
    for(int i=1;i<=n;i++)
     cout<<node[i].index;cout<<endl;
    int index=1;
    for(int i=1;i<=n;i++)
    {
        if(i!=1&&node[i].data!=node[i-1].data)
            index++;
        a[node[i].index]=index;
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++)
    {
        add(a[i]);
        res[i]+=i-query(a[i]);
    }
    for(int i=1;i<=n;i++)
        cout<<res[i]<<" ";cout<<endl;
    memset(tree,0,sizeof(tree));
    for(int i=n;i>=1;i--)
    {
        add(a[i]);
        res[i]+=query(a[i]-1);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cout<<res[i]<<" ";
        sum+=res[i]*(res[i]+1)/2;
    }
    cout<<endl;
    cout<<sum;
}
//用RMQ做求区间最值
#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
const int N = 50001;
int n;
int a[N];
int dp1[N][20],dp2[N][20];
void Init()
{
    for(int i=1;i<=n;i++)
    {
        dp1[i][0]=dp2[i][0]=a[i];
    }
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            dp1[i][j] = min(dp1[i][j-1],dp1[i+(1<<(j-1))][j-1]);
            dp2[i][j] = max(dp2[i][j-1],dp2[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r)
{
    int k=log2(r-l+1);
    int a=max(dp2[l][k],dp2[r-(1<<k)+1][k]);
    int b=min(dp1[l][k],dp1[r-(1<<k)+1][k]);
    return a-b;
}
int main()
{
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)   
        scanf("%d",&a[i]);
    Init();
    while(q--)
    {
        //cout<<"n="<<n<<endl;
        int l,r;scanf("%d %d",&l,&r);
        printf("%d\n",query(l,r));
    }
}
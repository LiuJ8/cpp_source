//用RMQ做求区间最值
#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
const int N = 500001;
int a[N];//存放原始数据
int dp1[N][17];//维护区间最小值
int dp2[N][17];//维护区间最大值
int res[N];
int n;
void Init()
{
    for(int i=1;i<=n;i++)
        dp1[i][0]=dp2[i][0]=a[i];//dp[i][0]就表示这个数本身
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
             dp1[i][j]=min(dp1[i][j-1],dp1[i+(1<<(j-1))][j-1]);
             dp2[i][j]=max(dp2[i][j-1],dp2[i+(1<<(j-1))][j-1]);
        }
}
int query_min(int l,int r)
{
    int k=log2(r-l+1);
    return min(dp1[l][k],dp1[r-(1<<k)+1][k]);
}
int query_max(int l,int r)
{
    int k=log2(r-l+1);
    return max(dp2[l][k],dp2[r-(1<<k)+1][k]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int sum=0;
    Init();
    for(int i=1;i<=n;i++)
    {
    	if(i==1)
    	{
    		if(query_min(2,n)>a[i]) res[++sum]=a[i];
		}
		else if(i==n)
		{
			if(query_max(1,n-1)<a[i]) res[++sum]=a[i];
		}
        else
        {
        	if(query_min(i+1,n)>a[i]&&query_max(1,i-1)<a[i])
            res[++sum]=a[i];
		}
    }
    cout<<sum<<endl;
    if(!sum) cout<<endl;
    else{
        for(int i=1;i<=sum;i++) cout<<res[i]<<" ";
    }
}
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1000001;
int dp[101][N];
int a[101];
int main()
{
    dp[0][0]=1;
    int n,sum=0;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
    cout<<sum<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
            dp[i][j]=dp[i-1][j]||dp[i-1][j+a[i]]||dp[i-1][abs(j-a[i])];
    }
    
    int res=0;
    for(int i=1;i<=sum;i++) if(dp[n][i]) res++;
    cout<<res;
}
/*
dfs
#include<stdio.h> 
int n;
int res;
int w[1000000]; 
bool st[100000];
void dfs(int k,int sum)//表示k个的砝码,重量是sum 
{
    if(k>n)//k>n 说明选完n个砝码 
    {
        if(sum>0&&!st[sum])// 判断选出来的n个砝码的重量是否没被标记过 ，如没标记则答案加1 
        {
            res++;
            st[sum]=true;//标记这个重量 
            return;
        }   
    }
    //还没选够n个砝码 
    else
    {
        dfs(k+1,sum-w[k]);//砝码放右边 
        dfs(k+1,sum);//跳过，不选用当前的砝码 
        dfs(k+1,sum+w[k]);//砝码放左边 
    }
}
int main()
{
    scanf("%d",&n); 
    for(int i=1;i<=n;i++)scanf("%d",&w[i]); 

    dfs(0,0);
    printf("%d",res); 
}

*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
int op[7];
int n,m,conflict[7][7];
ll dp[2][7];
void init()
{
    op[1]=4;
    op[4]=1;
    op[2]=5;
    op[5]=2;
    op[3]=6;
    op[6]=3;
}
ll mi(int a,int b)
{
    
    ll ans = 1;
    while(b>0)
    {
        if(b&1) ans=(ans%mod*a%mod)%mod;
        b>>=1;
        a=(a%mod*a%mod)%mod;
    }
    return ans;

}
int main()
{
    init();
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        conflict[x][y] = conflict[y][x] = 1;
    }
    
    for(int i=1;i<=6;i++) dp[0][i] = 1;
    int cur = 0;
    for(int level = 2;level <= n;level++)
    {
        cur = 1-cur;
        for(int  j=1;j<=6;j++)
        {
            dp[cur][j] = 0;
            for(int i=1;i<=6;i++)
            {
                if(conflict[i][op[j]]) continue;
                dp[cur][j] = (dp[cur][j]%mod + dp[1-cur][i]) %mod;
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=6;i++)
        ans = (ans + dp[cur][i])%mod;
    cout<<ans%mod*mi(4,n)%mod;
}
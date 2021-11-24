#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
int op[7];
int n,m,conflict[7][7];
void init()
{
    op[1]=4;
    op[4]=1;
    op[2]=5;
    op[5]=2;
    op[3]=6;
    op[6]=3;
}
ll f(int up,int cnt)
{
    if(cnt==0) return 1;
    ll ans = 0;
    for(int upp = 1;upp<=6;upp++)
    {
        if(conflict[op[upp]][up]) continue;
        ans = (ans+f(upp,cnt-1))%mod;
    }

    return ans;
}
//¿ìËÙÃÝ logn
ll mi(int a,int b)
{
    //a^b %mod
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
    ll ans=0;
    for(int up = 1;up<=6;up++)
    {
        ans = (ans+f(up,n-1))%mod;
    }
    cout<<mi(4,n)<<endl;
    cout<<ans*mi(4,n);
}
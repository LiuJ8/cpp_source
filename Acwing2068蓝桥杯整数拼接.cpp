#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int N = 1e5+10;
ll a[N];
ll st[11][N];//st[i][j] a[i]*10^x % m == j
int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        ll t=a[i]%m;
        for(int j=0;j<11;j++)
        {
            st[j][t] ++;
            t=10 * t % m;
        }
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        ll t=a[i]%m;
       int len=to_string(a[i]).size();
       res+=st[len][(m-t)%m];
        ll r=t;
        while(len--) r=r*10%m;
        if(r==(m-t)%m) res--;
    }
    cout<<res;
}
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
double a[N],res[N];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
    for(int i=n-1;i>=0;i--)
        res[i] = (res[i+1]+a[i+1])/2 ;
   //for(int i=0;i<=n;i++) cout<<res[i]<<" ";
   if(res[0]-(ll)res[0]==0) cout<<res[0];
   else cout<<(ll)res[0]+1; 
}


/*
O(n^2)
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long double ll;
const int N = 1e5+10;
ll a[N];
int n;
bool check(ll ans)
{
    for(int i=1;i<=n;i++)
    {
        if(ans<0) return false;
        if(ans < a[i]) ans=ans-(a[i]-ans);
        else ans=(ans+ans-a[i]);
    }
    if(ans>=0) return true;
    return false;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%llf",&a[i]);
    int ans=1;
    for(ans=1;ans<=N;ans++)
        if(check(ans)) break;
    cout<<ans;
}
*/
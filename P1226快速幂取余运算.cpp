#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll calculate(ll a,ll b,ll p)
{
    ll res=1;
    while(b>0)
    {
        if(b&1) res=(res%p*a%p)%p;//res=(res*a)%p=(res%p*a%p)%p
        b>>=1;
        a=(a%p*a%p)%p;
    }
    res%=p;
    return res;
}
int main()
{
    ll a,b,p;
    ll res;
    scanf("%lld%lld%lld",&a,&b,&p);
    res=calculate(a,b,p);
    printf("%d^%d mod %d=%d",a,b,p,res);
}
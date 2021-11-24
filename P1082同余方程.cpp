#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll x,y;
void exgcd(ll a,ll b)
{
    if(b==0)
    {
        x=1;y=0;return;
    }
    exgcd(b,a%b);
    ll temp=y;
    y=x-(a/b)*y;
    x=temp;
}
int main()
{
    int a,b;
    cin>>a>>b;
    exgcd(a,b);
    x=(x%b+b)%b;
    cout<<x;
}
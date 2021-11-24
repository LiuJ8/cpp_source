#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
const int N = 10000000+10;
int a[N];
int L,n,k;
bool check(int x) //xÊÇ¿Õ¿õÖ¸Êı
{
    int res=0;
    for(int i=1;i<n;i++)
    {
        res+=(a[i+1]-a[i])/x;
        if((a[i+1]-a[i])%x==0) --res;
        if(res>k) return true;
    }
    return false;
}
int main()
{
    cin>>L>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int l=1,r=L;
    while(l<r)
    {
        int mid=(l+r)>>1;
     //cout<<l<<" "<<r<<" "<<mid<<endl;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout<<l;
}
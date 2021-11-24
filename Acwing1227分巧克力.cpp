#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int h[N],w[N];
int n,k;
//求的是小于等于的最大
bool check(int x)
{
    int res=0;  //能分的人数太多，边长太小
    for(int i=1;i<=n;i++)
    {
        res+=(h[i]/x)*(w[i]/x); //必须先取整
        if(res >= k) return  false;
    }
    return true;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&h[i],&w[i]);
    }
    int l=1,r=1e5;//一个人分10^5*10^5，边长也是10^5最大
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid)) r=mid-1;
        else l=mid;
    }
    cout<<l;
}
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int L,n,m;
int a[N];
bool check(int x)//x：最短跳跃距离  这个距离情况下需要拿多少石头
{
    int cnt=0,last=0;//cnt表示总共需要石头个数，last表示上一个石头到原点距离
    for(int i=1;i<=n;i++)
    {
        if(a[i] - last < x) cnt++;
        else last=a[i];
        if(cnt > m) return false; //需要拿走的石头大于，最短距离大于
    }
    return true;
}
int main()
{
    cin>>L>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=0;
    a[++n]=L;
    int l=1,r=L;
    //求小于等于的最大距离 第二个模板 l=mid r=mid-1
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
}
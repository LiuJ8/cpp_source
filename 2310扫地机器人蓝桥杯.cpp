#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std; 
const int N = 1e5+10;
int n,k;
int a[N];
bool check(int x)
{
    int L = 0;
    int Q = x;
    for(int i=1;i<=k;i++)
    {
        if(L + Q < a[i]) return false;
        if(a[i] > L)
            L += Q;
        else
        {
            L=a[i] + Q -1;
        }
    }
   // cout<<"当前扫描到"<<L<<endl;
    if(L < n) return false;
    return true;
}
int main()
{
    cin>>n>>k;  //n是总长度, k是机器人个数
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+k);
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
       // cout<<l<<" "<<r<<" "<<mid<<endl;
        if(check(mid)) r=mid; // a[mid] <= target 
        else l=mid+1;
    //    cout<<2*(l-1)<<endl;
    }
    cout<<2*(l-1);
}
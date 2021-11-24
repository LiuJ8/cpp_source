#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N = 10002;
int a[N];
int main()
{
    int n,k;
    cin>>n>>k;
    int res=1;  //初始化为 1
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int temp=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]-temp>k){
            temp=a[i];
            res++;
        }
    }
    cout<<res;
}
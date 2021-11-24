#include<iostream>
using namespace std;
int n;
const int N = 1e9+7;
long long int sum=0;
long long int f[1000001];
int main()
{
    cin>>n;
    f[0]=f[1]=f[2]=f[3]=f[4]=1;
    for(int i=5;i<=n;i++)
        f[i]=(f[i-1]+f[i-5])%N;
    cout<<f[n];
}
/*
/*
//递归会溢出的。嵌套的太多了。
int fp(int x)
{
    if(x>n)
      {
            cout<<f[n]%N;
            return 0;
      }
    if(x<5)
        f[x]=1;
    else 
    {
        f[x]=(f[x-1]+f[x-5]);
        f[x]=f[x]%N;
    }
    fp(x+1);
    

}
*/
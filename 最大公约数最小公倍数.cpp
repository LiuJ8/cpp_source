#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int a,b;
    int MIN,MAX;
    scanf("%d%d",&a,&b);
    MIN=min(a,b);
    MAX=max(a,b);
    int yu1,yu2;
    yu1=MAX%MIN;
    while(yu1)
    {
        MAX=MIN;
        MIN=yu1;
        yu1=MAX%MIN;
    }
    cout<<MIN<<" ";
    cout<<a*b/MIN;
}
int gcd(int a,int b)
{
    int MIN,MAX;
    MIN=min(a,b);
    MAX=max(a,b);
    int yu1,yu2;
    yu1=MAX%MIN;
    while(yu1)
    {
        MAX=MIN;
        MIN=yu1;
        yu1=MAX%MIN;
    }
    return MIN;
}
int lcm(int a,int b)
{
    long long int res;
    res=a*b/gcd(a,b);
    return res;
}
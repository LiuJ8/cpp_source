#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e8+10;
int res[N],su[N];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) su[i]=1;
    int len=0;
    for(int i=2;i<=n;i++)
    {
        if(su[i]) res[++len]=i;
        for(int j=1;j<=len&&res[j]*i<=n;j++)
        {
            su[res[j]*i] = 0;
            if(i%res[j]==0) break;
        }
    }
    while(q--)
    {
        int k;scanf("%d",&k);
        cout<<res[k]<<endl;
    }
}
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =100001;
int a[N],vis[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        while(vis[x]!=0)
        {   
            x+=vis[x];
            vis[x]++;
        }
        a[i]=x;
        vis[x]++;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}
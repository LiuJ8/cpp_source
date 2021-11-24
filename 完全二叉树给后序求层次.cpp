#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 31;
int n;
int a[N];
void find(int root)
{
    if(root>n)
        return;
    find(2*root);
    find(2*root+1);
    cin>>a[root];
}
int main()
{
    cin>>n;
    find(1);
    for(int i=1;i<n;i++)
        cout<<a[i]<<" ";
    cout<<a[n];
}

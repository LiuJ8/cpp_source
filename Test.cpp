#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e4+10;
int a[N];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	m++;
	while(m--)
	{
		next_permutation(a+1,a+1+n);
		if(m==1)for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	}
}
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =1000011;
int f[N];
void Init()
{
   for(int i=1;i<=N;i++)
     f[i]=i;
}
int find(int x)
{
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
int main()
{
   int n;
   //Init();
   for(int i=0;i<=N;i++)
      f[i]=i;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      x=find(x);
      printf("%d ",x);
      f[x]=x+1;
   }
}
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N = 10002;
map<int,int>a;
int temp[N];
map<int,int> zhou;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&temp[i]);
    sort(temp,temp+n);
    for(int i=0;i<n;i++)
        a[i]=temp[i];
    for(int i=-10000;i<=10000;i++)
        zhou[i]=0;
   /* for(int i=0;i<n;i++)    
        printf("%d ",a[i]);
        */
    //直到所有的a[temp[i]]=1了才能输出
    int res=0;
    while(true)
    {
        //先找最小的未被访问的结点
        int i;
        for( i=0;i<n;i++)
        {
            if(!zhou[temp[i]])
                break;
        }
        if(i==n)
            break;
        for(int j=temp[i];j<=k;j++)
            zhou[j]=1;
        res++;
        
    }
    printf("%d",res);

}
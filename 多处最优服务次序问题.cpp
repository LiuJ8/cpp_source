#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10002;
int a[N];
int res[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(i<=m)
            res[i]=a[i];
        else{
            res[i]=a[i]+res[i-m];
        }
    }
    
   /* for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
        /**/
    double avg,sum;
    for(int i=1;i<=n;i++)
        sum+=(double)res[i];
        //cout<<sum<<endl;
    avg=sum/n;
    int re=(int)avg;
    if(avg-re>=0.5)printf("%d",re+1);
    else printf("%d",re);
}
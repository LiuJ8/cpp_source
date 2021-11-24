#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10002;
struct node
{
    double  T,V;
    double avg;
};
node a[N];
bool cmp(node a,node b)
{
    return a.avg>b.avg;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)&&(m||n))
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            scanf("%lf %lf",&a[i].T,&a[i].V);
            a[i].avg=a[i].V/a[i].T;
        }
        sort(a+1,a+1+n,cmp);
        double res=0;
        int i;
        for(i=1;i<=n;i++)
        {
            if(m>=a[i].T)
            {
                res+=a[i].V;
                m-=a[i].T;
            }
            else break;
        }
        //怎么说。考虑问题太不全面了。
        /*当前最有价值的还是不能做完。那就能做多少是多少
        最后那一点没有考虑好。真是，很简单一个题，非得自己不行
        人不行别怪路不平。
        */
        if(i<=n)
        {
            res+=a[i].V/a[i].T*m;
        }
        printf("%.2lf\n",res);
    }
}
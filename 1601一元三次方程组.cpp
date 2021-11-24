#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-7;    //一个很小的数
double a,b,c,d;
double f(double x)
{
    double res;
    res=a*x*x*x+b*x*x+c*x+d;
    return res;
}
/*
这里把f(x)*f(y) <=0 看成两种情况，f(x)*f(y)<0 f(x)*f(y)=0
*/
int main()
{
    cin>>a>>b>>c>>d;
    for(int i=-100;i<100;i++)   //根与根之间的差绝对值>=1,所以长度为1一定有一个解或者没有
    {
        double l=i,r=l+1;
        if(f(l)==0) printf("%.2lf\n",l);    //左端点==0单独考虑
        if(f(l)*f(r)<0)
        {   
            for(int j=1;j<=100;j++)
            {
                double mid=(l+r)/2;
                if(f(mid)*f(r)<=0)
                    l=mid;
                else r=mid;
/*
                  while(r-l>eps)
            {
                double mid=(l+r)/2;
                if(f(mid)*f(r)<=0)
                    l=mid;
                else r=mid;
            }
            printf("%.2lf ",l);
*/
            }
            printf("%.2lf ",l); //输出l r都行,二者差<10^-7
        }
    }
}
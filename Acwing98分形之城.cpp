#include<iostream>
#include<cmath>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
PLL calc(LL n,LL m)
{
    if(n==0) return {0,0};//0��ͼֻ��0һ����
    LL len=1ll<<(n-1);
    LL cnt=1ll<<2*(n-1);//n-1��ͼ����Ԫ�ظ���
    LL cnk=m / cnt;//���Ϊm��Ԫ�����ڿ�ı��
    LL idx=m % cnt;//���Ϊm��Ԫ���ڿ��ڵı��
    PLL pos = calc(n-1,idx);
    LL x=pos.x, y=pos.y;
    if(cnk==0) return{y,x};
    if(cnk==1) return{x,y+len};
    if(cnk==2) return {x+len,y+len};
    return {len*2-y-1,len-x-1};
}
int main()
{
    int T;
    LL n,a,b;
    cin>>T;
    while(T--)
    {
        cin>>n>>a>>b;
        PLL pa=calc(n,a-1);
        PLL pb=calc(n,b-1);
        double x=pa.x-pb.x, y=pa.y-pb.y;
        double dis=sqrt(x*x+y*y);
        printf("%.0lf\n",dis*10);
    }
}
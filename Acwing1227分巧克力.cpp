#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int h[N],w[N];
int n,k;
//�����С�ڵ��ڵ����
bool check(int x)
{
    int res=0;  //�ֵܷ�����̫�࣬�߳�̫С
    for(int i=1;i<=n;i++)
    {
        res+=(h[i]/x)*(w[i]/x); //������ȡ��
        if(res >= k) return  false;
    }
    return true;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&h[i],&w[i]);
    }
    int l=1,r=1e5;//һ���˷�10^5*10^5���߳�Ҳ��10^5���
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid)) r=mid-1;
        else l=mid;
    }
    cout<<l;
}
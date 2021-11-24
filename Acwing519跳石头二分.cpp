#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int L,n,m;
int a[N];
bool check(int x)//x�������Ծ����  ��������������Ҫ�ö���ʯͷ
{
    int cnt=0,last=0;//cnt��ʾ�ܹ���Ҫʯͷ������last��ʾ��һ��ʯͷ��ԭ�����
    for(int i=1;i<=n;i++)
    {
        if(a[i] - last < x) cnt++;
        else last=a[i];
        if(cnt > m) return false; //��Ҫ���ߵ�ʯͷ���ڣ���̾������
    }
    return true;
}
int main()
{
    cin>>L>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=0;
    a[++n]=L;
    int l=1,r=L;
    //��С�ڵ��ڵ������� �ڶ���ģ�� l=mid r=mid-1
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
}
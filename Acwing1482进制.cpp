/*
�ҵ�����С�Ĵ�,�����Ҵ��ڵ��ڷ��������Ķ����Ǵ��ڷ���������
�ڷ����ʱ��,�Ϳ���ô�ֵľͿ�����������
while(l<r)
{
    mid=l+r>>1;
    if(a[mid] >= target) r=mid;
    else l=mid+1;
    ѭ��������������l==r,����return  l,r��һ��,���Ǵ��ڵ���target���±�
}
------------------------------------
while(l<r)
{
    mid=l+r>>1;
    if(a[mid] > target) r=mid;
    else l=mid+1;
    ѭ������������Ҳ��l==r,����return l,r��һ��,���Ǵ���target���±�
}
------------------------------------
while(l<r)
{
    mid=l+r>>1;
    if(a[mid] <= target) l=mid+1;
    else r=mid;
    ѭ������������Ҳ��l==r,����return l,r��һ�������Ǵ���target���±�
}
------------------------------------
while(l<r)
{
    mid=l+r>>1;
    if(a[mid] < target) l=mid+1;
    else r=mid;
    ѭ����������������l==r,����return l,r��һ��,���Ǵ��ڵ���target���±�
}
------------------------------------
while(l<=r)
{
    mid=l+r>>1;
    if(a[mid] >= target) r=mid-1;
    else l=mid+1;
    ѭ��������������l>r,���������ǰѴ��ڵ���target�ķ�Ϊһ��,r����һ���ǰ��һ��(r=mid-1)
     return r��С��target
    ��return l�Ǵ��ڵ���target��λ��
}
   
--------------------------------------
while(l<=r)
{
    mid=l+r>>1;
    if(a[mid] > target) r=mid-1;
    else l=mid+1;
    ѭ��������������l>r,���������ǰѴ���target�ķ�Ϊһ��,
    return l�Ǵ���target
    return r��С�ڵ���target
}
--------------------------------------
while(l<=r)
{   
    mid=l+r>>1;
    if(a[mid] <=target) l=mid+1;
    else r=mid-1;
    ѭ��������������l>r;�ǰ�С�ڵ��ڷ�Ϊһ��
    return l�Ǵ���target
    return r��С�ڵ���target
}
---------------------------------------
while(l<=r)
{
    mid=l+r>>1;
    if(a[mid] < target) l=mid+1;
    else r=mid+1;
    ѭ����������������l<r,�ǽ�С��target�ķ�Ϊһ��
    return l�Ƿ��ش��ڵ���target
    return r�Ƿ���С��target
}
--------------------------------------------
--------------------------------------------
while(l<=r) �˳���������l>r,l���ұ�r�����,�����ȺŵĻ�,return l���Ǵ��ڵ�,return r����С�ڵ�
--------------------------------------------
--------------------------------------------
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int ll;
string a,b;
int get(char a)
{
    if(a>='0'&&a<='9') return a-'0';
    return a-'a'+10;
}
ll calculate(string a,ll radix) //radix����,�㷨���ؾ����㷨
{
    ll res=0;
    for(int i=0;i<a.length();i++)
    {
        if((double)res*radix+get(a[i])>1e16) return 1e18; //����һ���ܴ���� double������ֻ����res*radix�Ų������
        res=res*radix+get(a[i]);
    }
    return res;
}
int main()
{
    int tag,radix;
    cin>>a>>b>>tag>>radix;
    string c;
    c=tag==1?a:b;
    ll res=calculate(c,radix);
    string d=tag==1?b:a; //d��Ҫ�������
    ll l=0,r=res+1;
    for(int i=0;i<d.length();i++)
    {
        l=max(l,(ll)get(d[i])+1);
    }
    cout<<l<<" "<<r<<endl;
    while(l<r)
    {
        ll mid=l+r >> 1;
        if(calculate(d,mid) >= res) r=mid; 
        else l=mid+1;
        cout<<l<<" "<<r<<" "<<calculate(b,mid)<<endl;
    }
    /*
      while(l<=r)
   {
       ll mid=l+r >>1;
       if(calculate(d,mid)>=res) r=mid-1;
       else l=mid+1;
   }
   if(calculate(d,l)==res) cout<<l;
   ��ʱֻ�����l, return r��������ڵ��ڵ�ǰһ��,������С��
   return l��������ڵ��ڵĵ�һ��,��ĿҪ�����������������С��,�����Ǵ��ڵ��ڵ�������С��
   */
    if(calculate(d,l)==res) cout<<l; //�������l����r������,l==r
    else cout<<"Impossible";
}

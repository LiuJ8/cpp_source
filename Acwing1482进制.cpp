/*
找的是最小的答案,所以找大于等于符合条件的而不是大于符合条件的
在分类的时候,就看怎么分的就可以区别上面
while(l<r)
{
    mid=l+r>>1;
    if(a[mid] >= target) r=mid;
    else l=mid+1;
    循环结束的条件是l==r,所以return  l,r都一样,都是大于等于target的下标
}
------------------------------------
while(l<r)
{
    mid=l+r>>1;
    if(a[mid] > target) r=mid;
    else l=mid+1;
    循环结束的条件也是l==r,所以return l,r都一样,都是大于target的下标
}
------------------------------------
while(l<r)
{
    mid=l+r>>1;
    if(a[mid] <= target) l=mid+1;
    else r=mid;
    循环结束的条件也是l==r,所以return l,r都一样，都是大于target的下标
}
------------------------------------
while(l<r)
{
    mid=l+r>>1;
    if(a[mid] < target) l=mid+1;
    else r=mid;
    循环结束的条件还是l==r,所以return l,r都一样,都是大于等于target的下标
}
------------------------------------
while(l<=r)
{
    mid=l+r>>1;
    if(a[mid] >= target) r=mid-1;
    else l=mid+1;
    循环结束的条件是l>r,分类条件是把大于等于target的分为一类,r在这一类的前面一个(r=mid-1)
     return r是小于target
    而return l是大于等于target的位置
}
   
--------------------------------------
while(l<=r)
{
    mid=l+r>>1;
    if(a[mid] > target) r=mid-1;
    else l=mid+1;
    循环结束的条件是l>r,分类条件是把大于target的分为一类,
    return l是大于target
    return r是小于等于target
}
--------------------------------------
while(l<=r)
{   
    mid=l+r>>1;
    if(a[mid] <=target) l=mid+1;
    else r=mid-1;
    循环结束的条件是l>r;是把小于等于分为一类
    return l是大于target
    return r是小于等于target
}
---------------------------------------
while(l<=r)
{
    mid=l+r>>1;
    if(a[mid] < target) l=mid+1;
    else r=mid+1;
    循环结束的条件还是l<r,是将小于target的分为一类
    return l是返回大于等于target
    return r是返回小于target
}
--------------------------------------------
--------------------------------------------
while(l<=r) 退出的条件是l>r,l在右边r在左边,不看等号的话,return l都是大于的,return r都是小于的
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
ll calculate(string a,ll radix) //radix进制,算法是秦九昭算法
{
    ll res=0;
    for(int i=0;i<a.length();i++)
    {
        if((double)res*radix+get(a[i])>1e16) return 1e18; //返回一个很大的数 double的括号只包含res*radix才不会溢出
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
    string d=tag==1?b:a; //d是要计算的数
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
   这时只能输出l, return r是满足大于等于的前一个,所以是小于
   return l是满足大于等于的第一个,题目要求输出满足条件的最小的,所以是大于等于的里面最小的
   */
    if(calculate(d,l)==res) cout<<l; //计算输出l或者r都可以,l==r
    else cout<<"Impossible";
}

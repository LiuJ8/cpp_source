/*
https://www.acwing.com/solution/content/60330/  没看懂的解法
*/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int ll;
int n;
ll C(int a,int b)
{
    int i,j;
    i=a;j=b;
    ll res=1;    //写成 ll
    for(int i=a,j=1;j<=b;i--,j++) //j从1开始。精度问题
      {
            res=res*i/j;
      }
    return res;
}
int main()
{
    
    cin>>n;
    for(int i=16;i>=0;i--)
    {
        int l=2*i,r=n; //为什么左端点是2i，右端点是n？？？？？？
        int mid; 
        /*
        二分二分二分！！！ 不会。
          int l = 2 * k, r = max(n, l);
          int mid=r;
          while(l < r){
              mid = l + r >> 1;
              if(C(mid, k) >= n) r = mid;
              else  if(C(mid,k)<n) l = mid + 1;
            }
          if(C(r, k) != n) return false;
          // C(r, k)的从0开始的顺序！
         cout << 1ll * (r + 1) * r / 2 + k + 1 << endl;
        */
        while(l<=r)
        {
            mid=l+r>>1;//不用加括号，移位优先级小于加减优先级
            if(C(mid,i) > n) r=mid-1;
            else  if(C(mid,i)<n) l=mid+1;
            else break;
        }
        if(C(mid,i)==n) {cout<<1ll*(mid+1)*mid/2+i+1;break;}
    }
}

/*
#include <cstdio>
long long a[105555][20];
void result(int x,int y){
    printf("%lld\n",1ll*x*(x+1)/2+y+1);
}
int main(){
    int n;sca   nf("%d",&n);
    a[0][0]=1;
    if(n==1){
        puts("1");return 0;
    }
    for (int i = 1; i <= 20000; i ++ ){
        a[i][0]=1;for(int j=1;j<=18;j++){
            a[i][j]=a[i-1][j-1]+a[i-1][j];
            if(a[i][j]==n){
                result(i,j);return 0;
            }
        }
    }
    result(n,1);return 0;
}
*/
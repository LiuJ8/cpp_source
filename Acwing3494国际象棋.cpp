#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 110,M=1<<6,K=21,mod=1e9+7;
int f[N][M][M][K];
int n,m,k;
int get(int x)
{
    //求二进制中1的个数
    int res=0;
    while(x)
    {
        res++; 
        x-=x&-x;//x&-x取最低位的1
    }
    return res;
}
/*
c
a
b
*/

int main()
{
    cin>>n>>m>>k;
    //初始状态
    f[0][0][0][0] = 1;
    for(int i=1;i<=m;i++) //循环枚举列
        for(int a=0; a< 1 << n;a++) //字母a和下一行的b可以互换
            for(int b=0;b < 1 << n;b++)
            {
                if(b&(a<<2) || a&(b<<2)) continue;
                for(int c=0;c< 1<<n;c++)
                {
                    if(c&(a<<2) || a&(c<<2)) continue;  //可以不写这一句
                    if(c&(b<<1) || b&(c<<1)) continue;
                    int t=get(b);
                    for(int j=t;j<=k;j++)
                        f[i][a][b][j] = (f[i][a][b][j] + f[i-1][c][a][j-t]) % mod;
                }
            }
    //最后的答案是f[m][a][b][k]
    int  res=0;
    for(int a=0;a< 1<<n;a++)
        for(int b=0;b< 1<<n;b++)
           res=(res+ f[m][a][b][k])%mod;
    cout<<res;
}

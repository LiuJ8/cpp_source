#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
int op[7];
int n,m,conflict[7][7];
struct matrix{
    ll a[7][7];
};
matrix cMatrix;//冲突表
void init()
{
    op[1]=4;
    op[4]=1;
    op[2]=5;
    op[5]=2;
    op[3]=6;
    op[6]=3;
    for(int i=1;i<=6;i++)
        for(int j=1;j<=6;j++) cMatrix.a[i][j] = 1;
}

//矩阵的乘法
matrix cal(matrix m1,matrix m2)
{
    matrix res;
    for(int i=1;i<=6;i++) for(int j=1;j<=6;j++) res.a[i][j] = 0;
    for(int i=1;i<=6;i++)
        for(int j=1;j<=6;j++)
        {
            for(int k=1;k<=6;k++) 
            res.a[i][j] = (res.a[i][j] % mod + m1.a[i][k]*m2.a[k][j] % mod)%mod;
        }
    return res;
}
//求矩阵M的k次方
matrix mPow(matrix M,ll k)
{
    matrix res;
    for(int i=1;i<=6;i++)
        for(int j=1;j<=6;j++)
            if(i==j) res.a[i][j] = 1;   
            else res.a[i][j] = 0;

    while(k>0)
    {
        if(k&1) res=cal(res,M);
        k>>=1;
        M = cal(M,M);
    }
    return res;
}

//快速幂 logn
ll mi(ll a,ll b)
{
    //a^b %mod
    ll ans = 1;
    while(b>0)
    {
        if(b&1) ans=(ans%mod*a%mod)%mod;
        b>>=1;
        a=(a%mod*a%mod)%mod;
    }
    return ans;
}
int main()
{
    init();
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        cMatrix.a[op[x]][y] = cMatrix.a[op[y]][x] = 0;
    }
 
    matrix res = mPow(cMatrix,n-1);
        ll ans = 0;
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=6;j++)   ans=(ans %mod +res.a[i][j] % mod)%mod;
 
    } 
     ans = (ans%mod*mi(4,n)%mod)%mod;
    cout<<ans;
}
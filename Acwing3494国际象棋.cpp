#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 110,M=1<<6,K=21,mod=1e9+7;
int f[N][M][M][K];
int n,m,k;
int get(int x)
{
    //���������1�ĸ���
    int res=0;
    while(x)
    {
        res++; 
        x-=x&-x;//x&-xȡ���λ��1
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
    //��ʼ״̬
    f[0][0][0][0] = 1;
    for(int i=1;i<=m;i++) //ѭ��ö����
        for(int a=0; a< 1 << n;a++) //��ĸa����һ�е�b���Ի���
            for(int b=0;b < 1 << n;b++)
            {
                if(b&(a<<2) || a&(b<<2)) continue;
                for(int c=0;c< 1<<n;c++)
                {
                    if(c&(a<<2) || a&(c<<2)) continue;  //���Բ�д��һ��
                    if(c&(b<<1) || b&(c<<1)) continue;
                    int t=get(b);
                    for(int j=t;j<=k;j++)
                        f[i][a][b][j] = (f[i][a][b][j] + f[i-1][c][a][j-t]) % mod;
                }
            }
    //���Ĵ���f[m][a][b][k]
    int  res=0;
    for(int a=0;a< 1<<n;a++)
        for(int b=0;b< 1<<n;b++)
           res=(res+ f[m][a][b][k])%mod;
    cout<<res;
}

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define Mod 19260817
typedef long long int  ll;
ll x,y;
inline int getint()
{
    int res = 0, ch = getchar();
    while(!isdigit(ch) && ch != EOF)
        ch = getchar();
    while(isdigit(ch))
    {
        res = (res << 3) + (res << 1) + (ch - '0');
        res %= Mod;//ֱ�Ӷ�MODȡ��
        ch = getchar();
    }
    return res;
}
 
void exgcd(ll a,ll b)
{
    if(b==0)
    {
        x=1;y=0;return;
    }
    exgcd(b,a%b);
    ll temp=y;
    y=x-(a/b)*y;
    x=temp;
}
int main()
{
    ll a,b;
    a=getint(); //�ϰ�λ�����ݣ����ַ�����
    b=getint();
    a%=Mod;b%=Mod;
    if(b==0) {cout<<"Angry!";return 0;}
    //a=a/b;b=19260817;
    exgcd(b,Mod);
    x=(x % Mod + Mod) % Mod; //����x�Ǹ���
    ll res=(a % Mod * (ll)x % Mod) % Mod;
    cout<<res;
}
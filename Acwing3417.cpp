#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1000001;
int dp[101][N];
int a[101];
int main()
{
    dp[0][0]=1;
    int n,sum=0;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
    cout<<sum<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
            dp[i][j]=dp[i-1][j]||dp[i-1][j+a[i]]||dp[i-1][abs(j-a[i])];
    }
    
    int res=0;
    for(int i=1;i<=sum;i++) if(dp[n][i]) res++;
    cout<<res;
}
/*
dfs
#include<stdio.h> 
int n;
int res;
int w[1000000]; 
bool st[100000];
void dfs(int k,int sum)//��ʾk��������,������sum 
{
    if(k>n)//k>n ˵��ѡ��n������ 
    {
        if(sum>0&&!st[sum])// �ж�ѡ������n������������Ƿ�û����ǹ� ����û�����𰸼�1 
        {
            res++;
            st[sum]=true;//���������� 
            return;
        }   
    }
    //��ûѡ��n������ 
    else
    {
        dfs(k+1,sum-w[k]);//������ұ� 
        dfs(k+1,sum);//��������ѡ�õ�ǰ������ 
        dfs(k+1,sum+w[k]);//�������� 
    }
}
int main()
{
    scanf("%d",&n); 
    for(int i=1;i<=n;i++)scanf("%d",&w[i]); 

    dfs(0,0);
    printf("%d",res); 
}

*/
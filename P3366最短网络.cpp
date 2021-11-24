/*
�ö�ӡ�
1.a����Ҫ��ʼ�������ģ���ΪҪ����С�Ҳ�����0�ģ�һ��ʼ���붼������Զ��
������Ϊ0�ͻ�����Ϊû�ӽ�ȥ���Ѿ��ӽ�ȥ�ˣ���Ϊ��������a[i][j]=0,����Ϊlowcost[j]=0�ˡ�
2.memset 0x7f���У�����forѭ����
3.�������ֻ���һ������·����Ҫȥ��
4.�����2 4 455   4 2 458�����滹��������������У���Ҫ����С�ı�
trustyourself
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 6001;
int n,m;
int a[N][N];
int lowcost[N];
int closest[N];
//��a����ĳ�ʼ��
void init()
{
       for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j] = 0x7fffffff;
}
void Init()
{
    for(int i=1;i<=n;i++)
    {
        closest[i]=1;
        a[i][i]=0;
        lowcost[i]=a[1][i];
        
    }
}

int main()
{
    cin>>n>>m;
    init();
    int j,k,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&j,&k,&z);
    if(a[j][k]==0||z<a[j][k])
    {
            a[j][k]=z;
            a[k][j]=z;
    }
    }
    Init();
    int sum=0;
    int i=1;
while(i<n)
    {
        int minn=0x7fffffff,k;
        for(int j=1;j<=n;j++)
        {
            if(lowcost[j]<minn&&lowcost[j]!=0)
            {
                minn=lowcost[j];
                k=j;
            }
        }
        if(minn!=0x7fffffff)
        {
            sum+=minn;
        i++;
            lowcost[k]=0;
        }
        else{
            break;
        }
        for(int j=1;j<=n;j++)
        {
            if(lowcost[j]>a[k][j]&&a[k][j]!=0)
            {
                lowcost[j]=a[k][j];
                closest[j]=k;
            }
        }
    }
    if(i==n)
    {
        cout<<sum;
    }
    else
    {
        cout<<"orz";
    }
    
}
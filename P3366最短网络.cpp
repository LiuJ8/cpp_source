/*
好多坑。
1.a数组要初始化成最大的，因为要找最小且不等于0的，一开始距离都是无穷远，
都设置为0就会误认为没加进去的已经加进去了，因为设置了其a[i][j]=0,误认为lowcost[j]=0了。
2.memset 0x7f不行，两个for循环了
3.输入会出现环，一个点有路径，要去除
4.会出现2 4 455   4 2 458，后面还会出现这两个城市，需要用最小的边
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
//对a数组的初始化
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
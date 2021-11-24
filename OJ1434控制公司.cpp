#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 102;
int n,vis[N][N],a[N][N];
//a[i][j]<=50的才需要dfs
//如果a[i][j]大于50了，i一定控制j公司。
//不大于50，才有可能控制该公司。
void dfs(int x,int y)
{
    if(vis[x][y])
        return;
    vis[x][y] = 1;
    for(int i=1;i<=100;i++)
    {
        if(i==x) continue;
        a[x][i] += a[y][i];
        if(a[x][i]>50&&!vis[x][i])
        //如果 x 控制i 的股权>50了并且我还显示着x没控制 i
            dfs(x,i); //孩子的孩子的孩子也可能是孩子
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=z;
    }
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
        {
            if(a[i][j]<=50)
               continue;
            dfs(i,j);
        }
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            if(i==j) continue;
            if(vis[i][j])
                printf("%d %d\n",i,j);
        }
    }
}
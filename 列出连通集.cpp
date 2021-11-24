#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
//采用邻接矩阵存图
const int N = 1e3+1;
int a[N][N];
int vis[N];
int n,m;
void DFS(int step)
{
      vis[step]=1;
    printf("%d ",step);
    for(int i=0;i<n;i++)
    {
        if(a[step][i]&&!vis[i]){
          DFS(i);
        }
  }
}
void BFS(int step)
{
  queue<int>q;
  q.push(step);
  while(!q.empty())
  {
    int front=q.front();
    q.pop();
    if(!vis[front])
      printf("%d ",front);
      vis[front]=1;
    for(int i=0;i<n;i++)
    {
      if(!vis[i]&&a[front][i])
      {
        vis[i]=1;
          printf("%d ",i);
        q.push(i);
      }
    }
    
  }
}
int main()
{
  
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    a[x][y]=a[y][x]=1;
  }
  for(int i=0;i<n;i++)
  {
    if(!vis[i])
    {printf("{ ");
    
      DFS(i);
    printf("}\n");}
  }
  memset(vis,0,sizeof(vis));
  for(int i=0;i<n;i++)
  {
    if(!vis[i])
    {
      printf("{ ");
      BFS(i);
      printf("}\n");
    }
  }
}
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
vector<int>G[1000009];
int vis[1000009];
void dfs(int x)
{
    vis[x]=1;cout<<x<<" ";
    for(int i=0;i<G[x].size();i++)
    {
        if(!vis[G[x][i]])
            dfs(G[x][i]);
    }
}
void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1]=1; cout<<"1 ";
    while(!q.empty())
    {
        int front=q.front();q.pop();
        for(int i=0;i<G[front].size();i++)
            if(!vis[G[front][i]]) vis[G[front][i]]=1,q.push(G[front][i]),cout<<G[front][i]<<" ";
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
    dfs(1);
    memset(vis,0,sizeof(vis));
    cout<<endl;
     bfs();
}
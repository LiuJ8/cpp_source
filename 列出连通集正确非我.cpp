
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1e3+10;
vector<int> aa[maxn];
bool flag[maxn];
bool vis[maxn];
vector<int> dans;
vector<int> bans;
void dfs(int n)
{
    if(!aa[n].empty())
    {
        for(int i=0;i<aa[n].size();i++)
        {
           if(flag[aa[n][i]]==0)
           {
               dans.push_back(aa[n][i]);
               flag[aa[n][i]]=1;
               dfs(aa[n][i]);
           }
        }
    }
}
void bfs(int n)
{
    if(!aa[n].empty()){
    queue<int> ss;
    ss.push(n);
    while(!ss.empty())
    {
        int t=ss.front();
        ss.pop();
        for(int i=0;i<aa[t].size();i++)
        {
            if(vis[aa[t][i]]==0)
            {bans.push_back(aa[t][i]);
            vis[aa[t][i]]=1;
            ss.push(aa[t][i]);
            }
        }
    }
    }
}

int point;int edge;int x,y;
int main()
{
   cin>>point>>edge;
   while(edge--)
   {
       cin>>x>>y;
       aa[x].push_back(y);
       aa[y].push_back(x);
   }
   for(int i=0;i<point;i++)
   {
       if(!aa[i].empty())
       {
           sort(aa[i].begin(),aa[i].end());
       }
   }
   for(int i=0;i<point;i++)
   {
       dans.clear();
       if(flag[i]==0)
       {
           flag[i]=1;
           dans.push_back(i);
           dfs(i);
           cout<<"{ ";
           for(int j=0;j<dans.size();j++)
           {
               cout<<dans[j]<<" ";
           }
           cout<<"}";
           cout<<endl;
       }
   }
   for(int i=0;i<point;i++)
   {
       bans.clear();
       if(vis[i]==0)
       {
           vis[i]=1;
           bans.push_back(i);
           bfs(i);
           cout<<"{ ";
           for(int j=0;j<bans.size();j++)
           {
               cout<<bans[j]<<" ";
           }
           cout<<"}";
           cout<<endl;
       }
   }
   return 0;
}

/**************************************************************
	Problem: 3078
	User: 202058503118
	Language: C++
	Result: 正确
	Time: 0 ms
	Memory: 2208 kB
****************************************************************/

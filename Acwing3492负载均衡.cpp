#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
/*难点在于时间到了，如何归还算力？*/
const int N = 200001;
int c[N];
struct node
{
    int index,time,suanli;
    bool operator<(const node &a) const
    {
        return time > a.time;
    }
};
priority_queue<node>q;
int main()
{

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y,z,w;//x时刻，y编号，z耗时，w算力
        scanf("%d%d%d%d",&x,&y,&z,&w);
       if(!q.empty())
       {
            
            while(!q.empty())
            {
                node front=q.top(); //cout<<front.index<<" "<<front.time<<" "<<front.suanli<<endl;
                if(front.time<=x)
                {
                    q.pop();c[front.index]+=front.suanli;
                }
                else break;
            }
       }
        
        if(c[y]>=w)
        {
            node temp;temp.index=y;temp.suanli=w;temp.time=x+z;q.push(temp);
            c[y]-=w; cout<<c[y]<<endl;
            
        }
        else cout<<"-1\n";
        
    }
}
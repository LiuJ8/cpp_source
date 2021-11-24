//用RMQ做求区间最值
#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
const int N = 500001;
int n;
int tree[N];
int a[N];

int lowbit(int x)
{
    return x&-x;
}
void add(int x,int k)
{
    for(int i=x;i<=n;i+=lowbit(i))
        tree[i]+=k;
}
int query(int x)
{
    int res=0;
    for(int i=x;i>=1;i-=lowbit(i))
        res+=tree[i];
    return res;
}
int range_query(int l,int r)
{
	if(l==r)return 0;
    return query(r-1)-query(l-1);
}
void Init()
{
    for(int i=1;i<=n;i++)
    {
        a[i]=1;
        add(i,1);
    }
}
int main()
{
    int q;
    int mod,l,r,x,y;
    cin>>n>>q;
    Init(); 
    while(q--)
    {
        scanf("%d%d%d",&mod,&x,&y);
        l=min(x,y);r=max(x,y);
        if(mod==1)
        {
        	
            if(range_query(l,r)==r-l)
            	printf("Yes\n");
            	
            else if(range_query(1,l)+range_query(r,n)+a[n]==n+l-r)
            {	//cout<<l<<" "<<r<<" "<<range_query(1,l)<<" "<<range_query(r,n)<<" "<<a[n]<<endl;//a[n]
            	printf("Yes\n");
            }
            else printf("No\n");
        }
        if(mod==0)
        {
            if(l==0&&r==n)
            {
                if(a[n]==1)
            	{
            		 add(n,-1);
            		 a[n]=0; 
				}
                else{
                    add(n,1);
                    a[n]=1;
                }
            }
           else if(a[l]==1)
            {
                add(l,-1);
                a[l]=0;
            }
            else{
                add(l,1);
                a[l]=1;
            }
        }
    }

}

/*
5 100
1 2 5
0 4 5
1 4 5
0 2 3
1 3 4
1 1 3
0 1 2
0 2 3
1 2 4
1 2 5 

*/
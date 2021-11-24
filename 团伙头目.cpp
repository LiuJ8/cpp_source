#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include <map>
using namespace std;
const int N = 2001;
struct nod{
	string a,b;
	int time;
}node[N];
map<string,int> name;
vector<string>a;
int f[N];//父节点 
int tim[N];//每个人的总通话时间 
int total_time[N];//每个帮派的总通话时间 
int sum[N];	//每个帮派的总人数 
int maxm[N];	//每个帮派最大通话时间的人的编号 
int find(int x)
{
	if(x==f[x])
		return x;
	return f[x]=find(f[x]);
}
void Union(int a,int b)
{
	a=find(a);b=find(b);
	if(a!=b)
	{
		if(tim[maxm[a]]<tim[maxm[b]])
			maxm[a]=maxm[b]; //取根节点和当前新加入的结点的maxm的最大值，取较大的通话时间 
		sum[a]+=sum[b];		//之前不在一个连通分量，人数也加上 
		total_time[a]+=total_time[b];	//总通话时间也加上 
		f[b]=a;
	}
}
void Init()
{
	for(int i=0;i<a.size();i++)
	{
		name[a[i]]=i;//初始化每个人的姓名，string->int的映射 
		f[i]=i;		//初始f[i]=i; 
		sum[i]=1;	//每个帮派只有一个人 
		maxm[i]=i;	//最大的点的人就是他自己 
	}
}

struct re{
		string name;
		int sum;
	};
bool cmp(re a,re b)
{
	return a.name<b.name;
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>node[i].a>>node[i].b>>node[i].time;
		a.push_back(node[i].a);
		a.push_back(node[i].b);
	}
	sort(a.begin(),a.end());//排序 
	a.erase(unique(a.begin(),a.end()),a.end());//去重 
	Init();//初始化每个人 
	for(int i=0;i<n;i++)
	{
		int a=name[node[i].a];//a b是两个人的int编号 
		int b=name[node[i].b];
		total_time[a]+=node[i].time;
		total_time[b]+=node[i].time;
		tim[a]+=node[i].time;
		tim[b]+=node[i].time; 
	}

	for(int i=0;i<n;i++)
	{
		int x=name[node[i].a];
		int y=name[node[i].b];
		Union(x,y);
	}
	re res[N];
	int j=0;
	for(int i=0;i<a.size();i++)
	{//total_time[i]存放的是两倍的时间。 
		//因为一开始就存了和其他所有人的所有通话时间，后面Union的时候又加起来了。 
		if(i==f[i]&&total_time[i]/2>k&&sum[i]>=3)
			res[++j].name=a[maxm[i]],
			res[j].sum=sum[i];
	}
	sort(res+1,res+1+j,cmp);
	cout<<j<<endl;
	for(int i=1;i<=j;i++)
		cout<<res[i].name<<" "<<res[i].sum<<endl;
} 
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
const int N = 1001;
int f[N];
int maxm[N];
map<string,int> name;
vector<string> a;
int total_time[N];
int tim[N];
int sum[N];
struct nod{
    string a,b;
    int time;
}node[N];
int find(int x)
{
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
void Union(int a,int b)
{
    a=find(a);b=find(b);
    if(a!=b)
    {
        if(tim[maxm[a]]<tim[maxm[b]])
            maxm[a]=maxm[b];
        total_time[a]+=total_time[b];
        sum[a]+=sum[b];
        f[b]=a;

    }
}
void Init1()
{
   for(int i=0;i<a.size();i++)
   {
       name[a[i]]=i;
       f[i]=i;
       maxm[i]=i;
       sum[i]=1;
   }
}
void Init2(int n)
{
     for(int i=1;i<=n;i++)
    {
        int a,b;
        a=name[node[i].a];b=name[node[i].b];
        total_time[a]+=node[i].time;
        total_time[b]+=node[i].time;
        tim[a]+=node[i].time;
        tim[b]+=node[i].time;
    }
}
struct end{
    string i;
    int sum;
}res[N];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>node[i].a>>node[i].b>>node[i].time;
        a.push_back(node[i].a);
        a.push_back(node[i].b);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
   Init1();
   Init2(n);
   for(int i=1;i<=n;i++)
   {
       int a,b;
       a=name[node[i].a];b=name[node[i].b];
       Union(a,b);
   }
   int j=0;
   for(int i=0;i<a.size();i++)
   {
       if(i==f[i]&&total_time[i]/2>k&&sum[i]>=3)
        res[++j].i=a[maxm[i]],
        res[j].sum=sum[i];
   }
   cout<<j<<endl;
   for(int i=1;i<=j;i++)
   {
       cout<<res[i].i<<" "<<res[i].sum<<endl;
   }
}
*/
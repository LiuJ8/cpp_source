#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N = 1e3+1;
int a[N];
map<int,int>ma;
/*
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    int j=i;//j永远是孩子结点
    while(j>1)
    {
        if(a[j]<a[j/2])
        {
            swap(a[j],a[j/2]);
            j=j/2;
        }
        else break;
    }
}
*/
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int j=i;
        while(j>1)
        {
            if(a[j]<a[j/2])
            {
                swap(a[j],a[j/2]);
                j=j/2;
            }
            else break; //父节点比子节点小，不用换
        }
    }
    //数组是下标从1-n.对应不同的值
   /*
    //后面的判断是根据不同的值，找在数组里的下标
    并且值可以是负数，所以不得不用map int->int 
    */
   for(int i=1;i<=n;i++)
    ma[a[i]]=i;
    while(m--)
    {
        int x,y;cin>>x;
        string s;cin>>s;
        if(s[0]=='a')
        {
            cin>>y>>s>>s;	//要把剩下的输入吃完 
            if(ma[x]/2==ma[y]/2)
                cout<<"T"<<endl;
            else cout<<"F"<<endl;
        }
        else
        {
            cin>>s;cin>>s;
            if(s[0]=='r')
            {
                if(ma[x]==1)
                    cout<<"T"<<endl;
                else cout<<"F"<<endl;
            }
            else if(s[0]=='c')
            {
                cin>>s>>y;
                if(ma[x]/2==ma[y])
                    cout<<"T"<<endl;
                else cout<<"F"<<endl;
            }
            else if(s[0]=='p'){
                cin>>s>>y;
                if(ma[y]/2==ma[x])
                    cout<<"T"<<endl;
                else cout<<"F"<<endl;
            }
        }
    }
}
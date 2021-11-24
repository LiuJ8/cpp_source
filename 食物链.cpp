#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 50001;
int f[N*3];
void Init()
{
    for(int i=1;i<3*N-1;i++)
        f[i]=i;
}
int find(int x)
{
    if(x==f[x]) return x;
    return f[x] = find(f[x]);
}
void Union(int a,int b)
{
    int x=find(a);
    int y=find(b);
    f[x]=y;
}
int main()
{
    int n,k;
    int sum=0;
    scanf("%d%d",&n,&k);
    Init();
    while(k--)
    {
        int a,b,c;
        scanf("%d%d%d",&c,&a,&b);
        if(a>n||b>n)
        {
            sum++;
            continue;
        }
        if(c==1)
        {
            if(find(a)==find(b+n)||find(a)==find(b+2*n))
            {
                sum++;
            }
           else{
                //x y是同类
            Union(a,b);
            Union(a+n,b+n);
            Union(a+2*n,b+2*n);
           }
        }
        if(c==2)
        {
            //输入是a吃b
            //b吃a或者ab为同类时为假
            /*
            if(a==b)
            {
                sum++;continue;
            }
            可以不写。想想为什么你这么笨。
            如果a==b，那find(a)和find(b)其实就是find的一个东西。当然相等了。
            
            /*/
            if(find(a)==find(b)||find(a)==find(b+2*n))
            {
                sum++;
                //continue;
            }
            else{
                Union(a,b+n);
                Union(a+n,b+2*n);
                Union(a+2*n,b);
            }
        }
    }
    printf("%d",sum);
}
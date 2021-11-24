/*求下排每个数都是先前上排那十个数在下排出现的次数。
上排的十个数如下：$0,1,2,3,4,5,6,7,8,9$
举例：数值: $0,1,2,3,4,5,6,7,8,9$分配: $6,2,1,0,0,0,1,0,0,0$
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10]={0,1,2,3,4,5,6,7,8,9};
int res[10];
int getResult();
int getFrequency(int num);
int main()
{
    int k,i,success=0;
    while(success==0)
    {
        success=getResult();
         for(int i=0;i<10;i++)
        cout<<res[i]<<" ";
        cout<<endl;
    }
    for(int i=0;i<10;i++)
        cout<<res[i]<<" ";
}
int getResult()
{
    int i,num,frequency;
    int success =1;
    for(int i=0;i<10;i++)
    {
        num=a[i];
        frequency=getFrequency(num);
        if(res[i]!=frequency)
        {
            res[i]=frequency;
            success=0;
        }
    }
    return success;
}
int getFrequency(int num)
{
    int i;
    int count=0;
    for(i=0;i<10;i++)
    {
        if(res[i]==num)
            count++;
    }
    return count;
}
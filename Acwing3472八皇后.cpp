#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10];
int cnt=0;
void queen(int x) // [x,i]   [j,a[j]]
{
    if(x>8)
    {
        for(int i=1;i<=8;i++) cout<<a[i];cout<<endl;return;
    }
    int i,j;
    for(i=1;i<=8;i++) //����x�������У�����һ�п����С�
    {
        for(j=1;j<x;j++) 
        {
            if(a[j]==i||abs(x-j)==abs(i-a[j]))
                break;
        }
        if(j>=x) //[x,i]��ǰ�����зźõĶ�û�г�ͻ����i�п���
        {
            a[x]=i;queen(x+1);
        }
    }
}
int main()
{
    queen(1);
    cout<<cnt<<endl;
}
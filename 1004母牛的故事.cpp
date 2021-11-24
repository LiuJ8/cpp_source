#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string a[100000];
int main()
{
    int n;
   cin>>n;
   string temp;
   int len=0;
   while(getline(cin,temp))
    {
        a[len++]=temp;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<endl<<endl;
    for(int i=1+n;i<=len;i++)
    {
        string temp=a[i];
        for(int j=0;j<temp.length();j++)
        {
            if(temp[j]==' ') cout<<endl<<endl;
            else cout<<temp[j];
        }
        cout<<endl<<endl;
    }
  
}
#include<iostream>
#include<cstring>
#include<algorithm>
//回溯法
using namespace std;
const int N = 1000;
int a[N][N];
char str1[N],str2[N];
int maxi,maxj,MAX=0;
int main()
{
    cin>>str1+1>>str2+1;

    for(int i=1;i<=strlen(str1+1);i++)
    {
        for(int j=1;j<=strlen(str2+1);j++)
        {
            if(str1[i]==str2[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            if(a[i][j]>MAX)
            {
                maxi=i;maxj=j;
                MAX=a[i][j];
            }
        }
    }
    if(MAX==0)
    {
        cout<<"false";
    }
    else{
        int i,j;
    i=maxi;j=maxj;
    while(a[i][j]!=0)
    {
        i--;j--;
    }
    i++;j++;
    //cout<<endl;
    //cout<<i<<" "<<MAX<<endl;
    for(int x=i;x<i+MAX;x++)
    {
       cout<<str1[x];
    }
    }
   // cout<<endl;
    
}
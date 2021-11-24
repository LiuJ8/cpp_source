#include<stdio.h>
#include<string.h>
char a[10001];
int main()
{
    while(gets(a+1))
    {
        int len=strlen(a+1);
        for(int i=len/2;i>=1;i--)
        {
            if(i%2)  //是奇数，逆时针旋转，是前面的等于后面的
            {
                char c=a[i];
                int j;
                for(j=i;j+i<=len;j+=i)
                    a[j]=a[j+i];
                a[j]=c;
            }
            else{   //是偶数，顺时针，后面的等于前面的
                int index=(len/i)*i;
                char c=a[index];
                int j;
                for(j=index;j-i>=1;j-=i)
                    a[j]=a[j-i];
                a[j]=c;
            }
        }
        puts(a+1);
    }
}
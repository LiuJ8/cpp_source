#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[6]={0,1,3,9,27,81};
int b[3]={-1,0,1};
char c[3]={'-',' ','+'};
int main()
{
    int x;
    scanf("%d",&x);
    for(int i=0;i<3;i++)                //1
    {
        for(int j=0;j<3;j++)            //3
            for(int k=0;k<3;k++)        //9
                for(int l=0;l<3;l++)    //27
                    for(int r=0;r<3;r++) //81
                    {
                        if(b[i]*1+b[j]*3+b[k]*9+b[l]*27+b[r]*81==x)
                           {
                                if(b[r]) printf("81");
                                if(b[r]&&b[l]) printf("%c",c[l]);
                                if(b[l]) printf("27");
                                if((b[r]||b[l])&&b[k])printf("%c",c[k]);
                                if(b[k]) printf("9");
                                if((b[r]||b[l]||b[k])&&b[j]) printf("%c",c[j]);
                                if(b[j]) printf("3");
                                if((b[r]||b[l]||b[k]||b[j])&&b[i]) printf("%c",c[i]);
                                if(b[i]) printf("1");
                            break;
                           }
                    }
    }
}
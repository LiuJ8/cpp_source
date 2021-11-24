#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2*1e8+10;
string b,a;
int len[N]; //以每个字符为中心的回文长度的一半，向下取整
int manacher(string a)
{
    
    int rightSideCenter=0;    //右边界的回文串中心
    int rightSide=0;         //右边界
    int longestHalf=0;       //最长的回文长度
    int center = 0;          //最长回文长度的回文中心
    for(int i=0;i<a.length();i++)
    {
        bool needCalc = true;
        if(rightSide > i)
        {
            //计算i相对rightSideCenter的左边对称位置
            int leftCenter = 2*rightSideCenter -i;
            len[i] = len[leftCenter];
            if(i + len[i] >= rightSide) //如果超过了最右边界，进行调整
            {
                len[i] = rightSide - i;
            }
            if(i + len[i] < rightSide)
            {
                needCalc = false;
            }
        }
        if(needCalc)
        {
            while(i - 1 - len[i] >=0 && i + 1 + len[i] < a.length())
                if(a[i - 1 - len[i]] == a[i + 1 + len[i]])
                    len[i]++;
                else break;
        }
        //更新右端点
        rightSide = i + len[i];
        rightSideCenter = i;
        if(len[i] > longestHalf)
        {
            center = i;
            longestHalf = len[i];
        }
    }
    string res;
    for(int i = center - longestHalf +1;i<=center + longestHalf;i+=2)
        res.push_back(a[i]);
    cout<<res<<endl;
    return res.length();
}
int main()
{
    cin>>b;
    for(int i=0;i<b.length();i++)
    {
        a.append("#");
        a.push_back(b[i]);
        
    }
    a.append("#");
    cout<<a<<endl;
    int res = manacher(a);
    cout<<res;
}
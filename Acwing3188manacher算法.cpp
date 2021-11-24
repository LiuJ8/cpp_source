#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2*1e8+10;
string b,a;
int len[N]; //��ÿ���ַ�Ϊ���ĵĻ��ĳ��ȵ�һ�룬����ȡ��
int manacher(string a)
{
    
    int rightSideCenter=0;    //�ұ߽�Ļ��Ĵ�����
    int rightSide=0;         //�ұ߽�
    int longestHalf=0;       //��Ļ��ĳ���
    int center = 0;          //����ĳ��ȵĻ�������
    for(int i=0;i<a.length();i++)
    {
        bool needCalc = true;
        if(rightSide > i)
        {
            //����i���rightSideCenter����߶Գ�λ��
            int leftCenter = 2*rightSideCenter -i;
            len[i] = len[leftCenter];
            if(i + len[i] >= rightSide) //������������ұ߽磬���е���
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
        //�����Ҷ˵�
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
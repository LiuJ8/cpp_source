#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N = 1e4+10;
const int maxn = 2*1e4;
int n;
struct node{
    int l,r;
};
vector<node>reg;
bool cmp(node x,node y)
{
    return x.r<y.r;
}
bool check(int x)
{
    int L=0;
    vector<node>tmp(reg);
    while(true)
    {
        bool find=false; //��ʾ�ҵ�һ���ܽ��ϵ�����
        for(int i=0;i<tmp.size();i++)
        {
            int ta=tmp[i].l,tb=tmp[i].r;
            cout<<ta<<" "<<tb<<endl;
            int len=tb-ta;
            if(ta-x<=L && tb+x>=L) //�ܽ���
            {
                find = true;
                if(ta + x >= L) L += len;
                else if(ta + x < L) L = tb+x; 
                tmp.erase(tmp.begin()+i);
                break;
            }
        }
        if(!find || L>=maxn) break;
    }
    if(L>=maxn) return true;
    return false;   
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        node temp;scanf("%d%d",&temp.l,&temp.r);
        temp.l*=2;temp.r*=2; //��������䶼����������С��С����0.5 �ȳ�2�ٳ�2 **
        reg.push_back(temp);
    }
    sort(reg.begin(),reg.end(),cmp); //���Ҷ˵��������� **
    int l=0,r=2*1e4;
    double ans=0;
    while(l<r)
    {
        int mid=(l+r)>>1;
        cout<<l<<" "<<r<<" "<<mid<<endl;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<(double)l/2;
}
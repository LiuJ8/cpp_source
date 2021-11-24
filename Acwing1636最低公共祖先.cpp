/*
���������� + ��ϣ��
��������������: ���ڵ� > ����ӣ����ڵ� <= �Ҷ���
ǰ��������ԣ���->��->�ҵ�˳�����
��ǰ��������ҵ���һ�����϶������������ԵĽ��Ϊx,y�Ĺ�ͬ���ڵ� ******
*/
#include<iostream>
#include<cstring>
#include<algorithm>
//VSCode ��Ҫ��unordered_map��Ҫ��������
#include<tr1/unordered_map>
using namespace std::tr1;
//�ύֻ��Ҫ����һ��
//#include<unordered_map>
using namespace std;
unordered_map<int,bool> HashTable;
const int N = 10001;
int pre[N];
int main()
{
    int n,m;cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&pre[i]);
        HashTable[pre[i]]=true;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        if(HashTable[u]&&HashTable[v])
        {
            int father;
            for(int j=1;j<=n;j++)
            {
                if((pre[j]<=u&&pre[j]>=v)||(pre[j]>=u&&pre[j]<=v))
                   {
                        father=pre[j];
                        break;    
                    }
            }
            if(father==u||father==v)
            {
                printf("%d is an ancestor of %d.\n",father,u==father?v:u);
            }
            else cout<<"LCA of "<<u<<" and "<<v<<" is "<<father<<"."<<endl;
        }
        else if(!HashTable[u]&&!HashTable[v])
        {
            printf("ERROR: %d and %d are not found.\n",u,v);
        }
        else if(!HashTable[u])
            printf("ERROR: %d is not found.\n",u);
        else printf("ERROR: %d is not found.\n",v);
    }
}

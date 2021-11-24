/*
二叉树特性 + 哈希表
二叉搜索树特性: 父节点 > 左儿子，父节点 <= 右儿子
前序遍历特性：根->左->右的顺序遍历
从前序遍历中找到第一个符合二叉搜索树特性的结点为x,y的共同父节点 ******
*/
#include<iostream>
#include<cstring>
#include<algorithm>
//VSCode 想要用unordered_map需要下面两行
#include<tr1/unordered_map>
using namespace std::tr1;
//提交只需要下面一行
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

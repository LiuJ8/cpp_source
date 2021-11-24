#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N = 21;
typedef struct node{
    int key;
    struct node *lchild;
    struct node *rchild;
    int height;
}BTNode;
BTNode *bt;
int a[N];
void cengci(BTNode *bt)
{
    queue<BTNode *> q;
    q.push(bt);
    if(q.empty()) cout<<"Yes";
    while(!q.empty())
    {
        BTNode *p=q.front();
        q.pop();
        printf("%d ",p->key);
        if(p->lchild!=NULL)
            q.push(p->lchild);
        if(p->rchild!=NULL)
            q.push(p->rchild);
    }
    
}
void build(BTNode *&bt,int i,int n)//bt加引用，否则空间会释放 
{
    if(i<=n)
    {
    	bt=(BTNode *)malloc(sizeof(BTNode));
    	bt->lchild=bt->rchild=NULL;
        bt->key=a[i];
        build(bt->lchild,2*i,n);
        build(bt->rchild,2*i+1,n);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(bt,1,n);

    cengci(bt);
}
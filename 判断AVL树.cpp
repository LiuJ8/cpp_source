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

//获取当前结点的高度 
int height(BTNode *bt)
{
	if(bt==NULL)return 0;
	return bt->height;
}
//获取当前节点的平衡因子 
int getbalance(BTNode *bt)
{
	if(bt==NULL)return 0;
	return height(bt->lchild)-height(bt->rchild);
}
//创建新的结点
BTNode *newnode(int key)
{
	BTNode *bt;
	bt=(BTNode *)malloc(sizeof(BTNode));
	bt->key=key;
	bt->height=1;
	bt->lchild=bt->rchild=NULL;
	return bt;
 } 
//LL 
BTNode *ll_rotate(BTNode *y)
{
	BTNode *x=y->lchild;
	y->lchild=x->rchild;
	x->rchild=y;
	y->height=max(height(y->lchild),height(y->rchild))+1;
	x->height=max(height(x->lchild),height(x->rchild))+1;
	return x;
}
BTNode *rr_rotate(BTNode *y)
{
	BTNode *x=y->rchild;
	y->rchild=x->lchild;
	x->lchild=y;
	y->height=max(height(y->lchild),height(y->rchild))+1;
	x->height=max(height(x->lchild),height(x->rchild))+1;
	return x;
}
BTNode *lr_rotate(BTNode *y)
{
	BTNode *x=y->lchild;
	y->lchild=rr_rotate(x);
	return ll_rotate(y);
}
BTNode  *rl_rotate(BTNode *y)
{
	BTNode *x=y->rchild;
	y->rchild=ll_rotate(x);
	return rr_rotate(y);
}
BTNode *insert(BTNode *bt,int key)
{
	//构建二叉排序树 
	if(bt==NULL)
		return newnode(key);
	if(key<bt->key)
		bt->lchild=insert(bt->lchild,key);
	else if(key>bt->key)
		bt->rchild=insert(bt->rchild,key);
	else return bt;

	bt->height=1+max(height(bt->rchild),height(bt->lchild));//调整高度 
	//调整
	int balance=getbalance(bt);
	if(balance>1&&key < bt->lchild->key)//LL型
	{
		return ll_rotate(bt); 
	 } 
	else if(balance<-1&&key > bt->rchild->key)
		return rr_rotate(bt);
		
	else if(balance>1&&key > bt->lchild->key)
		return lr_rotate(bt);
		
	else if(balance<-1&&key < bt->rchild->key)
		return rl_rotate(bt);
		
	return bt;
}
void cengci(BTNode *bt)
{
	int sum=0;
	int left=0,right=0,flag=1;
    queue<BTNode *> q;
    q.push(bt);
    if(q.empty()) cout<<"Yes";
    while(!q.empty())
    {
        BTNode *p=q.front();
        q.pop();
			sum++;
        printf("%d ",p->key);
        if(p->lchild!=NULL)
            q.push(p->lchild);
        else left=1;
        if(p->rchild!=NULL)
           	 q.push(p->rchild);
		else right=1;
		if((left==1&&p->lchild!=NULL)||(right==1&&p->rchild!=NULL))
			flag=0;
    }
    if(flag==0)
    	cout<<endl<<"NO"; else cout<<endl<<"YES";
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	  scanf("%d",&a[i]);
    	  bt=insert(bt,a[i]);
	}
	cengci(bt);
}
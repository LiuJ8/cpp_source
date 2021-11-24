#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
const int N = 1000;
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}BTNode;
void houxu(BTNode *bt){
    stack<BTNode*> s;
    BTNode *p;
    int flag;
    do{
        while(bt!=NULL){
            s.push(bt);
            bt=bt->lchild;
        }
        p=NULL;
        flag = 1;
        while(!s.empty()&&flag){
            bt = s.top();
            if(bt->rchild==p)
            {
                cout<<bt->data;
                s.pop();
                p=bt;
            }
            else
            {
                flag = 0;
                bt=bt->rchild;
            }
        }
    }while(!s.empty());
    
}
BTNode *CreateBT(char *pre, char *in, int n){
    int p;char *t;BTNode *bt;
    if(n<=0) return NULL;
    bt = (BTNode *)malloc(sizeof(BTNode));
    bt->data = *pre; 
    for(t=in;t<n+in;t++){
        if(*t==*pre)
            break;
    }
    p = t - in;
    bt->lchild = CreateBT(pre+1,in,p);
    bt->rchild = CreateBT(pre+1+p,t+1,n-p-1);
    return bt;
}
int main(){
    char *pre,*in;
    pre = (char *)malloc(sizeof(char)*N);
    in = (char *)malloc(sizeof(char)*N);
    cin>>in>>pre;
    int n = strlen(pre);
    BTNode *bt = CreateBT(pre,in,n);//n：长度
    houxu(bt);
}
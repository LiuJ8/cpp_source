#include<iostream>
#include<algorithm>
#include<malloc.h>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;
}LinkNode;
int main()
{
    int n;
    cin>>n;
    LinkNode *st;
    st=(LinkNode *)malloc(sizeof(LinkNode));
    st->next=NULL;
    LinkNode *p;
    p=st;
    for(int i=1;i<=n;i++)
    {
        LinkNode *temp;
        temp=(LinkNode *) malloc(sizeof(LinkNode));
        temp->next=NULL;
        scanf("%d",&temp->data);
        {
            if(temp->data!=p->data)
              {  p->next=temp;
                p=temp;
            }
        }
    }
    p=st;
    p=p->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
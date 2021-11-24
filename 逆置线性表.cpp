//头插法
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct node{
    int data;   
    struct node *next;
}LinkList;
int main()
{
    LinkList *st;st=(LinkList *)malloc(sizeof(LinkList));
    st->data=0;st->next=NULL;
    int n;
    cin>>n;
    LinkList *p;
    for(int i=1;i<=n;i++)
    {
        LinkList *temp;
        temp=(LinkList *)malloc(sizeof(LinkList));
        scanf("%d",&temp->data);
        temp->next=st->next;
        st->next=temp;
    }
    p=st->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<int,int>a,b,c;
typedef struct node{
    int data;
    struct node *next;
}LinkList;
int main()
{   
    int MIN=0x7fffffff;
    int MAX=-MIN;
    LinkList *st1,*st2,*st3;
    st1=(LinkList *)malloc(sizeof(LinkList));
    st2=(LinkList *)malloc(sizeof(LinkList));
    st3=(LinkList *)malloc(sizeof(LinkList));
    int n;cin>>n;
    LinkList *p;
    p=st1;
    for(int i=1;i<=n;i++)
    {
        LinkList *temp;
        temp=(LinkList *)malloc(sizeof(LinkList));
        scanf("%d",&temp->data);
        p->next=temp;
        p=temp;
        a[temp->data]=1;
        MIN=min(MIN,temp->data);
        MAX=max(MAX,temp->data);
    }
    p=st2;
    int m;
    cin>>m;
     for(int i=1;i<=m;i++)
    {
        LinkList *temp;
        temp=(LinkList *)malloc(sizeof(LinkList));
        scanf("%d",&temp->data);
        p->next=temp;
        p=temp;
        b[temp->data]=1;
        MIN=min(MIN,temp->data);
        MAX=max(MAX,temp->data);
    }
    cin>>m;
    p=st3;
    for(int i=1;i<=m;i++)
    {
        LinkList *temp;
        temp=(LinkList *)malloc(sizeof(LinkList));
        scanf("%d",&temp->data);
        p->next=temp;
        p=temp;
        c[temp->data]=1;
        MIN=min(MIN,temp->data);
        MAX=max(MAX,temp->data);
    }
    for(int i=MIN;i<=MAX;i++)
    {
        if(a[i]&&b[i]&&c[i])
            cout<<i<<" ";
    }
}
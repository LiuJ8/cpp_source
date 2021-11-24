#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100000;
typedef struct LNode{
    int id;
    int grade;
    struct LNode *next;
}LinkList;
int main()
{
    LinkList *st1,*st2,*st;
    st1=(LinkList *)malloc(sizeof(LinkList));
    st2=(LinkList *)malloc(sizeof(LinkList));
    st=(LinkList *)malloc(sizeof(LinkList));
    st->next=NULL;
    int n,m;
    cin>>n>>m;
    LinkList *p,*t,*pre;//t用来从前往后遍历找比他小的,pre指向t前面   
    for(int i=1;i<=n+m;i++)
    {
        pre=st;
         t=pre->next;
        LinkList *temp;
        temp=(LinkList *)malloc(sizeof(LinkList));
        temp->next=NULL;
        scanf("%d%d",&temp->id,&temp->grade);
        //学号小就头插，学号大就尾插
        if(st->next==NULL)  //如果现在还没有插入的，直接插入
        {
            st->next=temp;
        }
        else
        {
            while(temp->id>t->id&&t->next!=NULL)
              {
                  pre=t;
                    t=t->next;
                    
              }
            if(t->next!=NULL)//如果没遍历到最后一个，头插
            {
                temp->next=pre->next;
                pre->next=temp;
            }
            else    //遍历到最后一个，直接插入
            {
                if(t->id<temp->id)
                {
                    t->next=temp;
                }
                else 
                {
                    temp->next=pre->next;
                    pre->next=temp;
                }
            }

        }
    }
    p=st->next;
    while(p!=NULL)
    {
        printf("%d %d\n",p->id,p->grade);
        p=p->next;
    }
}
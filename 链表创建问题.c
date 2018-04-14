#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}*LinkList;

/*初始化，构造一个只有头节点的空表；
void InitList(LinkList *L)
{
    L = (LinkList)calloc(1,sizeof(Lnode));
    L->next = NULL;
}
*/
//前插法构建单向链表；
void CreateList(LinkList L,int n)
{
    int i;
    LinkList p;
    L = (LinkList)calloc(1,sizeof(LinkList));
    L->next = NULL;
    for(i=0;i<n;i++)
    {
        p = (LinkList)calloc(1,sizeof(LinkList));
        printf("Please input new node: ");
        scanf("%d",&p->data);
        p->next = L->next;
        L->next = p;
    }
    //return L;
}

void ShowList(LinkList L)
{
    LinkList p = L->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    LinkList link_1;
    CreateList(link_1,5);
    ShowList(link_1);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}*LinkList;

/*初始化，构造一个只有头节点的空表；
void InitList(LinkList *L)
{
    L = (LinkList)calloc(1,sizeof(Lnode));
    L->next = NULL;
}
*/
//前插法构建单向链表；
LinkList CreateList(int n)
{
    int i;
    LinkList p,L;
    L = (LinkList)calloc(1,sizeof(LinkList));
    L->next = NULL;
    for(i=0;i<n;i++)
    {
        p = (LinkList)calloc(1,sizeof(LinkList));
        printf("Please input new node: ");
        scanf("%d",&p->data);
        p->next = L->next;
        L->next = p;
    }
    return L;
}

void ShowList(LinkList L)
{
    LinkList p = L->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    LinkList link_1;
    link_1 = CreateList(5);
    ShowList(link_1);
    return 0;
}

1.统计输入多组字符中“*”最多的字符，主要考察二维数组为函数参数，函数参数为指针。
#include <stdio.h>
#include <stdlib.h>

char *func(char s[][50],int n)
{
    int i,j;
    int num[n];
    int max,a;
    //初始化计数数组；
    for(i=0;i<n;i++)
    {
        num[i]=0;
    }
    //统计 * 数量；
    for(i=0;i<n;i++)
    {
        for(j=0;s[i][j]!='\0';j++)
        {
            if(s[i][j]=='*')
                num[i]++;
        }
    }
    //判断是否返回NULL；
    for(i=0;i<n;i++)
    {
        if(num[i]==0)
            continue;
        else
            break;
    }
    if(i==n) return NULL;
    //取最大值；
    max = num[0]; a = 0;
    for(i=1;i<n;i++)
    {
        if(max<num[i])
        {
            max = num[i];
            a = i;
        }
    }
    return s[a];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=-1)
    {
        int i;
        char str[n][50];
        for(i=0;i<n;i++)
        {
            scanf("%s",str[i]);
        }
        char *p;
        p = func(str,n);
        printf("%s\n",p);
    }
    return 0;
}
2.提取指定位置字符
#include <stdio.h>
#include <stdlib.h>

void func(char *str,char *p,int m,int n)
{
    int i,j;
    for(i=0,j=0;str[i]!='\0';i++)
    {
        if(i>=m-1&&i<=n-1)
        {
            p[j] = str[i];
            j++;
        }
    }
    p[j]='\0';
}
int main()
{
    char str[100];
    char p[100];
    int m,n;
    while(scanf("%s",str)!=-1)
    {
        scanf("%d%d",&m,&n);
        func(str,p,m,n);
        printf("%s\n",p);
    }
    return 0;
}
3.链表
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//初始化链表；
LinkList InitList() //如果形参为LinkList的指针，只定义指针而不赋空间则出错；

{
    LinkList Li;
    Li = (LinkList)calloc(1,sizeof(LinkList));
    Li->next = NULL;
    return Li;
}
//前插法构建单向链表；
LinkList CreateList(int n)
{
    int i;
    LinkList p,L;
    /*L = (LinkList)calloc(1,sizeof(LinkList));
    L->next = NULL;*/
    L = InitList();
    for(i=0;i<n;i++)
    {
        p = (LinkList)calloc(1,sizeof(LinkList));
        printf("Please input a new node: ");
        scanf("%d",&p->data);
        p->next = L->next;
        L->next = p;
    }
    return L;
}
//增加结点（无序）
void AddNode_List(LinkList L,ElemType n)
{
    LinkList p;
    p = (LinkList)calloc(1,sizeof(LNode));
    p->data = n;
    p->next = L->next;
    L->next = p;
}
//遍历链表；
void ShowList(LinkList L)
{
    LinkList p = L->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

//原地反转，另设节点指针，前插法重置链表
void Inverse_LinkList(LinkList L)
{
    LinkList p,r;
    p = L->next->next;
    L->next->next = NULL;
    while(p)
    {
        r = p -> next; //核心，另设变量指向下一个节点
        p->next = L->next;
        L->next = p;
        p = r;
    }
}
//删除指定结点；
void Delete_Node(LinkList L,int n)
{
    LinkList q,p;
    p = L;
    int i = 0;
    while((i<n-1)&&(p->next!=NULL))
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;

}
//删除偶数元素结点；
void Delete_EvenNode(LinkList L,int n)
{
    LinkList p;
    int i = 1,j=0;
    p = L->next;
    while(p!=NULL&&i<=n)  //不能只以p!=NULL为结束标志；
    {
        if((p->data)%2==0)
            {
                Delete_Node(L,i-j);
                j++;
            }
        p = p->next;
        i++;
    }
}

//建立升序有序单向链表；
LinkList Create_UpOrderList(int n)
{
    LinkList L,p,r;
    int i;
    ElemType m;
    L = InitList();
    for(i=0;i<n;i++)
    {
        p = L;
        printf("Please input a new node: ");
        scanf("%d",&m);
        r = (LinkList)calloc(1,sizeof(LNode));
        r->data = m;
        while((p->next!=NULL) && (m > p->next->data))
        {
            p = p->next;
        }
        r->next = p->next;
        p->next = r;
    }
    return L;
}
//增加升序单链表结点
void AddNode_UpOrderList(LinkList L,ElemType n)
{
    LinkList p,r;
    p = L;
    r = (LinkList)calloc(1,sizeof(LNode));
    r->data = n;
    while((p->next!=NULL) && (n > p->next->data))
    {
        p = p->next;
    }
    r->next = p->next;
    p->next = r;
}

//建立降序单链表；
LinkList Create_DownOrderList(int n)
{
    LinkList L,p,r;
    int i;
    ElemType m;
    L = InitList();
    for(i=0;i<n;i++)
    {
        p = L;
        printf("Please input a new node: ");
        scanf("%d",&m);
        r = (LinkList)calloc(1,sizeof(LNode));
        r->data = m;
        while((p->next!=NULL) && (m < p->next->data))
        {
            p = p->next;
        }
        r->next = p->next;
        p->next = r;
    }
    return L;
}
//增加降序单链表结点
void AddNode_DownOrderList(LinkList L,ElemType n)
{
    LinkList p,r;
    p = L;
    r = (LinkList)calloc(1,sizeof(LNode));
    r->data = n;
    while((p->next!=NULL) && (n < p->next->data))
    {
        p = p->next;
    }
    r->next = p->next;
    p->next = r;
}
//分割偶数链表
void Divide_EvenNode(LinkList L,LinkList evenList,int n)
{
    int i = 1,j=0;
    LinkList p;
    p = L->next;
    while(p!=NULL&&i<=n)//这里必须有p!=NULL；
    {
        if(p->data%2==0)
            {
                AddNode_List(evenList,p->data);
                Delete_Node(L,i-j);
                j++;
            }
        p = p->next;
    }
}
int main()
{
    LinkList link,evenl;
    link = CreateList(5);
    evenl = InitList();
    ShowList(evenl);
    printf("\n***********************\n");
    ShowList(link);
    Divide_EvenNode(link,evenl,5);
    printf("\n***********************\n");
    ShowList(link);
    printf("\n***********************\n");
    ShowList(evenl);
    return 0;
}

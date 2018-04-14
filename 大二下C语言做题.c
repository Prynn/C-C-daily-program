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


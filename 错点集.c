1.素数函数  忘记退出循环
int func(int m)
{
    int i,flag;
    for(i=2;i<m;i++)
    {
        if(m%i==0)
            {flag=0; 
            break;}    别忘了break！！！
        else
            flag=1;
    }
    if(flag==1)
        return m;
    else
        return 1;
}
2.忘记复位 
int main()
{
    int n,x,i,flag=0,t;
    while(scanf("%d",&n)!=-1)
    {
        t=0;   一定到记得复位！！！！
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x%2==0)
            {   t++;
                flag=1;
            }
        }
        if(flag==0)
            printf("0");
        else
            printf("%d\n",t);
    }
    return 0;
}
3.记得用n=strlen(str);
char c[100];
给c赋值"123456"之后   strlen(str)=6而不是100(初始赋的空间)；       和'\0'有关；
4.#include <stdio.h>
#include <stdlib.h>
double func(int b[],int n)
{
    int min,i,max,a,j;
    double aver=0.0;
    min=b[0];
    for(j=1;j<n;j++)
    {
        if(min>b[j])
        {
            i=j;
        }
    }
    max=b[0];
    for(j=1;j<n;j++)
    {
        if(max<b[j])
        {
            a=j;
        }
    }
    b[i]=0;
    b[a]=0;
    for(j=0;j<n;j++)                         循环量写成了i，和循环体内不对应；
    {
        aver+=b[j];
    }
    return (aver/(n-2));
}

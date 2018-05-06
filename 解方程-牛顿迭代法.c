#include<stdio.h>
#include<math.h>

void fun(int n,double x0,int c)
{
    double f,f1,x,c0=1;
    int i;
    for(i=0;i<c;i++)
    {
        c0=c0/10;
    }
    if(n==1)
    {
        do{
        x=x0;
        f1=3*x*x-2*x;
        f=x*x*x-x*x-1;
        x0=x-f/f1;
        }
    while(fabs(x0-x)>=c0);
    }
    if(n==2)
    {
        do{
        x=x0;
        f1=4*x*x*x-3;
        f=x*x*x*x-3*x+1;
        x0=x-f/f1;
        }
    while(fabs(x0-x)>=c0);

    }
    if(n==3)
    {
        do{
        x=x0;
        f1=1+exp(-x);
        f=x-exp(-x);
        x0=x-f/f1;
        }
    while(fabs(x0-x)>=c0);
    }
    printf("%d 1.00e-0%d %.5lf\n",n,c,x0);
}

int main()
{
    int n;
    double x0;
    char str[10];
    int c;
    while(scanf("%d",&n)!=-1)
    {
        scanf("%lf",&x0);
        scanf("%s",str);
        c = (int)(str[3]-'0');
        fun(n,x0,c);
    }
    return 0;
}

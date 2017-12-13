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

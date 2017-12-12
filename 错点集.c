1.素数函数
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

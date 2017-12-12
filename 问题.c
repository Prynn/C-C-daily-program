1.
#include<stdio.h>

int main()
{
    int n,a[10],i,m,b[10];  把10换成n为什么结果就错了
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    if(m>=n)
        printf("0");
    else
        {
            for(i=0;i<m;i++)
                {b[i]=a[i];}
            for(i=m;i<n;i++)
                b[i-1]=a[i];
        
    for(i=0;i<n-1;i++)
        printf("%d ",b[i]);}
    return 0;
}
2.null和\0

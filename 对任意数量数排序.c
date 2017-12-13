#include <stdio.h>
#include <stdlib.h>
void func(float a[],int n)
{
    int i,j;
    float t;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

int main()
{
   float grade[100];
   int i=0,n=0;
   while(scanf("%f",&grade[i])!=EOF)  重点在这
   {
       n++;i++;
   }
   func(grade,n);
   for(i=n-1;i>=0;i--)
   {
       printf("%g ",grade[i]);   %g可以小数整数混合输出
   }
    return 0;
}

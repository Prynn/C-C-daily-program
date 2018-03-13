#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,j,i,t;
    scanf("%d\n",&n);  //为什么加个\n才行  否则无法正确录入，第一个[0][50]直接为空白
    char str[n][50];
    for(i=0;i<n;i++)
        {
            gets(str[i]);
        }

    for(j=0;j<n;j++)
    {
        t=0;
       for(i=0;str[j][i+3]!='\0';i++)
       {
           if(str[j][i]=='g'&&str[j][i+1]=='o'&&str[j][i+2]=='o'&&str[j][i+3]=='d')
            t++;
       }
       printf("%d\n",t);
    }
    return 0;
}

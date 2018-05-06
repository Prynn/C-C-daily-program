重点在于：
1.插入排序算法  2.为字符数组动态开辟空间 3.二维数组的指针表示
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort1(char **pp,int n)
{
     int i,j;
    char t[20];
    for(i=0; i<n; i++)//简单的插入排序
        {
            strcpy(t,pp[i]);
            for(j=i-1; j>=0&&(strcmp(t,pp[j])<0); j--)
            strcpy(pp[j+1],pp[j]);
            strcpy(pp[j+1],t);
        }
    //补充完成程序
}
void output1(char *p[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s\n",p[i]);
    }
 //补充完成程序
}
int main()
{
    void sort1(char **pp,int n);
    void output1(char *p[],int n);
    char str[50],*cp[20];
    int n,l,i;
    while(scanf("%d\n",&n)!=EOF)
    {
          //getchar();
          for(i=0;i<n;i++)
          {
              gets(str);
             //start
              l = strlen(str);
             cp[i] = (char*)calloc(1,l*sizeof(char));
             strcpy(cp[i],str);//在此写动态开辟并存储程序
             //end
           }
           sort1(cp,n);
           output1(cp,n);
    }
    return 0;
}

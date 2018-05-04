1.单纯的计数：
int main()  
{  
    int i,num=0,word=0;  
    char string[80];  
    char c;  
        gets(string);  
    for(i=0;(c=string[i])!='\0';i++)  
        if(c==' ')word=0;  
        else if(word==0)  
        {word=1;  
         num++;  
        }  
    printf("there is %d words in this line;\n",num);  
    return 0;  
}  
2.分隔单词  

#include <stdio.h>
#include <stdlib.h>

void split(char *s)
{
    int is_word=0,i,j=0,k=0,num=0;
    char w[20][20];
    for(i=0;s[i]!='\0';i++)
    {
        if(is_word==0&&(s[i]<='z'&&s[i]>='a')||(s[i]<='Z'&&s[i]>='A'))
        {
            w[j][k]=s[i];
            is_word=1;
            k++;
            num++;  //单独计数，不让末尾的标点或空格影响数量
        }
        else if(is_word==1&&(s[i]<='z'&&s[i]>='a')||(s[i]<='Z'&&s[i]>='A'))
        {
            w[j][k]=s[i];
            is_word=1;
            k++;
        }
        else if((s[i]>'z'||s[i]<'a')&&(s[i]>'Z'||s[i]<'A')&&is_word==1)
        {
            w[j][k]='\0';
            k=0;
            j++;
            is_word=0;
        }
    }
    w[j][k]='\0';
    for(i=0;i<=j;i++)
    {
        printf("%s ",w[i]);
    }
    printf("\n分出了%d个单词\n",num);

}

int main()
{
    int n;
    int i;
    while(scanf("%d",&n)!=-1)
    {
        char str[n][1000];
        getchar();//getchar();  //锐格系统要吸收两次
        for(i=0;i<n;i++)
        {
            gets(str[i]);
        }
        for(i=0;i<n;i++)
        {
            split(str[i]);
        }
    }
    return 0;
}

这是C语言阶段考的一道题目，对于一串字符，提取其中的数字。
要求：1.开头遇到空格要跳过。2.开头遇到'+'或'-'就当作符号。3.遇到非数字就结束。（看成了提取其中的数字，本题就是是简化了）
1.用getchar（）逐个读取并实时处理。
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,s=1;
    char c;
    c=getchar();
    while(c=='')            //对于开头是空格就跳过。
    {
        c=getchar();        //开头是空格不能忽视，要表达出来。
    }
    if(c=='+')
        s=1;                //用好标志量，而不是用体积很大的条件分支。这一点很重要，以后要多用。
    else if(c=='-')
        s=-1;               //用一个标志变量来存储+1和-1来决定最后输出的数正负号，而不是对最后的printf进行条件分支(麻烦至极)。
    while(c!='\n')          
    {
        if(c<'0'||c>'9')
        break;
        n=n*10+c-'0';       //将一个一个提取出来的数字整合为一个多位整数的算法，而不是用数组一个一个存数字然后再*10^n(极其笨的方法)。
        c=getchar();
    }
    printf("%d",s*n);
    return 0;
}
2.用函数传指针形式处理
#include <stdio.h>
#include <stdlib.h>
int func(char *s)
{
    int sum=0,f=1;
    while(*s == ' ')
    {
        s++;
    }
    if(*s == '+')
        f=1;
    else if(*s == '-')
        f=-1;
    else if(*s<='9' && *s>='0')
        sum=*s-'0';
    else
        return 0;
    s++;
    while(*s != '\0')
    {
        if(*s<='9' && *s>='0')
            sum = sum*10 + (*s-'0');
        else
            break;
        s++;
    }
    return sum*f;
}
int main()
{
    char a[50];  //如果定义成char* a;则出现错误；
    while(scanf("%s",a)!=-1) //如果用gets()如何实现多组数据输入?
    {
        printf("%d\n",func(a));
    }
    return 0;
}

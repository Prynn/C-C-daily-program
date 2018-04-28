先举一个犯过的错误例子！！！：
#include <stdio.h>
#include <string.h>
char * retstring();
int main()
{
    char * name2;
    name2 = retstring();
    printf("%s\n",name2);
    return 0;
}
char * retstring()
{
    char name[10];
    strcpy(name,"prynn");
    return name;
}
warn:retstring函数中字符数组name是一个局部变量，当函数执行完毕之后name的地址也将消失，所以返回name数组的首地址是无效的；

以下4种方法：
1)将要返回的字符串指针作为参数传入，并返回该指针。（需要在主函数中额外定义此指针）
char* strcpy(char* des,const char* source)  //函数strcpy源码；
{
    char* r=des;
    assert((des != NULL) && (source != NULL));
    while((*r++ = *source++)!='\0');
    return des;
}

2)函数中使用malloc动态分配空间，但是一定要注意在主调函数中将其释放，应为malloc动态分配的内存位于堆区，而堆区的内存是要程序员自己释放的。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * retstring();
int main()
{
    char * name2;
    name2 = retstring();
    printf("%s\n",name2);
    //记住一定要用free释放，否则会造成内存泄露
    free(name2);
    return 0;
}
char * retstring()
{
    char * name;
    name = (char *)malloc(10);
    strcpy(name,"张汉青");
    return name;
}
3.返回一个静态局部变量。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * retstring();
int main()
{
    char * name2;
    name2 = retstring();
    printf("%s\n",name2);
    return 0;
}
char * retstring()
{
    static char name[10];  创建静态局部变量；
    strcpy(name,"张汉青");
    return name;
}
4.使用全局变量
char   g_s[100]; 
char*   fun() 
{ 
        strcpy(g_s,   "abc "); 
        return   g_s; 
} 

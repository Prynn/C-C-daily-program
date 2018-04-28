1.用函数返回字符串
错误例子！！！：
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
    strcpy(name,"汉青");
    return name;
}
retstring函数中字符数组name是一个局部变量，当函数执行完毕之后name的地址也将消失，所以返回name数组的首地址是无效的；

以下4种方法：
1)将要返回的字符串指针作为参数传入，并返回该指针。（需要在主函数中额外定义此指针）
char* strcpy(char* des,const char* source)  //函数strcpy源码；
{
    char* r=des;
    assert((des != NULL) && (source != NULL));
    while((*r++ = *source++)!='\0');
    return des;
}

！！！令讨论创建字符数组和字符指针的关系:
int main()
{
    char a[50];
    scanf("%s",a);
    char *r = a;   都是指针，可以直接赋值；//这句话是错的，只能用字符数组名字给字符指针赋值，反过来不行
    r[3] = '\0';   赋值之后，r和a指向同一个地址，所以修改r就是修改a；
    printf("%s",a);
    return 0;
}
而以下代码出现错误：
int main()
{
    char a[50];
    char *r;
    scanf("%s",r);  只是定义了字符指针r，而没有开辟空间和赋值
    printf("%s",r); 同样错误；
    a = r;          必须使用 strcpy(a, r);
    printf("%s",a);
    return 0;
}
对于字符指针可以直接赋值：r = "abcdef";
而对于字符数组必须使用string.h中的strcpy();进行赋值

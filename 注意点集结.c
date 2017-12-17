1.printf 输出时 \" 表示"     \\表示\   %%表示%
2."字符"的输入和输出：
    定义 char ch;
    1)scanf("%c",&ch);  不会跳过空白字符，若第一个输入字符是" ",则存储在 ch 里字符就是空格；
    2)getchar()是读入一个字符并将其返回，所以必须使用赋值将其存储在变量中：ch=getchar();   返回的是int型数值，同时也不会跳过空格；
            示例：while((ch=getchar())==' ') ;   //此语句将把第一个非空格字符存储在ch中；
3.bool型函数返回值应该是true或false；不是0或1；
4.数组作参数：
       定义：int func(int a[])  //通常不说明数组长度；
       声明：int func(int [])  //简写形式；
       使用：    func(b);     //使用时没有[];
5.字符串
    1)'\0' 和 NULL(大写) 暂时先看成是一样；
    2)定义：   char *p; p="abc";       
               *p="def";//用指针定义不能够修改；
              char p[]="abc";//可以修改；若char p[100]="abc";那么余下的空间全是'\0';
    3)字符串的读写：
            char str[10];
            scanf("%c",str);//不需要&，str是数组名，把str当作指针来处理；scanf会跳过空白符并直到遇到空白符为止，并在末尾自动补加'\0'；
                            //scanf读入的字符串永远不包含空白字符；
            gets(str);//不会跳过空白字符，并且只遇到换行符才停止，空格不停止；
    4)<string.h>中包含的常用函数：
      (1)计算长度strlen:
                int len;    len=strlen("abc");
                char a[10]="abc";   len=strlen(a);//不包括'\0';
      (2)复制strcpy:
                strcpy(str1,str2); //将str2复制给str1,返回值是str1;
                strcpy(str1,"abcd");//str1 = "abcd";这是错的；
                strcpr(str1,strcpy(str2,"abcd"));//利用返回值；
      (3)拼接strcat:
                strcat(str1,"abc");//返回拼接后的字符串；
                strcat(str1,str2);    
      (4)比较strcmp:
                strcmp(str1,str2);//依据ASCII码，返回值>0,<0,=0;
6.scanf
    多组数据输入：
        k=scanf("%d",&n);
        while(k!=-1)
        {
         //数据处理主体
        }
        while(scanf("%d",&n)!=EOF) 和 while(scanf("%d",&n)!=-1) 一样;
     /*scanf 函数的返回值反映的是按照指定的格式符正确读入的数据的个数。
     如果输入数据与指定格式不符，则会产生输入错误。遇到输入错误，scanf函数会立即终止，返回已经成功读取的数据的个数。*/
      gets()返回首地址
 7.随机数，随机种子
    #include<time.h>
    int main()
    {
        srand(time(0));
        for(int i=0;i<10;i++)
            printf("%3d",rand()%100+1);
        printf("\n");
        return 0;
    }
    

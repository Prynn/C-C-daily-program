多组数据输入：
k=scanf("%d",&n);
while(k!=-1)
{
  //数据处理主体
}
while(scanf("%d",&n)!=EOF) 和 while(scanf("%d",&n)!=-1) 一样

scanf ：当遇到回车，空格和tab键会自动在字符串后面添加’\0’，但是回车，空格和tab键仍会留在输入的缓冲区中。
gets：可接受回车键之前输入的所有字符，并用’\n’替代 ‘\0’.回车键不会留在输入缓冲区中

gets(s); 
其中s为字符串变量（字符串数组名或字符串指针）。

gets(s)函数与scanf(“%s”,s)相似，但不完全相同，
使用scanf(“%s”,s) 函数输入字符串时存在一个问题，就是如果输入了空格会认为字符串结束，空格后的字符将作为下一个输入项处理，
但gets()函数将接收输入的整个字符串直到遇到换行为止。 
也就是说：gets()函数读取到\n（我们输入的回车）于是停止读取，但是它不会把\n包含到字符串里面去。
然而，和它配合使用的puts函数，却在输出字符串的时候自动换行。

 scanf("%s%d%d %c %c%d", stu[i].name, &stu[i].final_score, &stu[i].class_score, &stu[i].leader_or_not,  &stu[i].west_or_not,&stu[i].paper_num);
//这里只有char的输入需要在格式控制里面给空格  其他会自动将空格视为空；

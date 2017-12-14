#include <stdio.h>
#include <stdlib.h>
#define LEN 100
int main()
{
   char array[LEN];
   int count[LEN];
   int i,is_one_ahead; //is_one_ahead:记录前一个字符是否为1
   int tail; //count数组的有效最末下标
   while(gets(array)!=NULL)
   {
      for(i=0;i<LEN;i++)
        count[i] = 0;
      i = 0;
      is_one_ahead = 1;
      tail = -1;
      while(1)
      {
         //start
        if(array[i] != '\0')    //这里 if (array[i] != NULL) 也通过
        {
        if(array[i]==is_one_ahead)
            count[tail]++;
        else
            {tail++;
            count[tail]++;}
        is_one_ahead=array[i];
        }
         //end
         else 
            break;
         i++;
      }
      for(i=0;i<=tail;i++)
        i<tail ? printf("%d ",count[i]) : printf("%d\n",count[i]);
   }
   return 0;
}

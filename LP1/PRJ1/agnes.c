 #include <stdio.h>
 #include <string.h>
 int main()
 {
     char pal,num;
     int i, cont;
     cont =0;
     while (num != '\n')
     {
         num=getchar();
         if (num == '1')
         {
        		cont=(cont*2)+1;
         }
     		else if (num =='0')
     		{
     		    cont=cont*2;
     		}
     }
     printf("%d\n",cont);
 }
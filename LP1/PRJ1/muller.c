#include <stdio.h>
#include <string.h>

void main(void){
  char num;
  unsigned long int cont = 0;
  
  while ((num=getchar()) != '\n'){
    if (num == '1'){
      cont=(cont*2)+1;
    } else if (num =='0'){
      cont=cont*2;
    }
  }
  
     printf("%ld\n",cont);
 }
// ler um número binário sem sinal usando getchar
// e imprimí-lo convertido para decimal.

// recomendo que não esquente com o getchar inicialmente;
// crie uma array de chars com número e converta-o; tipo
// char binary[]= '0001'; int i = 0;
// for(i = 0; i < strlen(binary); i++){
//    ?????
//}
// deste jeito se preocupa só com a conversão primeiro,
// e com o getchar depois.

// convertendo decimais para binários:
// -- comece considerando que o valor do número é zero
// -- caminhe da esquerda para direita
// -- quando encontrar 0, valor = valor * 2
// -- quando encontrar 1, valor = valor * 2 + 1

 #include <stdio.h>
 int main()
 {
     char n;
     long long cont=0;
     
     while (n != '\n') 
     {
         n=getchar();
         if (n == '1')
         {
             cont=(cont*2)+1;
         } else if (n == '0') 
         {
          cont=cont*2;
         }
    
         }
     printf ("%lld\n", cont);
     return 0;
 }
         
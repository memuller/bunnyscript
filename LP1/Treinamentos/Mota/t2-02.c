// Fazer um programa em C leia uma idade I (inteiro positivo) e informe se ela está compreendida entre 10 e 18 anos 
// (inclusive).

#include <stdio.h>

int main()
{
    int i;
    
    scanf("%i", &i);
    if (i<0)
    {
        printf("A IDADE DEVE SER MAIOR OU IGUAL A ZERO");
    } else if (i<10 || i>18)
    {
        printf("NAO");
    } else {
        printf("SIM");
    }
    return 0;
}
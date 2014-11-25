// Fazer um programa em C leia um número inteiro positivo N e informe se o número é divisível por 3 e 6.

#include <stdio.h>

int main()
{
    int n;
    
    scanf("%i", &n);
    if (n<0)
    {
        printf("O NUMERO DEVE SER MAIOR OU IGUAL A ZERO");
    } else if ( n%3 == 0 && n%6 == 0) {
        printf("SIM");
    } else {
        printf("NAO");
    }
    return 0;
}
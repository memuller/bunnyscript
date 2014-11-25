// Fazer um programa em C leia o valor do empréstimo E (double), a taxa de juros percentual J (double) e a 
// quantidade de meses M (inteiro positivo) e calcule o valor da dívida após M meses, com uma taxa de juros de 
// M% ao mês.

#include <stdio.h>
#include <math.h>

int main()
{
    int m, BOOL=1;
    double e, j;
    
    scanf("%lf", &e);
    if (e<0)
    {
        printf("O VALOR DO EMPRESTIMO NAO PODE SER NEGATIVO");
        BOOL=0;
    }
    scanf("%lf", &j);
    if (j<0 && BOOL==1)
    {
        printf("A TAXA DE JUROS NAO PODE SER NEGATIVA");
        BOOL=0;
    }
    scanf("%i", &m);
    if (m<0 && BOOL==1)
    {
        printf("A QUANTIDADE DE MESES NAO PODE SER NEGATIVA");
        BOOL=0;
    }
    
    if (e >= 0 && j >= 0 && m >= 0)
    {
        e=e*pow(1+(j/100), m);
        printf("%lf", e);
    }
    return 0;
}
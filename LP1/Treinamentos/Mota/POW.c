// Fazer um programa em C leia o valor do empréstimo (double) e calcule o valor da divida após 6 meses,
// com uma taxa de juros de 5% ao mês.

#include <stdio.h>
#include <math.h>

int main()
{
    double empr, juros;
    scanf("%lf", &empr);
    if (empr < 0)
    {
        printf("O VALOR DO EMPRESTIMO NAO PODE SER NEGATIVO\n");
    } else {
    	juros=pow(1.05, 6);
    	empr=empr*juros;
    	printf("%.2lf", empr);
    }
    return 0;
}
// Fazer um programa em C leia o valor do salário mínimo M e o valor do salário S de um funcionário e diga quantos 
// salários mínimos o funcionário ganha.

#include <stdio.h>

int main()
{
    double m, s, aux;
    
    scanf("%lf", &m);
    scanf("%lf", &s);
    
    if (m <= 0)
    {
        printf("O SALARIO MINIMO DEVE SER MAIOR QUE ZERO");
    } else if (s < m) {
        printf("O SALARIO DO FUNCIONARIO NAO PODE SER MENOR QUE O MINIMO");
    } else {
        aux=(s/m);
        printf("%.2f", aux);
    }
    return 0;
}
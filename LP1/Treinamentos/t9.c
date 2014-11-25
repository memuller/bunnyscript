// Fazer um programa em C leia os dois catetos A e B de um triângulo retângulo e imprima na tela a sua hipotenusa.

#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, hip, aux;
    
    scanf("%lf", &a);
    scanf("%lf", &b);
    
    if (a < 0 || b < 0)
    {
        printf("NENHUM CATETO PODE SER NEGATIVO"); 
    } else {
        aux=pow(a,2) + pow(b,2);
        hip=sqrt(aux);
        printf("%.2lf", hip);
    }
    return 0;
}
         
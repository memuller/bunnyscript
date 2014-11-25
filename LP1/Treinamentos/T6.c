// Fazer um programa em C que leia o lado L (double) de um quadrado e imprima na tela o seu perímetro,
// área e diagonal.

#include <stdio.h>
#include <math.h>

int main()
{
    double l, pr, area, diag;
    
    scanf("%lf", &l);
    if (l<0)
    {
        printf("O LADO NAO PODE SER NEGATIVO");
    } else {
        pr = 4*l;
        area = pow(l,2);
        diag=l*sqrt(2);
        printf("%.2lf\n", pr);
        printf("%.2lf\n", area);
        printf("%.2lf", diag);
    }
    return 0;
}
        
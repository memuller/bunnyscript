// Fazer um programa em C leia o raio R (double) de um círculo e imprima na tela o seu perímetro e área.

#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979

int main()
{
    double r, pr, area;
    scanf("%lf", &r);
    if (r<0)
    {
        printf("O RAIO NAO PODE SER NEGATIVO");
    } else {
        pr=2*PI*r;
        area=PI*pow(r,2);
        printf("%.2lf\n", pr);
        printf("%.2lf", area);
    }
    return 0;
}
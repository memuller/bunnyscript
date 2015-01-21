// Fazer um programa em C leia a base B (double) e a altura H (double) de um retângulo e imprima na tela o 
// seu perímetro, área e diagonal

#include <stdio.h>
#include <math.h>

int main()
{
    double b, h, pr, area, diag, x;
    
    scanf("%lf", &b);
    scanf("%lf", &h);
    if (b<0)
    {
        printf("A BASE NAO PODE SER NEGATIVA");
    } else if (h<0) {
        printf("A ALTURA NAO PODE SER NEGATIVA");
        } else {
    			pr=2*b+2*h;
    			printf("%.2lf\n", pr);
    			area=b*h;
    			printf("%.2lf\n", area);
    			diag=sqrt(pow(b,2) + pow(h,2));
    			printf("%.2f\n", diag);
    }
    return 0;   
}
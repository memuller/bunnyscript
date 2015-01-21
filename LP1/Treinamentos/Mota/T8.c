// Fazer um programa em C leia os três lados L1, L2 e L3 de um paralelepípedo retângulo e imprima 
// na tela a área total de suas faces, o seu volume e sua diagonal.

#include <stdio.h>
#include <math.h>

int main()
{
    double l1, l2, l3, area, vol, diag, aux;
    
    
    scanf("%lf", &l1);
    scanf("%lf", &l2);
    scanf("%lf", &l3);
    if (l1 < 0 || l2 < 0 || l3 < 0)
    {
        printf("NENHUM LADO PODE SER NEGATIVO");
    } else {
        area=2*((l1*l2)+(l1*l3)+(l2*l3));
        vol=l1*l2*l3;
        aux=pow(l1,2) + pow(l2,2) + pow(l3,2);
        // diag=sqrt(pow(l1,2) + pow(l2,2) + pow(l3,2));
        diag=sqrt(aux);
        printf("%.2lf\n", area);
        printf("%.2lf\n", vol);
        printf("%.2lf", diag);
    }
    return 0;
}
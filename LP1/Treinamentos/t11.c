// Fazer um programa em C leia a razão R  de uma PG, seu primeiro termo P e o valor N e cacule o n-ésimo termo da PG.
// R, P e N são todos inteiros.

#include <stdio.h>
#include <math.h>

int main()
{
    int r, p, n, tn, aux;
    
    scanf("%i", &r);
    scanf("%i", &p);
    scanf("%i", &n);
    if (n<0)
    {
        printf("A QUANTIDADE DE TERMOS DEVE SER MAIOR QUE ZERO");
    } else {
        n=n-1;
        aux=pow(r, n);
        tn=p*aux;
        printf("%i", tn);
    }
    return 0;
}
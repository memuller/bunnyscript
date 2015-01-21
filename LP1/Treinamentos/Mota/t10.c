// Fazer um programa em C leia a razão R  de uma PA, seu primeiro termo P e o valor N e cacule o n-ésimo termo da PA. 
// R, P e N são todos inteiros.

#include <stdio.h>
#include <math.h>

int main()
{
    int r, p, n, tn;
    
    scanf("%i", &r);
    scanf("%i", &p);
    scanf("%i", &n);
    
    if (n < 0)
    {
        printf("A QUANTIDADE DE TERMOS DEVE SER MAIOR QUE ZERO");
    } else {
        tn=p + (r*(n-1));
        printf("%i", tn);
    }
    return 0;
}
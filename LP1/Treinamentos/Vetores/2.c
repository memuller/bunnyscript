/* Faça um programa em C que peça ao usuário duas notas que ele tirou 
e mostre a média.
Use vetores! Aliás, use somente um vetor para essas três variáveis. */

#include <stdio.h>

void main()
{
    int i, aux, vetor[3];
    for (i=0; i<3; i++)
    {
        printf("Digite a nota: ");
        scanf("%i", &aux);
        vetor[i]=aux;
    }
    vetor[2]=(vetor[1]+vetor[0])/2;
    printf("A média é: %i", vetor[2]);
}
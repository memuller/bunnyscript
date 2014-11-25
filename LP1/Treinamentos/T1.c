// Fazer um programa em C que leia um número inteiro e escreva na tela o seu antecessor e sucessor.

#include <stdio.h>

int main()
{
    int i, a, s;
    scanf("%i", &i);
    a=i-1;
    s=i+1;
    printf("%i\n", a);
    printf("%i", s);
    return 0;
}
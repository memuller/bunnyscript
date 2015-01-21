// Fazer um programa em C que leia dois nu´meros e escreva o dividendo, divisor, quociente e resto

#include <stdio.h>

int main()
{
    int n1, n2;
    scanf("%i", &n1);
    scanf("%i", &n2);
    if (n1 > n2)
    {
        printf("%i\n", n1);
        printf("%i\n", n2);
    } else if (n2 > n1)
    {
        printf("%i\n", n2);
        printf("%i\n", n1);
    }
    printf("%i\n", n1/n2);
    printf("%i", n1%n2);
	 return 0;
}
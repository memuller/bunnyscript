/* # ATIVIDADE 2
    altere esta função de fatoração para que ela imprima, junto com o resultado, a quantidade de etapas 
    de fatoração realizadas. */
    
#include <stdio.h>
#include <math.h>

void fatorar(int num)
{
    static int i=2, cont=0;
    int lim;
    lim=sqrt(num);
    while  (num > 1 && i < lim)
    {
        if (num%i == 0)
        {
            printf("%i\n", i);
            num=num/i;
            fatorar(num)
            cont+=1;
        } else {
            i+=1;
        }
    }
    printf("O número de múltiplos é: %i", cont);
}

int main()
{
    int num;
    scanf("%i", &num);
    fatorar(num);
    return 0;
}


#include <stdio.h>
#include <math.h>

void fatorar(int num)
{
    static int i=2;
    int lim;
    lim=sqrt(num);
    while  (num > 1 && i < lim)
    {
        if (num%i == 0)
        {
            printf("%i\n", i);
            num=num/i;
            fatorar(num);
        } else {
            i+=1;
        }
    }
}

// i varia, num varia, lim não

int main()
{
    int num;
    scanf("%i", &num);
    fatorar(num);
    return 0;
}
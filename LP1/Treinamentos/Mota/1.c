/* # ATIVIDADE 1
    crie uma função recursiva que fatore um número passado como parâmetro, e imprima o resultado.
    o número deve ser lido do usuário, no programa principal.
    caso já tenha feito funções de fatoração recursivas, copie-a. */
    

#include <stdio.h>
#include <math.h>

void fatorar(int num)
{
    static int i=2, cont=0;
    float lim;
    lim=sqrt(num);
    while  (num > 1 && i <= lim)
    {
        if (num%i == 0)
        {
            printf("%i\n", i);
            num=num/i;
            cont+=1;
            fatorar(num);
        } else {
            i+=1;
        }
    }
    printf("i:%i, num: %i, cont: %i\n", i, num, cont);
    if (num==i)
    {
        //printf("O número de múltiplos é: %i\n", cont);
    }
}

int main()
{
    int num;
    scanf("%i", &num);
    fatorar(num);
    return 0;
}
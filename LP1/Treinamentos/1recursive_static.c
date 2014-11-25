/*
    # ATIVIDADE 1
    crie uma função recursiva que fatore um número passado como parâmetro, e imprima o resultado.
    o número deve ser lido do usuário, no programa principal.
    caso já tenha feito funções de fatoração recursivas, copie-a.


    # VARIAVEIS ESTATICAS
    Variáveis estáticas tem seu valor preservado quando o "bloco" de código (por exemplo, uma função) 
    em que estão é executado múltiplas vezes.
    
    Não confundir com "elas não mudarem" (isso seria uma constante).
    Variáveis estáticas são úteis, por exemplo, em métodos recursivos; pois elas não serão 
    "reiniciadas" com cada chamada do método.
    
    Declare variáveis estáticas adicionando static antes de sua declaração.
    static integer i = 0;


    # ATIVIDADE 2
    altere esta função de fatoração para que ela imprima, junto com o resultado, a quantidade de etapas 
    de fatoração realizadas.
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int some(int value){
    value ++;
    printf("%i\n", value);
    if(value < 3 ){
        some(value);
    }
}
void main(){
    printf("Eu agora irei contar até 3.\n");
    some(0);
}



// int fatorar(int num)
// {
//     int pr=1, i, n;
//     n=sqrt(num);
//     while (num%i == 0)
//     {
//         num=num/i;
//         printf("%i\n", num);
//         i+=1;
//     }
//     fatorar(num);
//     return 0;
// }
 
        
/* for (i=2; i<n; i++)
    {
        while (num%i == 0)
        {
            num=num/i;
            printf("%i\n", num);
        }
    }
*/


// para i começando em 2, enquanto i for menor que a raiz do número, i++
//    enquanto número % 0 == 0
//        numero = numero / i
//        ...e isso é um fator.


// int main()
// {
//     int num;
//     scanf("%i", &num);
//     fatorar(num);
//     return 0;
// }


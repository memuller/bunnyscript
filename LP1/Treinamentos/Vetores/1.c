/* Faça um programa que peça 3 números inteiros ao usuário, armazene
em um vetor, depois mostre o valor de cada elemento do vetor, assim 
como seu índice. */


/*
    *variavel = o valor contido no endereço de memória contido nesta variavel
    &variavel = o endereço de memória desta variável
    
    
    & - leia como "o endereço de memória de..."
    o &variavel retorna o endereço de memória onde aquela variável está.
    você vai usar ele quando precisar "apontar" para esta variável.
    sempre o usará com variáveis reais também - tipo, não faz sentido usar 
    &variavel se a variável em questão for do tipo ponteiro, pois isso vai te retornar...
    o endereço de memória onde o ponteiro do ponteiro está armazenado (??) o que é bullshit.
    
    char texto[50] = "I kiss dudes";
    printf("%d", &texto); // vai imprimir um inteiro bizarro, que é o endereço de memória onde
    // este array de chars está.
    
    
    ARRAYS SEREM BULLSHIT
    
    C não tem array também. ele te ilude só.
    na prática, um array é um endereço de memória + a informação do tamanho de cada elemento dele + quantos tem.
    
    por exemplo, 
    int numeros[5]; 
    este array na prática é o endereço de memória onde o primeiro elemento vai ser armazendo,
    a informação de que são inteiros - logo, cada um possui 8bytes
    e que existirão cinco elementos.
    
    o ponto é que, por exemplo, caso você queira acessar o segundo elemento de um array "manualmente",
    você poderia só acessar o endereço de memória
    [posição do primeiro elemento] + 8
    ...sendo oito o tamanho de uma variável do tipo inteiro em bytes, right.
    tipo, cada elemento do array na prática está na posição de memória
    [posição do primeiro elemento] + [tamanho de cada elemento] * [numero do elemento-1]
    
    ...got it?

*/
#include <stdio.h>

int * leitura()
{
    int i, aux=0;
    static int vetor[3];
    for(i=0; i<3; i++)
    {
        scanf("%i", &aux);
        vetor[i]=aux;
    }
    return vetor;
}

void main()
{
    int i;
    int *array;
    array=leitura();
    
    for(i=0; i<3; i++)
    {
        printf("%i é o valor do slot %i\n", array[i], i);
    }
}

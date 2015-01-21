/* Trab5 - Crivo de Eratóstenes
Due date: sexta, 9 janeiro 2015, 20:00
Maximum number of files: 1
Type of work: Individual work
Trab5 - Crivo de Erastótenes
O Crivo de Eratóstenes é um algoritmo que provê um método simples e prático para se 
encontrar todos os números  primos menores que um certo valor limite N. 
Para implementá-lo na linguagem C precisamos de um array. Cada posição deste array pode 
conter dois valores, 1 (um), caso o número correspondente ao índice do array seja primo, 
e 0 (zero), caso não. O array deve ser inicializado com todos os valores dos elementos 
iguais a 1. As exceções são os valores dos índices 0 e 1 do array, que são inicializados 
com zero uma vez que sabe-se de antemão que os números zero e um não são primos. 
A implementação do algoritmo é iterativa, percorrendo o array de números dos índices 2 
até N. Para cada número primo encontrado todos os seus múltiplos são marcados com não 
primos. Ao final do algoritmo, sobram apenas com valores iguais a um os índices do vetor
relativos aos números primos. 
Entrada: Seu programa deve receber através do teclado o valor limite N. (N não será em
hipótese alguma maior do que 1000)
Saída: Seu programa deve imprimir na tela os valores dos números primos menores que N 
separados de um caracter espaço.
Restrições:
1) O array usado para o cálculo do crivo deve ser alocado dinamicamente em função do 
tamanho da entrada.
2) Os laços da sua implementação do ALGORITMO DE CÁLCULO DO CRIVO DE ERATÓSTENES devem 
ter o menor número de iterações possível.
3) Todas as iterações com o array devem obrigatoriamente utilizar aritmética de 
apontadores. */

#include <stdio.h>
#include <stdlib.h>

/*
    THE SIEVE
    Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
    Initially, let p equal 2, the first prime number.
    Starting from p, enumerate its multiples by counting to n in increments of p, and mark them in the list (these will be 2p, 3p, 4p,...,np.; the p itself should not be marked).
    Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.

    When the algorithm terminates, all the numbers in the list that are not marked are prime.

    http://upload.wikimedia.org/wikipedia/commons/b/b9/Sieve_of_Eratosthenes_animation.gif
*/


// fills every position of given array, of given size, with a given value.

void fill_with(int *array, int size, int content){
    int i = 0;
    while(i < size){
        *(array+i) = content;
        i++;
    }
}

// prints all indexes and values of a given array, of given size.
// for debug purposes.
void print_all(int *list, int size){
    int i = 0;
    while(i < size){
        printf("%i: %i\n", i, *(list+i));
        i++;
    }
    
}

// prints, from a given array of given size, the indexes of all itens whose
// value is 1.
void print_primes(int *list, int size){
    int i = 0;
    while(i < size){
        if(*(list+i) == 1){
            printf("%i ", i);
        }
        i++;
    }
}

void main (){
    int limit ;
    int *numbers;
    int p, i ;
    
    
    // Reads the limit.
    printf("Exibir primos até? ");
    scanf("%i", &limit);
    limit ++; //counter starts at zero, so...
    
    // allocates the numbers array
    numbers = (int*) malloc(limit * sizeof(int));
    
    // fills all positions with 1s.
    // that is, for now all numbers are unmkared/considered primes.
    fill_with(numbers, limit, 1); 
    
    // we're pretty sure 0 and 1 are not primes; mark them.
    *(numbers) = 0; *(numbers+1) = 0;
    
    p = 2; i = 0; // we start from 2 onwards.
    
    while(i < limit){ // while we haven't reached the limit yet...
        
        // starting from p, marks all numbers using p-sized steps.
        // that is, marks all multiples of p.
        i = p;
        while(i < limit){
            i += p;
            *(numbers+i) = 0;
        }
        
        // finds the next p; which is the first unmarked number
        // greater than p.
        i = p+1;
        while(i < limit){
            if(*(numbers+i) != 0){
                p = i;
                break;
            }
            i++;
        }
    }
    
    // prints.
    print_primes(numbers, limit);
    
}
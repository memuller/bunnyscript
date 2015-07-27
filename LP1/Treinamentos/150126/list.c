/*
Dado um arquivo de texto 'amor', escreva um programa que imprima todas as palavras nele 
contidas, em ordem alfabética, e a quantidade de vezes em que cada uma delas aparece.

Por exemplo:

a: 1
can: 1
defiance: 1
every: 1
feel: 1
hear: 1
I: 3
silence: 1
speak: 1
you: 1
when: 1
word: 1

*/

/*


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct palavra {
    char palavra[20];
    int qtd;
    struct palavra * proxima;
};
/*

no programa, cada palavra é representada por um struct com os componentes
    palavra, uma string com o texto da palavra propriamente dita
    quantidade, um inteiro com a quantidade de vezes no qual a palavra apareceu
    proxima, um ponteiro para a próxima palavra se houver (do contrário, 0)


que haja um ponteiro para struct do tipo palavra chamado lista;

após abrir o arquivo de texto
para cada palavra presente no arquivo de texto
    leia a palavra e coloque em uma variável 
        
    



== IN THE END
no final devemos ter uma lista encadeada de palavras
onde cada elemento é um struct do tipo palavra
cada struct deve representar uma palavra diferente (terem valores diferentes no campo palavra)
a quantidade de vezes no qual a palavra apareceu deve estar contabilizada no campo quantidade

*/

/*
== CHAINED LIST
-----------         -----------         -----------
palavra             palavra             palavra
quantidade          quantidade          quantidade
proxima - - - - - > proxima - - - - - > proxima
-----------         -----------         -----------


*/



void main()
{
    FILE *texto;
    char word[50];
    
    struct palavra * lista = NULL; 
    
    
    texto=fopen("amor", "r");
    
    while(fscanf(texto, "%s ", word) == 1){
        printf("%s ", word);
        
        if(!lista){ //nada na lista. precisamos criar o primeiro elemento
            lista = malloc(sizeof(struct palavra)); //reservamos memória para o primeiro elemento e...
            // yay, fazemos lista apontar para ele.
            
            // colocamos os valores de coisas dentro deste struct
            strcpy(lista->palavra, word);
            lista->qtd = 1;
            lista->proxima = 0;
        }
        
        
    }
    
    fclose(texto);

    printf("\n==THE WORDS\n");
    printf("%s|%i ", lista->palavra, lista->qtd);

}

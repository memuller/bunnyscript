/*
Escreva um programa que produza, o índice remissivo de um arquivo texto. O nome do arquivo a ser analisado será fornecido pelo teclado. Cada palavra deve conter somente letras. Caracteres numéricos, espaços, tabs, vírgulas etc devem ser considerados separadores de palavras. Além disto, todas as letras minúsculas devem ser convertidas para maiúsculas. O índice remissivo deve se apresentar da seguinte forma: cada palavra encontrada deve ser apresentada em letra maiúscula, sucedida pelo caracter : + espaço + linha de ocorrência + vírgula + espaço + linha de ocorrência + vírgula + espaço + linha de ocorrência e assim por diante.

Seu programa deve, a cada palavra encontrada no texto, verificar se a mesma já fora encontrada. Caso ainda não tenha ocorrido, a mesma deve ser acrescentada à estrutura de dados do índice remissivo. Em linhas gerais, a estrutura de dados do índice é uma árvore binária não balanceada contendo as palavras (sem repetição) em ordem alfabética. Cada palavra possui uma lista encadeada com os números das linhas onde a referida palavra ocorrera. Para uma dada palavra a lista de números de linha deve ser mantida em ordem crescente e não deve conter repetições.  Ao fim, seu programa deve gerar o índice remissivo na tela do computador. Não deixe de liberar toda a memória alocada dinamicamente.
*/

/*
    * read each word with fscanf (whitespace, non-alpha)
    * capitalize them

    storage:
    binary, alpha-sorted unbalanced tree
        - each element is a chained list    
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){

    FILE * text;
    char word[50];
    int i = 0, c = 1;
    long pos = -1;

    text = fopen("text", "r");
    while(fscanf(text, "%[^0-9]", word) != EOF){
        if(pos == ftell(text)){
            fseek(text, 1, SEEK_CUR);
        }
        pos = ftell(text);
        printf("%s ", word);
        
        i++;
    }

    fclose(text);
}
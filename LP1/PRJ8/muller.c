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

struct Word {
    char id[50];
    struct Word *next;
    struct Pos *positions;
    int count;
};

struct Pos {
    int id;
    struct Pos *next;
};

void destroy_list(struct Word *node){
    if(node){
        destroy_list(node->next);
        free(node);
    }
}

struct Word * insert(char id[50], struct Word **node){
    struct Word *current = *node;
    if( ! *node){
        *node = (struct Word*) malloc(sizeof(struct Word));
        current = (*node);
    } else {
        while(current->next != 0){
            current = current->next;
        }
        current->next = (struct Word*) malloc(sizeof(struct Word));
        current = current->next;
    }
    strcpy(current->id, id);
    current->count = 0;
    current->next = 0;
    current->positions = 0;
    return current ;
}


struct Word * seek_or_insert(char id[50], struct Word **node){
    if(!*node){ return insert(id, node); }

    struct Word *current = *node;
    
    while(current->next != 0){
        if(strcmp(id, current->id) == 0){
            return current;
        }
        current = current->next;
    }

    return insert(id, node);
}

void add_position(int index, struct Word * word){
    struct Pos *current;
    if(word->positions == 0){
        printf("!");
        word->positions = (struct Pos*) malloc(sizeof(struct Pos));
        
        word->positions->id = index;
        word->positions->next = 0;
                
    } else {
        current = word->positions;
    }
    word->count++;

    printf("%s|%d ", word->id, word->count);

    //position->id = pos;
    
    //position->next = 0;
    
}


void main(){

    FILE * text;
    char word[50];
    int i = 0, c = 1, words = 0;
    long pos = -1;

    struct Word *root, *current;

    text = fopen("text", "r");
    while(fscanf(text, "%49[^0-9,. \n-]", word) != EOF){
        if(pos == ftell(text)){
            fseek(text, 1, SEEK_CUR);
            c++;
        } else {
            current = seek_or_insert(word, &root);
            add_position(c, current);

            words++;
            c += strlen(word);

        }
        pos = ftell(text);
    }

    fclose(text);

    current = root;
    while(current->next != 0){
        int pos;
        //printf("%d", current->positions);
        //if(current->positions){
           // struct Pos *temp = current->positions;
        //} else {pos = 0;}
        //printf("%s|%i ", current->id, pos);
        //printf("%s|%i ", current->id, current->count);
        current = current->next;
    }
}
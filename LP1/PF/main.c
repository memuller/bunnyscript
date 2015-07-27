#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No_Processo{
    int pid;
    int TempoRemanescente;
    struct No_Processo* proximo;
}

void insere(struct No_Processo* elemento, struct No_Processo* fila){
    struct No_Processo *atual = fila;
    // vai até o último elemento
    while(atual->proximo != 0){
        atual = atual->proximo;
    }
    // adiciona um novo último elemento
    atual->proximo = (struct No_Processo*) malloc(sizeof(struct No_Processo));
    atual = atual->proximo;
    
    //copia o elemento passado como parâmetro para lá
    atual->pid = elemento->pid;
    atual->TempoRemanescente = elemento->TempoRemanescente;
    
    //libera o elemento passado como parâmetro
    free(elemento);
}

// exclui o primeiro elemento de uma lita encadeada
void excluir(struct *No_Processo fila){
    struct No_Processo *primeiro = fila;
    // aponta fila para o segundo elemento
    fila = primeiro->proximo;
    // libera o primeiro elemento
    free(primeiro);
} 


void ler_pra_fila(char nome_arquivo[], struct *No_Processo fila){
    FILE *arquivo;
    
    // cria um struct temporário para receber os valores lidos
    struct No_Processo temp_processo;
    
    arquivo = fopen(nome_arquivo, "r");
    // lê do arquivo direto para o struct temporário
    while(fscanf(arquivo, "%i %i", &temp_processo.id, &temp_processo.TempoRemanescente) != EOF){
        insere(&temp_processo, fila); //usa a função criada anteriormente para inserir
    }
    fclose();
}

int ** matriz_ident(int dimensoes){
    int **matriz;
    int *valores;
    int i, j, c = 0;
    // aloca os valores
    valores = (int *) malloc(dimensoes * dimensoes * sizeof(int));
    //aloca o apontador funcionando como linha
    matriz = (int **) malloc(dimensoes * sizeof(int *));
    // faz os elementos de matriz apontarem para os valores
    // no início de cada linha
    for(i = 0; i < dimensoes; i++){
        matriz[i] = &(valores[i*dimensoes]);
    }
    
    //loop loop colocando os valores
    for(i = 0; i < dimensoes; i++){
        for(j = 0; j < dimensoes; j++){
            matriz[i][j] = c;
            c++;
        }
    }
    return matriz;
}

void main {
    
}
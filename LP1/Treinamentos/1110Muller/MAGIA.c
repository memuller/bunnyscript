/*
    Sabendo que o arquivo anos.txt é formatado da seguinte forma:
    1-1:1-1
    0-1:0-5
    1-0:5-0
    0-0:3-3
    leia cada valor individualmente, em cada linha, usando scanf.
*/

/* fscanf lê bytes de um arquivo usando um formato específico. a string do formato
 segue o mesmo padrão de costume - usado no printf e scanf.
 
 */
 
#include <stdio.h>
#include <stdlib.h>

void main(){
    FILE *anos;
    char teste[51];
    int idade;
    anos = fopen("anos2.txt", "r");
    // estas variáveis receberão os quatro números presentes em uma linha
    int primeiro, segundo, terceiro, quarto;
    
    // leio do stream "anos" algo formatado como descrito ali - %i-%i:%i-%i
    // os demais parâmetros são ponteiros para as variáveis que vão receber 
    // os valores lidos, na mesma ordem. parece o printf ao contrário
    fscanf(anos, "%[ -~] %i", teste, &idade);
    teste[50]='\0';
    
    // veja como deu certo.
    printf("li: %s %i", teste, idade);
    
    // assim como as demais funções de ler arquivo, é usado um ponteiro interno
    // e usos posteriores continuam da posição onde a última leitura terminou.
    // fscanf(anos, "%i-%i:%i-%i", &primeiro, &segundo, &terceiro, &quarto);
    // printf("\nli a segunda linha: %i, %i, %i, %i", primeiro, segundo, terceiro, quarto);
    
    fclose(anos);
    
    
}
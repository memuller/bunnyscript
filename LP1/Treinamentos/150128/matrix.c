/* Escreva um programa que, dado um número real fornecido pelo teclado,
imprima o resultado do produto teste número e da matriz M, contida no arquivo
matriz.txt

Utilize matrizes com alocação por linha.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
vetor 

*/

/*
    ponteiro do tipo de dados que você quer
    valor seria o endereço de memória alocado via malloc
    
    int *vetor = malloc(sizeof(int)*10);
*/
void main(){
    int rows = 3, collumns = 4, i, j;
    FILE * arq;
    
    
    int **matriz = malloc(sizeof(int *)*rows);
    
    for(i=0; i < rows; i++){
        matriz[i] = malloc(sizeof(int)*collumns);
    }

    int c = 0;
    
    arq = fopen("matriz.txt", "r");
    
    // matriz[row][collumn]
    int temp, row = 0, collumn = 0; // 4 linhas 
    while(fscanf(arq, "%i ", &temp) != EOF){
        collumn++;
        if(collumn > collumns){
            row++;
            collumn = 0;
        }
        matriz[row][collumn] = temp;
        
    }
    fclose(arq);
    
    for(i = 0; i < rows; i++){
        for(j = 0; j < collumns; j++){
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
    
    for(i=0; i < rows; i++){
        free(matriz[i]);
    }
    free(matriz);
}
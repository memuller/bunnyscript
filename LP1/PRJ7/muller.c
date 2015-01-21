/*
Trab 7 - Produto de Matrizes com alocação fragmentada por linhaEscreva um programa na 
linguagem C que calcule o produto de duas matrizes A e B, produzindo como saída A x B 
("A vezes B"). A matrizes A e B estão armazenadas na variante P2 do formato de arquivo 
de imagem PGM. Caso as dimensões das matrizes sejam incompatíveis, seu programa deve 
escrever em stdout a mensagem "Erro dimensoes incompatveis\n", caso contrário o 
programa deve escrever em stdout o resultado do produto expresso também no formato PGM 
variante P2. 
Seu programa receberá através de stdin duas linhas. Na primeira será fornecido o nome 
do arquivo relativo à matriz A e na segunda o nome do arquivo relativo à matriz B. 
Requisitos não funcionais do programa: 
1) Todas as matrizes devem ser alocadas usando o método de alocação fragmentada por linha
2) Ao final da execução a memória alocada dinamicamente deverá ser devidamente liberada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ** alloc_matrix(int ** map, int rows, int cols){
    int i;
    map = (int **) malloc(rows * sizeof(int *));
    for(i = 0; i < rows; i++){
        map[i] = (int *) malloc(cols *sizeof(int));
    }
    return map;
}

void clear_matrix(int ** map, int rows){
    int i;
    for(i=0; i < rows; i++){
        free(map[i]);
    }
    free(map);
}

int ** read_matrix(char filename[], int **map, int *rows, int *cols){
    int i, j, pixel; char line[200], *piece;
    FILE *file;
    file = fopen(filename, "r");
    
    i = 1;
    while(fgets(line, 200, file) != NULL){
        if(line[0] == '#'){ continue; }
        
        // rows and collumns
        if(i == 2){
            piece = strtok(line, " ");
            *rows = atoi(piece);
            piece = strtok(NULL, " ");
            *cols = atoi(piece);
        // levels
        } else if(i == 3){
            break;
        }
        i++;
    }
    
    map = alloc_matrix(map, *rows, *cols);
    
    i = 0; j = 0;
    while(fscanf(file, "%i ", &pixel) == 1){
        map[j][i] = pixel;
        i++;
        if(i == *cols){
            i = 0; j++; 
        }
    }
    
    fclose(file);
    return map;
}

void main(){
    char filename[50];
    int rows[2], cols[2], num_elements[2];
    int **a, **b, **p;
    int i, j, k;
    
    scanf("%s", filename);
    a = read_matrix(filename, a, &rows[0], &cols[0]);
    scanf("%s", filename);
    b = read_matrix(filename, b, &rows[1], &cols[1]);
    
    // a = read_matrix("originalPgmP2.1.pgm", a, &rows[0], &cols[0]);
    // b = read_matrix("originalPgmP2.1.pgm", b, &rows[1], &cols[1]);
    
    
    if(cols[0] != rows[1]){
        printf("Erro dimensoes incompativeis\n");
        return;
    }
    
    int temp ;
    for(i = 0; i < cols[0]; i++){
        for(j = 0; j < cols[0]; j++){
            temp = 0;
            for(k = 0; k < cols[0]; k++){
                temp += a[i][k] * b[k][j];
            }
            printf("%i ", temp);
        }
    }

    
    
    clear_matrix(a, rows[0]);
    clear_matrix(b, rows[1]);
    

    
}
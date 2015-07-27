/* Trab 6 - Mediana 1.0
Due date: sexta, 9 janeiro 2015, 21:00
Maximum number of files: 1
Type of work: Individual work
Trab 6 - Mediana 1.0
Faça um programa que calcule a mediana dos pixels de uma imagem no formato PGM subtipo P2.

Seu programa deve fazer as seguintes atividades:

Ler pelo teclado o nome da imagem de entrada.
Ler do arquivo PGM os valores dos pixels da imagem armazenando cada um numa posição de um
array (unidimensional) de inteiros com dimensão Cols x Linhas alocado dinamicamente. 
(OBS.: Os valores dos pixels estão entre 0 e 255)
Ordenar o array de pixels em ordem crescente (vc pode utilizar o algoritmo de ordenação
de sua preferência)
Obter no array ordenado o valor da mediana e imprimi-lo na tela do terminal.
Restrições:
1) O array de pixels deve  alocado dinamicamente em função do tamanho da entrada.
2) Todas as iterações com o array de pixels devem obrigatoriamente utilizar aritmética
de apontadores. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(){
    
    char filename[50];
    FILE *file;
    
    int rows, cols, levels, num_pixels;
    int pixel, temp ;
    int *pixels;
    
    int median;
    
    int i, j;
    
    char line[200];
    char *piece;
    
    //sprintf("WHAT IS A PGM IMAGE? ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    //file = fopen("originalPgmP2.pgm", "r");
    
    i = 1;
    while(fgets(line, 200, file) != NULL){
        if(line[0] == '#'){ continue; }
        
        // rows and collumns
        if(i == 2){
            piece = strtok(line, " ");
            rows = atoi(piece);
            piece = strtok(NULL, " ");
            cols = atoi(piece);
        // levels
        } else if(i == 3){
            levels = atoi(line);
            break;
        }
        i++;
    }
    
    num_pixels = cols * rows;
    pixels = (int*) malloc(num_pixels*sizeof(int));
    
    
    // reads the pixels.
    i = 0;
    while(fscanf(file, "%i ", &pixel) == 1){
        *(pixels+i) = pixel;
        i++;    
    }
    
    fclose(file);
    
    // bubble-sorts the pixel array
    for(i = 0; i < num_pixels -1; i++){
        for(j = 0; j < num_pixels -1; j++){
            if(*(pixels+j) > *(pixels+j+1)){
                temp = *(pixels+j);
                *(pixels+j) = *(pixels+j+1);
                *(pixels+j+1) = temp;
            }
        }
    }
    
    // if the number of pixels is even, the median is the middle value
    if(num_pixels % 2){
        median = *(pixels+num_pixels/2);
    
    // otherwise it's the average between the two middle values
    } else {
        median = (
            *(pixels+num_pixels/2) + *(pixels+num_pixels/2 -1) 
        ) /2 ;
    }
    
    printf("%i", median);
    
    
    
    
}
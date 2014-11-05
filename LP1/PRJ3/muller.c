#include <stdio.h>
#include <stdlib.h>


long int getFileSize(FILE *file){
    fseek(file, 0, SEEK_END);
    long int size = ftell(file);
    rewind(file);
    return size;
}


int main()
{
    
    FILE *pgm;
    
    int rows, cols, levels, size ;
    int i = 0, words = 0, line_count = 0;
    char * buffer, * o_buffer;
    char format[2];
    int in_comments = 0;
    int metadata_lines = 3;
    pgm = fopen("originalPgmP5.pgm", "rb");
    if (!pgm){ /* handle */ }
    long int file_len = getFileSize(pgm);
    
    buffer = (char*) malloc(sizeof(char)*file_len);
    
    fread(buffer, 1, file_len, pgm);
    fclose(pgm);
    buffer[1] = '5';
    for(i = 0; i < file_len; i++){
        unsigned char c = buffer[i];
        if(c == '#') { metadata_lines++;}
        if(c == '\n'){line_count++; printf("%c",'\n'); continue;}
        if(line_count > metadata_lines-1){
            printf("%u ",c);
        } else {
            printf("%c", c);
        }
        
    }

    
    
    //printf("%i x %i /%i %s", rows, cols, levels, type);
    
}
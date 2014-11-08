#include <stdio.h>
#include <stdlib.h>

// returns size of a file, in bytes.
long int getFileSize(FILE *file){
    fseek(file, 0, SEEK_END); //gets to last file byte
    long int size = ftell(file); //fetches how many bytes were walked
    rewind(file); //gets back to the beginning position
    return size;
}


int main()
{
    
    FILE *pgm;
    int i;
    char * buffer;
    char file_name[50];
    int rows, cols, at_char = 1 ;
    
    // we need to keep track of lines so we know when when to switch from printing
    // ASCII chars or their integer values.
    int line_count = 1;
    // normally a PGM file has three metadata lines with ASCII chars.
    int metadata_lines = 3;
    
    // reads filename.
    gets(&file_name);
    // opens the file.
    pgm = fopen(file_name, "rb");
    if (pgm == NULL){
        printf("%s", "Erro: arquivo inexistente\n");
        return 0;
        
    }
    // gets file size in bytes; them allocates a buffer for it. 
    long int file_len = getFileSize(pgm);
    buffer = (char*) malloc(sizeof(char)*file_len);
    
    // reads and closes the file.
    fread(buffer, 1, file_len, pgm);
    fclose(pgm);
    
    // changes the file format to P2.
    buffer[1] = '2';
    
    // loops on every byte of the buffer
    for(i = 0; i < file_len; i++){
        at_char++; 
        // a char.
        unsigned char c = buffer[i];
        // if it's a comment, we need to consider an additional line when
        // deciding where the metadata ends and the actual binary stuff starts.
        if(c == '#')  metadata_lines++; 
        // if it's a line break, count, print it and jumps to the next char.
        if(c == '\n'){ 
            line_count++; 
            printf("%c",'\n'); 
            continue;
            at_char = 0;
        }
        // if we're over the metadata section...
        if(line_count > metadata_lines){
            // ...them it means we're into the binary chars section
            // print their unsigned decimal values.
            printf("%u ",c); 
        } else {
            // otherwise it's still metadata. print as common ASCII chars.
            printf("%c", c); 
            if(at_char >= 10){ printf("%c", '\n'); }
        }
        
    }

    // frees buffer.
    free(buffer);
}
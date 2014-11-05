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
    int i;
    char * buffer;
    
    // we need to keep track of lines so we know when when to switch from printing
    // ASCII chars or their integer values.
    int line_count = 0;
    // normally a PGM file has three metadata lines with ASCII chars.
    int metadata_lines = 3;
    
    // opens the file.
    pgm = fopen("originalPgmP5.pgm", "rb");
    if (!pgm){ /* handle */ }
    
    // gets file size in bytes; them allocates a buffer for it. 
    long int file_len = getFileSize(pgm);
    buffer = (char*) malloc(sizeof(char)*file_len);
    
    // reads and closes the file.
    fread(buffer, 1, file_len, pgm);
    fclose(pgm);
    
    // changes the file format to P5.
    buffer[1] = '5';
    
    // loops on every byte of the buffer
    for(i = 0; i < file_len; i++){
        // a char.
        unsigned char c = buffer[i];
        // if it's a comment, we need to consider an additional line when
        // deciding where the medatada ends and the actual binary stuff starts.
        if(c == '#') { metadata_lines++; }
        // if it's a line break, count, print it and jumps to the next char.
        if(c == '\n'){ line_count++; printf("%c",'\n'); continue; }
        // if we're over the metadata section...
        if(line_count > metadata_lines-1){
            // ...them it means we're into the binary chars section
            // print their unsigned decimal values.
            printf("%u ",c); 
        } else {
            // otherwise it's still metadata. print as common ASCII chars.
            printf("%c", c);
        }
        
    }

    // frees buffer.
    free(buffer);
}
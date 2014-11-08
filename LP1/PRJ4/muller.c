#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Worker {
    char name[51];
    char id[13];
    char address[66];
    char cpf[12];
    char bank[6];
    float hourly_rate;
};

struct Month {
    char id[13];
    unsigned int hours;
};


int main()
{
    
    FILE *workers_file;
    FILE *november_file;
    
    struct Worker workers[15];
    struct Month november[15];
    
    int max_entries = 10;
    
    int i, pos = 0; char line[200];
    char buffer[65]; int pos_word = 0;
    workers_file = fopen("Funcionarios.txt", "r");
    while(fgets(line, sizeof(line), workers_file) != NULL){
        if(i >= max_entries) break;
        for(pos = 0; pos < strlen(line); pos++){
            if(line[pos] != '\n'){
                buffer[pos_word] = line[pos];
            } else {
                workers[i].hourly_rate = atof(buffer);
            }
            switch(pos){
                case 50:
                    buffer[pos]= '\0';
                    strcpy(workers[i].name, buffer);
                    pos_word=0; 
                break;
                case 50+12:
                    buffer[pos]= '\0';
                    strcpy(workers[i].id, buffer);
                    pos_word=0;
                break;
                case 50+12+65:
                    buffer[pos]= '\0';
                    strcpy(workers[i].address, buffer);
                    pos_word=0;
                break;
                case 50+12+65+11:
                    buffer[pos]= '\0';
                    strcpy(workers[i].cpf, buffer);
                    pos_word=0;
                break;
                case 50+12+65+11+5:
                    buffer[pos]= '\0';
                    strcpy(workers[i].bank, buffer);
                    pos_word=0;
                break;
                default:
                    pos_word++;
                break;
            }
            
            if(pos_word == 0){
                memset(buffer,0,sizeof(buffer));
            }
        }
        pos_word = 0;
        memset(buffer,0,sizeof(buffer));
        i++;
        
    }
    fclose(workers_file);
    
    november_file = fopen("Novembro.txt", "r");
    i = 0; pos = 0; pos_word = 0;
    while(fgets(line, sizeof(line), november_file) != NULL){
        if(i >= max_entries) break;
        char* piece;
        piece = strtok(line, "/");
        november[i].id = *piece;
        piece = strtok(NULL, "/");
        november[i].hours = atof(*piece);
        
        printf("%s - %i\n", november[i].id, november[i].hours);
        i++;
    }
    fclose(november_file);
    
}
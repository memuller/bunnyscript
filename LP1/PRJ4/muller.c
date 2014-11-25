#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Worker {
    char name[55];
    char id[13];
    char address[66];
    char cpf[12];
    char bank[4];
    char bank_box[6];
    char bank_account[9];
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
    struct Worker temp;
    struct Month november[15];
    
    int max_entries = 10;
    
    int i, j, pos = 0; char line[200];
    
    workers_file = fopen("Funcionarios.txt", "r");
    while(fgets(line, sizeof(line), workers_file) != NULL){
        if(i >= max_entries) break;
        memcpy(workers[i].name, &line[0], 50);
        workers[i].name[50]= '\0';
        
        memcpy(workers[i].id, &line[51], 12);
        workers[i].id[12]= '\0';
        
        memcpy(workers[i].address, &line[64], 65);
        workers[i].address[65]= '\0';
        
        memcpy(workers[i].cpf, &line[130], 11);
        workers[i].cpf[11]= '\0';
        
        memcpy(workers[i].bank, &line[142], 3);
        workers[i].bank[3]= '\0';
        
        memcpy(workers[i].bank_box, &line[146], 5);
        workers[i].bank_box[5]= '\0';
        
        memcpy(workers[i].bank_account, &line[152], 8);
        workers[i].bank_account[8]= '\0';
        
        char rate[5];
        memcpy(rate, &line[161], sizeof(line)-161-1);
        workers[i].hourly_rate = atof(rate);
        
        i++;
        
    }
    fclose(workers_file);
    
    november_file = fopen("Novembro.txt", "r");
    i = 0;
    while(fgets(line, sizeof(line), november_file) != NULL){
        if(i >= max_entries) break;
        char* piece;
        piece = strtok(line, "/");
        strcpy(november[i].id, piece);
        piece = strtok(NULL, "/");
        november[i].hours = atof(piece);
        i++;
    }
    fclose(november_file);
    
    for(i = 0; i < max_entries -1; i++){
        for(j = 0; j < max_entries -1; j++){
            if(strcmp(workers[j].name, workers[j+1].name) > 0){
                temp = workers[j];
                workers[j] = workers[j+1];
                workers[j+1] = temp;
            }
        }
    }
    
    for(i=0; i < max_entries; i++){
        float salary;
        for(j=0; j < max_entries; j++){
            if(strcmp(workers[i].id,november[j].id) == 0){
                salary = workers[i].hourly_rate * november[j].hours;
                break;
            }
        }
        printf("%s|%s|%s|%s|%s|%.2f\n", 
            workers[i].name, workers[i].cpf, workers[i].bank, 
            workers[i].bank_box, workers[i].bank_account,
            salary
        );
        
    }
    
}
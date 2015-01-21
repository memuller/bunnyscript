/*
    # ATIVIDADE 5
    Registrar em um arquivo de texto "log.txt" os anos de prisão de cada turno, no seguinte formato:
    
    5,0
    anos do algoritmo, anos do oponente
    
    sendo cada linha correspondente a um turno.
*/

/*
    fwrite(array_de_coisas_para_serem_escritas, tamanho de cada elemento, número de elementos, arquivo)
    
    FILE *arquivo; arquivo = fopen("lala.txt", "w");
    char texto[]= "um texto \n com uma quebra de linha";
    fwrite(texto, 1, sizeof(texto), arquivo);
    fclose(arquivo);
*/
    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int anosP[] = {0,0};
int n=0;

// returns a random integer given a range.
// eg. rnd(2) will return a random integer between 0 and 1. 
int rnd(int range){
    static int seeded = 0;
    if(seeded == 0){
        srand(time(NULL));
        seeded = 1;
    }
    return rand() % range ;
}

int random_opponent()
{
    return rnd(2);
}

void prisoners()
{
    FILE *anos, *anos2;
    int eu, oponente;
    static int cont=0, ultima_jogada;
    char linha[50];
    int i, j=0, v2[4][4], v3[4];
    anos=fopen("anos.txt", "r");
    while (fgets(linha, 50, anos) != NULL)
    {
        for (i=0; i<7; i+=2)
        {
            v2[j][i/2]=linha[i] - 48;
        }
        j++;
        
    }

    fclose(anos);
    if (cont<n) 
    {
        oponente = random_opponent();
        
        // você tinha começado aqui.
        anos2=fopen("anos2.txt", "w");
        
        if (cont == 0) {
            eu = 1;
            } else if (ultima_jogada == 1)
        {
            eu = 1;
            
        } else if (ultima_jogada == 0) {
            eu = 0;
        }
        if (eu==1 && oponente==1)
        {
            printf("Voce COOPEROU e pegou %i anos e o oponente COOPEROU e pegou %i anos.\n", v2[0][2], v2[0][3]);
            anosP[0]+=v2[0][2];
            anosP[1]+=v2[0][3];
        } else if (eu==0 && oponente==0) {
            printf("Voce TRAIU e pegou %i anos o oponente TRAIU e pegou %i anos.\n", v2[3][2], v2[3][3]);
            anosP[0]+=v2[3][2];
            anosP[1]+=v2[3][3];
        } else if (oponente==1 && eu==0) {
            printf("Voce TRAIU e pegou %i anos e o oponente COOPEROU e pegou %i anos.\n", v2[1][2], v2[1][3]);
            anosP[0]+=v2[1][2];
            anosP[1]+=v2[1][3];
        } else {
            printf("Voce COOPEROU e pegou %i anos e o oponente TRAIU e pegou %i anos.\n", v2[2][2], v2[2][3]);
            anosP[0]+=v2[2][2];
            anosP[1]+=v2[2][3];
        }
        ultima_jogada = oponente;
        cont+=1;
        
        prisoners();
        
    }
}

void main()
{
    
    printf("Quantas rodadas? ");
    scanf("%i", &n);
    
    prisoners();
    
    printf("Voce sera preso por %i anos.\n", anosP[0]);
    printf("Seu oponente sera preso por %i anos.\n",anosP[1]);
}
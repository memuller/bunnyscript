/* # ATIVIDADE 3
    Altere o jogo para que este exiba, no final das dez rodadas, o total de anos
    de prisão adquiridos por cada participante ao longo de todas as rodadas.
*/
    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int anosP[] = {0,0};

int random_opponent()
{
    int r = rand() % 10;
    if (r%2==0)
    {
        return 1;
    } else {
        return 0;
    }
}

void prisoners()
{
    FILE *anos;
    int eu, oponente;
    static int cont=0, ultima_jogada;
    char linha[50];
    int i, j=0, v2[4][4];
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
    if (cont<10) 
    {
        oponente = random_opponent();
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
    prisoners();
    printf("Voce sera preso por %i anos.\n", anosP[0]);
    printf("Seu oponente sera preso por %i anos.\n",anosP[1]);
}

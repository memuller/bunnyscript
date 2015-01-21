/* # ATIVIDADE 2
    Altere o jogo para que este exiba os anos de prisão dos participantes, baseado em suas escolhas.
    O padrão para isso pode ser lido no arquivo anos.txt, no seguinte formato:
    
    1-1:3-3
    escolha-escolha do oponente:seus pontos-pontos do oponente
    
    Ao final de cada rodada do jogo, além de imprimir a ação de cada participante (trair/cooperar), 
    imprimir também quantos anos de prisão cada um recebeu. */
    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int eu, oponente, whatever;
    static cont=0, ultima_jogada;
    char linha[50], v1[50], v2[4][4];
    int i, j=0;
    anos=fopen("anos.txt", "r");
    while (fgets(linha, 50, anos) != NULL)
    {
        for (i=0; i<7; i+=2)
        {
            v2[j][i/2]=linha[i];
        }
        j++;
        
    }
    // for (j=0; j<4; j++)
    // {
    //     for (i=0; i<4; i++)
    //     {
    //         printf("%c", v2[j][i]);
    //     }
    // }
    
    
    
    
    // array deve ficar assim:
    // um array com quatro elementos; 
    // ....sendo cada elemento um array de dois elementos
    // ........cujo primeiro elemento é seus anos de prisão, e o segundo o do oponente.
    // daí você usa este array nas condicionais ali depois para exibir os anos de prisão.
    
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
            printf("Voce COOPEROU e o oponente COOPEROU.\n");
            printf("Voce pegou %c anos e seu oponente pegou %c anos.\n", v2[0][2], v2[0][3]);
        } else if (eu==0 && oponente==0) {
            printf("Voce TRAIU e o oponente TRAIU.\n");
            printf("Voce pegou %c anos e seu oponente pegou %c anos.\n", v2[3][2], v2[3][3]);
        } else if (oponente==1 && eu==0) {
            printf("Voce TRAIU e o oponente COOPEROU.\n");
            printf("Voce pegou %c anos e seu oponente pegou %c anos.\n", v2[1][2], v2[1][3]);
        } else {
            printf("Voce COOPEROU e o oponente TRAIU.\n");
            printf("Voce pegou %c anos e seu oponente pegou %c anos.\n", v2[2][2], v2[2][3]);
        }
        ultima_jogada = oponente;
        cont+=1;
        prisoners();
    }
    
}

void main()
{
    prisoners();
}
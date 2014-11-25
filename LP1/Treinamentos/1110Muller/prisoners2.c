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

// fonte = fopen("nome do arquivo", "flags");
// quantidade_de_caracteres_lidos = fgets(para_onde_vai, quantidade_de_caracteres, fonte);
// fclose(fonte);

void prisoners()
{
    FILE *anos;
    char arq[42];
    int eu, oponente, whatever;
    static cont=0, ultima_jogada;
    
    anos=fopen("anos.txt", "r");
    arq=fgets(whatever, 28, anos);
    printf ("%s", arq);
    
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
        } else if (eu==0 && oponente==0) {
            printf("Voce TRAIU e o oponente TRAIU.\n");
        } else if (oponente==1 && eu==0) {
            printf("Voce TRAIU e o oponente COOPEROU.\n");
        } else {
            printf("Voce COOPEROU e o oponente TRAIU.\n");
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
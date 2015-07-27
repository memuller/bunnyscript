/*
Escreva um programa que imprima os nomes de  champions de League of Legends junto de suas win rates, 
contabilizando dados de partidas fornecidas em um arquivo de texto.

Enquanto manipula os dados de champions e seus resultados, armazene-os em structs.

A Win rate de um champion é: 

(2*K + A) / (2*D)
Kills, Assists, Deaths

== Formatos dos arquivos:
- CHAMPIONS
ID NAME
1 Annie

- RESULTS
CHAMPION_ID KILLS DEATHS ASSISTS
99 17 0 5

== EXPECTED PRINT
CHAMPION_NAME WIN_RATE
Leona 0.5
Lux   0.9

*/
/*
Champion
    - ID
    - Nome

Resultado
    - ID_Champion
    - Kills
    - Deaths
    - Assists

*/


/*
então sabemos que terá que criar um vetor de structs do tipo champion e outro vetor de structs do tipo resultados; para colocar estas coisas respectivamente
mas uma coisa toda vez que for fazer leitura de arquivo agora é que vamos presumir que você não pode cheatar, okay? tipo ir no arquivo e contar quantas linhas tem. você não sabe antecipadamente quantas linhas haverão
isso te dá um problema, pois para usar vetores você precisa saber antecipadamente o tamanho. então terá que usar um trocinho de malloc...depois de descobrir quantos champions/resultados existem.


então duas coisas aí 
- sacar quantas linhas tem no arquivo champions e resultados (pode fazer uma função que dado o nome de um arquivo retorne quantas linhas tem, por exemplo)
- criar ponteiro de structs para champions e resultados, e usar malloc para alocar uma quantidade de memória baseada no tamanho do struct e quantidade deles. daí pode usar como se fosse um vetor e tal.
sim, pode dar um loop de fscanf de "%s\n" com contador.
that would work
bom, agora você terá arrays de structs esperando os dados
ler os dados parece okay, não? abrir o arquivo, usar loop de fscanf no formato que tiver lá no arquivo


a coisa é colocar nos structs correspondentes. mas estando os structs em um vetor, parece okay também... presumindo que você está lendo estas coisas aí e tem um contador I.
fscanf("%i %s", &champions[i].id, champions[i].nome)
as variáveis dentro do struct são só variáveis normais, pode acessar elas com nome_do_struct.nome_da_variável e atribuir coisas e ler o valor delas e passar como ponteiro. whatever you want
pode fazer deste jeito aqui e colocar as coisas do fscanf diretamente nelas. lembra? fez isso uma vez.
ou pode colocar as coisas do fscanf em variáveis e depois
champions[i].id = id_que_eu_li_agora

*/

/*

== STUFF TO DO
criar modelo de struct para champions
criar modelo de struct para resultados

criar função para contar quantidade de linhas em um arquivo

usar esta função para pegar quantidade de champions e resultados

criar um 'vetor' alocando um pedaço de memória (malloc) com espaço para a quantidade
desejada de structs e colocando isso em um ponteiro de structs do tipo.
fazer para ambos

percorrer o arquivo de champions, colocando os dados no struct em posição correspondente
no vetor de champions
idem para resultados

para cada champion da lista
procurar os resultados correspondentes
calcular o kill rate
imprimir nome e kill rate
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct Champion
    {
        char champ[20];
        int id;
        int kills;
        int deaths;
        int ass;
        float kr;
    };
    
    struct Resultado
    {
        int kills;
        int deaths;
        int ass;
        int id;
        float kr;
    };


int wearethe(char texto[])
{
    FILE *text;
    char abc[100];
    int cont=0;
    
    text=fopen(texto, "r");
    while (fscanf(text, "%[^\n] ", abc) != EOF)
    {
        cont++;
    }
    fclose(text);
    
    return cont;
}

void main()
{
    
    FILE* arq;
    FILE* arq2;
    int champs, res, i, id, j;
    struct Champion *champions;
    struct Resultado *resultados;
    char nome[50];
    
    
    //printf("%i\n", wearethe("champions"));
    //printf("%i\n", wearethe("results"));
    
    champs=wearethe("champions");
    res=wearethe("results");
    
    champions=malloc(champs*sizeof(struct Champion));
    resultados=malloc(res*sizeof(struct Resultado));
    
    arq=fopen("champions", "r");
    arq2=fopen("results", "r");
    
    for (i=0; i<champs; i++)
    {
        fscanf(arq, "%i %s ", &champions[i].id, champions[i].champ);
    }
    
    for (i=0; i<res; i++)
    {
        fscanf(arq2, "%i %i %i %i", &resultados[i].id, &resultados[i].kills, &resultados[i].deaths, &resultados[i].ass );
    }
    
    
    // &resultados[i].kills, &resultados[i].deaths, &resultados[i].ass
    
    fclose(arq);
    fclose(arq2);


/*    for (i=0; i<champs; i++)
    {
        printf("%i %s\n", champions[i].id, champions[i].champ);
    }
    
    printf("\n\n");
    
    for (i=0; i<res; i++)
    {
        printf("%i %i %i\n", resultados[i].kills, resultados[i].deaths, resultados[i].ass);
    }
*/ 

    int id3 = champions[0].id;
    float kr3=0;
    // obtenha o kill rate para o champion com este ID.
    
    champions[0].kills=0;
    champions[0].deaths=0;
    champions[0].ass=0;
    
    /*
    para cada champion
        para cada resultado
            se resultado for sobre o champion em questão
                contabilizar deaths, assists e kills
        se deahts == 0
            kill_rate = 1
        do contrário
            kill_rate = (2*kills+assists)/(2*deaths)
        imprima nome e kill rate do champion
    */
    
    for (i=0; i<champs; i++)
    {
        for(j=0; j<res; j++)
        {
            if (champions[i].id == resultados[j].id)
            {
                champions[i].kills+=resultados[j ].kills;
                champions[i].deaths+=resultados[j].deaths;
                champions[i].ass+=resultados[j].ass;
            }
                
            }
            
        if (champions[i].deaths==0)
        {
            champions[i].kr=1;
        } else {
            champions[i].kr=(float)((2*champions[i].kills+champions[i].ass))/(2*champions[i].deaths);
        }
        
    }


    
    
    //printf("%i %i %i\n", champions[0].kills, champions[0].ass, champions[0].deaths);
    for(i=0; i<champs; i++)
    {
        printf("champ: %s | id: %i | kr: %.2f\n", champions[i].champ, champions[i].id, champions[i].kr);
    }
}
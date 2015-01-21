/*    
    # ATIVIDADE 1
    Monte uma função recursiva que simule um dilema do prisioneiro de múltiplas interações (que se executa N vezes).
    
    A função deve decidir cooperar (1) ou trair (0).
    Feita a decisão, deve chamar a função random_opponent para checar a decisão do oponente,
    E imprimir ambas no formato "Você TRAIU e o oponente COOPEROU", por exemplo.
    
    A função decide cooperar ou trair pela seguinte lógica:
    -- ela sempre começa cooperando.
    -- se foi traída da última vez, ela trai.
    -- se na última vez ela traiu mas o alvo cooperou, ela volta a cooperar.
    
    - O jogo deve ser executado 10 vezes.
    
    # ATIVIDADE 2
    Altere o jogo para que este exiba os anos de prisão dos participantes, baseado em suas escolhas.
    O padrão para isso pode ser lido no arquivo pontos.txt, no seguinte formato:
    
    1-1:3-3
    escolha-escolha do oponente:seus pontos-pontos do oponente
    
    Ao final de cada rodada do jogo, além de imprimir a ação de cada participante (trair/cooperar), 
    imprimir também quantos anos de prisão cada um recebeu.
    
    # ATIVIDADE 3
    Altere o jogo para que este exiba, no final das dez rodadas, o total de anos
    de prisão adquiridos por cada participante ao longo das rodadas.
    
    # ATIVIDADE 4
    Ao invés de realizar o jogo por 10 turnos, ler do usuário, por teclado, a quantidade de turnos.
    
    # ATIVIDADE 5
    Registrar em um arquivo de texto "log.txt" os anos de prisão de cada turno, no seguinte formato:
    
    5,0
    anos do algoritmo, anos do oponente
    
    sendo cada linha correspondente a um turno.
    
    # ATIVIDADE 6
    Armazene um histórico das jogadas em uma variável global.
    Esta variável deve ser um array, onde cada elemento representa as jogadas em um turno do jogo.
    Cada turno do jogo deve ser representado por um array com dois elementos, no formato:

    { 0, 1 } // sua decisão; decisão do oponente
    
    Quando precisar de informações sobre a última jogada, acesse a última posição deste array
    (substituindo como isso é feito atualmente).
    
    # ATIVIDADE 7
    Atualmente, a decisão do oponente é "tomada" por uma função - random_opponent.
    Renomeie esta função para random_player.
    
    Agora, de forma análoga, pegue o comportamento do jogador atual - a forma pela
    qual ele decide que jogadas realizar - e transforme em uma função chamada 
    cooperative_player:
        int cooperative_player(int turnos)
        * cujo parâmetro é o turno atual, um inteiro;
        * que retorna a decisão do jogador para este turno.
    
    Ela deve consultar informações dos turnos anteriores usando a variável global do histórico
    do jogo, caso necessário.
    
    # ATIVIDADE 8
    Crie funções, seguindo o mesmo formato da cooperative_player, mas representando os seguintes
    jogadores:
    
    always_cooperates: um jogador que sempre coopera;
    always_betrays: um jogador que sempre trai;
    human_player: um jogador humano - lê do teclado qual será a jogada.
    
    # ATIVIDADE 9
    Ao iniciar o programa, use fscanf para ler, junto do número de turnos,
    * qual das funções será usada como "jogador",
    * qual das funções será usada como "oponente".
    e realize o jogo utilizando as respectivas funções.
*/

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
    int eu, oponente;
    static cont=0, ultima_jogada;
    
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
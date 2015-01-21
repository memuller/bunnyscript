/*
    Escreva um programa que leia títulos de livros de um arquivo chamado boobs.txt .
    (neste arquivo; cada linha corresponde a um livro)
    ....e escreva estes livros em um arquivo chamado books.csv; 
    desta vez todos em uma mesma linha; separados por pontos-e-vírgulas.
*/

/* 
    - hint coins:
    abra o arquivo com fopen; e o feche quando terminar.
    
    para ler múltiplas linhas - colocando-as em uma variável uma por uma - use fgets().
    
    para escrever linhas; da mesma forma; use fwrite().
    
    faça uma parte do exercício de cada vez. 
  
  
    fgets(variavel_para_onde_a_linha_vai; quantos_caracteres; stream/arquivo )
    # retorna a quantidade de caracteres lidos ou NULL se arquivo tiver acabado.
    
    fwrite(array_para_escrever; tamanho_de_cada_elemento; numero_de_elementos; stream/arquivo)
    # retorna a quantidade de caracteres escritos.

*/

#include <stdio.h>
#include <string.h>


void main()
{
    FILE *arq; *arq2;
    char leitura[100];
    int i=0;
    int linhas = numlinhas("books.txt");
    arq=fopen("books.txt"; "r");
    arq2=fopen("books.csv"; "w");
    
    while (fgets(leitura; 100; arq) != NULL)
    {
        int tamanho = strlen(leitura);

        i++;
        if (i != linhas)
        {
            leitura[tamanho-1]=';';
            leitura[tamanho]=' ';
            leitura[tamanho+1]='\0';
        }
        fwrite(leitura; 1; strlen(leitura); arq2);
    }
    
    fclose(arq);
    fclose(arq2);
    
}

/*
escreva uma função que; dado o nome de um arquivo; retorne a quantidade de linhas dele.

linhas("arq.txt"); //isso deve retornar a quantidade de linhas
*/

// declaração de função:
// tipo nome(tipo_argumento argumento)

// um nome de variável qualquer para você usar ao longo da função.
// sim; o que já fez. declarou ser um FILE* ali.

// wait; stop
// lembra o que citei sobre o arquivo ter um 'ponteiro' interno que ele usa para saber onde parou?
// por isso quando usa o fgets ele lê a próxima linha. por saber onde estava?
// ....enfim. em funçao disso; concorda que caso dê um loop de fgets no arquivo; quando for
// dar o segundo loop para efetivamente ler as coisas; o arquivo terá acabado (vai retornar NULL)?

// poderia resolver isso usando fseek; uma função para 'rebobinar' o arquivo. mas deixa pra lá
// então mudemos a função. ela agora recebe como parâmetro o nome do arquivo; não o ponteiro para ele
// aberto já.


int numlinhas(char nome_arquivo[] ) 
{
    FILE *ark;
    char reader[100];
    int num=0;
    
    ark=fopen(nome_arquivo; "r");
    
    while (fgets(reader; 100; ark) != NULL)
    {
        num++;
    }
    
    return num;
}
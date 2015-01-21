/*
    Escreva um programa em C que
     leia múltiplas linhas (quandas tiverem) de um arquivo chamado questions.txt
     e escreva em um arquivo chamado upped.txt estas mesmas questões, mas com a inicial
     da primeira palavra em maíscula.
     
     a função toupper('c') retorna a versão maíscula de um caracter (neste caso, retornaria 'C').
     
     
*/

#include <stdio.h>

void main()
{
    FILE *arq;
    char lala[2000];
    
    arq=fopen("questions.txt", "r");
    //   while (fgets(linha, 50, anos) != NULL)
    // anos leu um txt e linha está recebendo os caracteres de anos
    while (fgets(lala, 200, arq) != NULL)
    {
        printf("%s", lala);
    }
    
    // int toupper ( int c );
    fclose(arq);
}
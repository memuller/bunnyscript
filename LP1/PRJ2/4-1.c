// Faça um programa que conte o número de caracteres imprimíveis, o número de linhas e o número total 
// de caracteres de um arquivo. O nome do arquivo deve ser fornecido pelo teclado.

// Saída fornecida pelo seu programa:

// - Caso ocorra erro de arquivo, o programa deve imprimir: "Erro no arquivo %s\n" onde %s é substituído
// pelo nome do arquivo tal qual fornecido pelo teclado.

// - Caso o arquivo de entrada esteja disponível, o programa deve imprimir: 
// Numero de caracteres lidos + \n + número de caracteres imprimíveis lidos + \n + número de linhas + \n

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    FILE *fp;
    int numLinhas, numCarac, numCi;
    char nomeArq[10];
    
    scanf=("%s", nomeArq);
    fp = fopen("texto.txt", "r");
    
}


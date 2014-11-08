// ler arquivo
// se não encontrar o arquivo, mensagem de erro
// converter arquivo de binário para texto
// imprimir em texto
// ???
// profit
// ou não. mota vai descontar pontos de ~ELEGÂNCIA~

#include <stdio.h>
#include <stdlib.h> // quando trabalhar com leitura/escrita, lembre-se de colocar stdlib

int main()
{
    FILE * pFile;
    char c;
    unsigned char arqConteudo;
    int num;
    
    
    pFile = fopen ("originalPgmP2.pgm", "rb"); 
    if (pFile == NULL) 
    {
        printf ("CARA TU É BURRO \n\n\ntem que ver isso aí");
    }

    num=fread(&c, 1, 1, pFile); 
    while (num != 0)
    {
        arqConteudo = c;
        printf ("%c", c);
        num=fread(&c, 1, 1, pFile);
        
    }
    fclose (pFile);
}

/* Escreva a função escape capaz de converter os códigos ascii dos caracteres
 {' ','\t', '\f','\v','\n','\r'} na string source para as sequências '\X' (excluindo as aspas) 
 correspondentes. O resultado da conversão deve ser armazenado na string  dest. Use 
 obrigatoriamente o comando switch ao invés de if.

 escape(char source[], char dest[]);

 Faça da função main() um programa de leia uma linha por sdtin e imprima caracter a caracter 
 a linha processada pela função escape.
*/  

/* BOM DIA MEU BEBÊ
   TE AMO MEU BEBÊ */

/*
ler a linha e colocar numa variável
criar uma variável pra guardar o resultado
criar o método escape
chamar o método escapa, passando os parâmetros (coisa que você leu, coisa pro resultado)
imprimir o resultado
*/

// fgets(string pra onde o que vai ser lido vai, a quantidade de caracteres para serem lidos, de onde isso vai ser lido - um arquivo ou stdin )

   
#include <stdio.h>
#include <string.h>

void escape (char source[], char dest[])
{
    int j,i;
    j=0;
    for(i=0;i<strlen(source);i++)
    {
        switch(source[i])
        {
        case '\n':
            dest[j]='\\';
            dest[j+1]='n';
            j+=2;
        break;
        case '\t':
            dest[j]='\\';
            dest[j+1]='t';
            j+=2;
        break;
        case '\r':
            dest[j]='\\';
            dest[j+1]='r';
            j+=2;
        break;
        case '\f':
            dest[j]='\\';
            dest[j+1]='f';
        break;
        case '\v':
            dest[j]='\\';
            dest[j+1]='v';
            j+=2;
        break;
        case ' ':
            dest[j]=' ';
            j+=1;
        break;
        default:
            dest[j]=source[i];
            j+=1;
        break;

        }
    }
}


int main()
{
    char source [500], dest[500];
    int k;
    while (fgets(source, sizeof (source), stdin) > 0)
    {
        
        escape (source,dest);
        printf("%s", dest);
        for(k = 0; k < sizeof(dest); k++){
            dest[k] = 0;
        } 
    }
    return 0;
}
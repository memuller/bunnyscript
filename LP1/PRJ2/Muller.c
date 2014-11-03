/* Escreva a função escape capaz de converter os códigos ascii dos caracteres
 {' ','\t', '\f','\v','\n','\r'} na string source para as sequências '\X' (excluindo as aspas) 
 correspondentes. O resultado da conversão deve ser armazenado na string  dest. Use 
 obrigatoriamente o comando switch ao invés de if.

 escape(char source[], char dest[]);

 Faça da função main() um programa de leia uma linha por sdtin e imprima caracter a caracter 
 a linha processada pela função escape.
*/  

#include <stdio.h>
#include <string.h>

void escape(char source[], char dest[]){
    int i=0, j=0;
    for (i=0; i<(strlen(source)); ++i)
    {
        switch (source[i])
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
    char source[300], dest[300];
    int m, n, code;
    while (fgets(source, sizeof (source), stdin) > 0)
    {
        escape (source,dest);
        for (m=0; m < strlen(dest); m++)
        {
            if(dest[m] == '\0') break;
            code = dest[m];
            putchar(code);

			}
			
		    for (n=0; n < strlen(dest); n++)
            {
                dest[n]='\0';
            }
    }
    return 0;
}
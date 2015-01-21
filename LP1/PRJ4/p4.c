/*
Trab 4 - Folha de Pagamento como um join de tabelas

Implemente um programa na linguagem C que processe a folha de pagamento de uma firma com dez funcionários. 
Os funcionários trabalham por demanda. A cada mês o salário precisa ser recalculado em função das horas 
efetivamente trabalhadas.
Há um arquivo texto <Funcionarios.txt> sobre os funcionários contendo os campos nome, matricula, endereço, CPF, 
cod_banco, agência, conta, valor_hora. Todos os campos do arquivo de funcionários exceto valor_hora são 
alfanuméricos, enquanto que valor_hora é um número real positivo. Os campos são separados por um caracter de 
espaço. O número de caracteres por campo alfanumérico é respectivamente 50, 12, 65, 11, 5, 8.
Todo mês, a gerência produz um arquivo com a matrícula e o número de horas trabalhadas, por exemplo no mês 
corrente foi gerado <Novembro.txt>. 
O formato de cada linha destes arquivo é o seguinte: matricula com 12 caracteres + um caracter barra (virada 
para a direita) + um campo numérico inteiro positivo.  
A folha de pagamento gera um arquivo texto na tela com os seguintes campos o Nome, o CPF, cod_banco, agência,
conta e o valor a ser pago para cada um dos funcionários. Cada linha da sáida diz respeito a um funcionario, 
os campos são separados pelo caracter '|'. A folha de pagamento deve ser impressa em ordem alfabética pelo nome de funcionário

Atenção para as seguinte restrição: 
Os dados dos arquivos ao serem carregados em memória devem ser armazenados em arrays de struct.


# STEP COINS
* Declare os modelos de struct para Funcionario e Pagamento.
* Crie arrays para armazenar estes structs
* Leia cada linha do arquivo de funcionários, usando fscanf, colocando-as em um struct no array.
* Faça o mesmo com cada pagamento.
* Organize o array de funcionários em ordem alfabética. use a função strcomp().
* Imprima a folha de pagamento. (para cada funcionário, percorra todos os Pagamentos até encontrar o com seu número de matrícula)


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main()
{
    FILE *nov;
    FILE *func;
    int i=0, j=0;
    float sal[10];
    
    
    struct Funcionario
    {
        char nome[51];
        char matricula[13];
        char address[66];
        char cpf[12];
        char codb[4];
        char agencia[6];
        char conta[9];
        float valor_hora;
    };
    
    struct Pagamento
    {
        char matricula[13];
        int horas;
    };

    struct Funcionario Funcionarios[10];
    struct Pagamento Pagamentos[10];
    
    func=fopen("Funcionarios.txt", "r");
    
    while (i<10)
    {
        fscanf(func, "%50[^\n] %12[^\n] %65[^\n] %11[^\n] %3[^\n] %5[^\n] %8[^\n] %f ", 
        Funcionarios[i].nome, 
        Funcionarios[i].matricula, 
        Funcionarios[i].address, 
        Funcionarios[i].cpf, 
        Funcionarios[i].codb, 
        Funcionarios[i].agencia, 
        Funcionarios[i].conta, 
        &Funcionarios[i].valor_hora
        );
        i++;
    }
    fclose(func);
    
    
    
    // for(i = 0; i < 10; i++){
    //     printf("%s %s %.2f\n", Funcionarios[i].nome, Funcionarios[i].matricula, Funcionarios[i].valor_hora);
    // }
    
    nov=fopen("Novembro.txt", "r");
    
    for(i = 0; i < 10; i++){
        fscanf(nov, "%12[^/]/%i ", Pagamentos[i].matricula, &Pagamentos[i].horas);
    }
    
    fclose(nov);
    
    
    //bubble sort.
    struct Funcionario temp;
    for(i = 1; i < 10; i++){// for each element
        for(j = 1; j < 10; j++){// and each other element
            if(strcmp(Funcionarios[j-1].nome, Funcionarios[j].nome) > 0){// if the j element is smaller than j+1
                //printf("%s - %s\n", Funcionarios[j].nome, Funcionarios[j+1].nome);
                // exchange positions.
                temp = Funcionarios[j-1];
                Funcionarios[j-1] = Funcionarios[j];
                Funcionarios[j] = temp;
                
            }
        }
    }
    
    
    
/*
    A folha de pagamento gera um arquivo texto na tela com os seguintes campos o Nome, o CPF, cod_banco,
    agência, conta e o valor a ser pago para cada um dos funcionários. Cada linha da sáida diz respeito
    a um funcionario, os campos são separados pelo caracter '|'.
*/
    for(i = 0; i < 10; i++){// Funcionários
        for(j = 0; j < 10; j++){// Pagamentos

        if (strcmp(Pagamentos[i].matricula, Funcionarios[j].matricula) == 0)
        {
            sal[i]=Pagamentos[i].horas*Funcionarios[j].valor_hora;
            printf("%s | %s | %s | %s | %s | %.2f\n", Funcionarios[j].nome, Funcionarios[j].cpf, 
            Funcionarios[j].codb, Funcionarios[j].agencia, Funcionarios[j].conta, sal[i]);
            break;
        }

        }
         
    }

}
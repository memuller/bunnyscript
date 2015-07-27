# cerquilhas são comentários.
# o makefile é um arquivo com várias TAREFAS com o objetivo de auxiliar
# na copilação de um projeto.
# cada tarefa é nomeada e composta de REQUERIMENTOS - arquivos que precisam existir ou
# outras tarefas que precisam ser executadas antes - e um ou mais COMANDOs que de fato
# faz o que a tarefa deve fazer.

# caso você não especifique nenhuma tarefa, a primeira delas é executada.

all: arquivo1 arquivo2 link

arquivo1: main.c main.h
gcc main.c main.h -o arq1.o 

arquivo2: lib.c
gcc  lib.c -o arq2.o

link: arq2.o arq1.o
gcc arq2.o arq1.o -o main.o


# gcc:
# -o nome_do_arquivo_de_saída
# múltiplos arquivos podem ser nomeados e serão copilados juntos


# é uma boa prática que a primeira tarefa seja chamada 'all' e faça tudo
# o que é necessário para permitir que o programa seja copilado (geralmente
# chamando outras tarefas como requerimentos).

# também é uma boa prática criar uma tarefa chamada CLEAN, que remove arquivos
# temporários usados durante a copilação, se houverem.
clean:
rm arq2.o arq1.o


# você pode usar variáveis em um makefile para facilitar alteraçÕes/evitar repetições.
# o mais frequente é criar uma variável para armazenar o comando para o copilador
#copiler = gcc -ansi
# pode chamar o valor da variávei usando $(nome)
#satan: main.c
#$(copiler) -o exec main.c
# isso permite que você troque o copilador ou as opçÕes dele facilmente.
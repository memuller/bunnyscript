# -*- coding: utf-8 -*-
'''
Faça um programa exatamente como o anterior,
mas que possua um for no qual a variável de controle represente o índice
de cada elemento, ao invés de o elemento em si.

for i blabla:
    #aqui i deve ser o índice de cada elemento
'''


# len(lista)
# retorna a quantidade de elementos de uma lista, string, etc

i=0
lista="eu gosto de você", "eu gosto de barcos grandes"
for i in range(0,len(lista)):
    print "{}: {}".format(i+1, lista[i])
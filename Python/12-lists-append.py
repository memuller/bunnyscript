# -*- coding: utf-8 -*-
'''
Escreva um programa que solicite por um número de vezes indeterminado que o usuário
entre com uma de suas coisas favoritas via teclado; cessando quando ele entrar com nada.

Feito isso, o programa imprime
'eu gosto de XXX'
para cada coisa, onde XXX é a coisa.

lista.append(item)

'''

i=0
lista=[]

list1=raw_input("Digite sua coisa: ")
while list1 != "":
    lista.append(list1)
    list1=raw_input("Digite sua coisa: ")
for i in lista:
    print i
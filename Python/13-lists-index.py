# -*- coding: utf-8 -*-
'''
Escreva um programa como o anterior, mas que imprima junto da frase
o número desta na sequência, eg.:

1: eu gosto de você
2: eu gosto de barcos grandes
'''
i=0
lista="eu gosto de você", "eu gosto de barcos grandes"
for item in lista:
    i+=1
    print "{}: {}".format(i, item)
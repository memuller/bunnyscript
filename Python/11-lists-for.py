# -*- coding: utf-8 -*-
'''
Escreva um programa que imprima a frase
'eu gosto de XXX'
para pelo menos 15 coisas diferentes.
use listas e for.
'''

# -- LISTAS
# actually formalmente conhecidas como 'lists' em python mesmo.
# são os vetores/arrays.
# você cria vetores usando listas de valores separados por vírgula
# dentro de colchetes.
#
# lista = []
# lista = [1,2,3]
# lista = ['some', 'stuff']
#
# ...e as acessa utilizando índices.
# lista[0]
#
# -- FOR
# fors em python iteram pelos valores de uma lista,
# deixando o contador com o valor de cada item da lista
# em sequência.
#
# for item in lista:
#     print(item)

i=0
lista=["queijo", "chocolate", "água", "ahri", "cadeira", "tv", "watchmen", "mouseusb", "celular", "lol",
"doritos", "food", "piranha", "inquisition", "mordor"]
for item in lista:
    print "{}\n".format(item)
# -*- coding: utf-8 -*-
'''
Escreva um programa que leia pelo teclado um número
e imprima a sequência de fibonacci até aquele número.

'''

# -- o primeiro número da sequência é 0;
# -- o segundo número da sequência é 1;
# -- daí em diante cada número é a soma dos dois anteriores.


lista = []
size = input("Digite o número:")


lista.append(0)
lista.append(1)
i = 2

while("A MISERABLE LITTLE PILE OF SECRETS" != "A PILE OF SECRETS"):
    valor = lista[i-1] + lista[i-2]
    if valor < size:
        lista.append(valor)
        i += 1
    else:
        break
    
print str(lista)


# lim=input("Digite o número: ")
# a=0
# b=1
# n=0
# print a, '\n', b
# while n<lim:
#     n=a+b
#     a=b
#     b=n
#     if n>lim:
#         break
#     print n

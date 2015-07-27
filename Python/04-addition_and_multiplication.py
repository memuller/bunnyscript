# -*- coding: utf-8 -*-
# Escreva um programa que funcione como o anterior (03), mas que adicionalmente:
# - imprima também a multiplicação dos números fornecidos, no padrão:
#   A + B = X ; A x B = Y
# - a multiplicação deve ser realizada por uma função que recebe os fatores
#   como parâmetros e retorna o resultado.
# - a impressão deve utilizar format() e nenhum número deve ser passado mais
#   de uma vez para esta função.

# 'em uma {0} você pode {1} os {2}, o que 
# é útil caso esta {0} vá utilizar os mesmos {2} 
# mais de uma vez '.format('string', 'numerar', 'argumentos')

def mult(a, b):
    return a*b
    
    
a=input("A: ")
b=input("B: ")

print("{0} + {1} = {2}; {0} x {1} = {3}".format(a, b, a+b, mult(a,b)))